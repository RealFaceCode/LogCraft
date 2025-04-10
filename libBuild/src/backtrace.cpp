#include "logcraft/backtrace.hpp"

#include <vector>
#include <string>
#include <stacktrace>
#include <filesystem>

namespace lc::internal
{
    LC_API Backtrace GetBacktrace()
    {
        auto stacktrace = std::stacktrace::current();

        std::size_t size = stacktrace.size();

        Backtrace backtrace;
        backtrace.m_sFunctionNames.reserve(size);
        backtrace.m_sFileNames.reserve(size);
        backtrace.m_nLineNumbers.reserve(size);

        for (auto frame : stacktrace)
        {
            backtrace.m_sFunctionNames.emplace_back(frame.description());
            backtrace.m_sFileNames.emplace_back(frame.source_file());
            backtrace.m_nLineNumbers.emplace_back(frame.source_line());
        }

        return backtrace;
    }

    LC_API void TrimFunctionName(Backtrace& bt)
    {
        bool last = false;
        for (size_t i = 0; i < bt.m_sFunctionNames.size(); ++i)
        {
            auto pos = bt.m_sFunctionNames[i].find('!');
            if (pos != std::string::npos)
                bt.m_sFunctionNames[i].erase(0, pos + 1);
            pos = bt.m_sFunctionNames[i].find('+');
            if (pos != std::string::npos)
                bt.m_sFunctionNames[i].erase(pos, bt.m_sFunctionNames[i].size() - pos);
        }
    }

    LC_API void TrimFile(Backtrace& bt)
    {
        for(auto& file : bt.m_sFileNames)
        {
            std::filesystem::path path = file;
            file = path.filename().string();
        }
    }

    LC_API void DelAfterMain(Backtrace& bt)
    {
        bool last = false;
        for (size_t i = 0; i < bt.m_sFunctionNames.size(); ++i)
        {
            if (last)
            {
                bt.m_sFileNames.erase(bt.m_sFileNames.begin() + i);
                bt.m_sFunctionNames.erase(bt.m_sFunctionNames.begin() + i);
                bt.m_nLineNumbers.erase(bt.m_nLineNumbers.begin() + i);
                --i;
            }

            if (bt.m_sFunctionNames[i] == "main")
                last = true;
        }

        bt.m_sFileNames.erase(bt.m_sFileNames.begin(), bt.m_sFileNames.begin() + 3);
        bt.m_sFunctionNames.erase(bt.m_sFunctionNames.begin(), bt.m_sFunctionNames.begin() + 3);
        bt.m_nLineNumbers.erase(bt.m_nLineNumbers.begin(), bt.m_nLineNumbers.begin() + 3);
    }

    void BacktracePrint(const Backtrace& bt) {}
}