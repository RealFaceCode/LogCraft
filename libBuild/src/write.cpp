#include "logcraft/write.hpp"

#include <sstream>
#include <eutil/time/Time.hpp>
#include <print>

#include "logcraft/logConfig.hpp"
#include "logcraft/logcraftConfig.hpp"
#include "logcraft/backtrace.hpp"

namespace lc::internal
{

#pragma region FillBuffer

    void FillTimeToBuffer(std::stringbuf& buffer, const LogConfig& config, bool fileMode)
    {
        if(!config.m_bLogTime)
            return;

        if(!config.m_sBTime.empty())
            buffer.sputn(config.m_sBTime.data(), config.m_sBTime.size());

        if(config.m_bColorTime && !fileMode)
            buffer.sputn(config.m_sColorTime.data(), config.m_sColorTime.size());

        auto time = util::getCurrentTime(config.m_sLogTimeFormat);
        buffer.sputn(time.data(), time.size());

        if(config.m_bColorTime && !fileMode)
        {
            auto color = internal::GetResetColor();
            buffer.sputn(color.data(), color.size());
        }

        if(!config.m_sATime.empty())
            buffer.sputn(config.m_sATime.data(), config.m_sATime.size());
    }

    void FillDateToBuffer(std::stringbuf& buffer, const LogConfig& config, bool fileMode)
    {
        if(!config.m_bLogDate)
            return;

        if(!config.m_sBDate.empty())
            buffer.sputn(config.m_sBDate.data(), config.m_sBDate.size());

        if(config.m_bColorDate && !fileMode)
            buffer.sputn(config.m_sColorDate.data(), config.m_sColorDate.size());

        auto date = util::getCurrentTime(config.m_sLogDateFormat);
        buffer.sputn(date.data(), date.size());

        if(config.m_bColorDate && !fileMode)
        {
            auto color = internal::GetResetColor();
            buffer.sputn(color.data(), color.size());
        }

        if(!config.m_sADate.empty())
            buffer.sputn(config.m_sADate.data(), config.m_sADate.size());
    }

    void FillFunctionToBuffer(std::stringbuf& buffer, const LogConfig& config, std::string_view sFunction, bool fileMode)
    {
        if(!config.m_bLogFunction)
            return;

        if(!config.m_sBFunction.empty())
            buffer.sputn(config.m_sBFunction.data(), config.m_sBFunction.size());

        if(config.m_bColorFunction && !fileMode)
            buffer.sputn(config.m_sColorFunction.data(), config.m_sColorFunction.size());

        buffer.sputn(sFunction.data(), sFunction.size());

        if(config.m_bColorFunction && !fileMode)
        {
            auto color = internal::GetResetColor();
            buffer.sputn(color.data(), color.size());
        }

        if(!config.m_sAFunction.empty())
            buffer.sputn(config.m_sAFunction.data(), config.m_sAFunction.size());
    }

    void FillLineToBuffer(std::stringbuf& buffer, const LogConfig& config, int nLine, bool fileMode)
    {
        if(!config.m_bLogLine)
            return;

        if(!config.m_sBLine.empty())
            buffer.sputn(config.m_sBLine.data(), config.m_sBLine.size());

        if(config.m_bColorLine && !fileMode)
            buffer.sputn(config.m_sColorLine.data(), config.m_sColorLine.size());

        buffer.sputn(std::to_string(nLine).data(), std::to_string(nLine).size());

        if(config.m_bColorLine && !fileMode)
        {
            auto color = internal::GetResetColor();
            buffer.sputn(color.data(), color.size());
        }

        if(!config.m_sALine.empty())
            buffer.sputn(config.m_sALine.data(), config.m_sALine.size());
    }

    void FillLevelToBuffer(std::stringbuf& buffer, const LogConfig& config, std::string_view sLevel, bool fileMode)
    {
        if(!config.m_bLogLevel)
            return;

        if(config.m_bColorLevel && !fileMode)
            buffer.sputn(config.m_sColorLevel.data(), config.m_sColorLevel.size());

        if(!config.m_sBLevel.empty())
            buffer.sputn(config.m_sBLevel.data(), config.m_sBLevel.size());

        buffer.sputn(sLevel.data(), sLevel.size());

        if(!config.m_sALevel.empty())
            buffer.sputn(config.m_sALevel.data(), config.m_sALevel.size());

        auto& lcConfig = internal::GetLogCraftConfig();
        if(lcConfig.m_bAllignLeft)
        {
            auto nMaxLevelWidth = lcConfig.m_nCurrentMaxLevelWidth;
            auto nLevelWidth = sLevel.size();
            auto nDiff = nMaxLevelWidth - nLevelWidth;

            buffer.sputn(std::string(nDiff, ' ').data(), nDiff);
        }
        
        if(config.m_bColorLevel && !fileMode)
        {
            auto color = internal::GetResetColor();
            buffer.sputn(color.data(), color.size());
        }
    }

    void FillLabelToBuffer(std::stringbuf& buffer, const LogConfig& config, std::string_view sLabel, bool fileMode)
    {
        if(sLabel == "")
            return;

        if(config.m_bColorLabel && !fileMode)
            buffer.sputn(config.m_sColorLabel.data(), config.m_sColorLabel.size());

        if(!config.m_sBLabel.empty())
            buffer.sputn(config.m_sBLabel.data(), config.m_sBLabel.size());

        buffer.sputn(sLabel.data(), sLabel.size());

        if(!config.m_sALabel.empty())
            buffer.sputn(config.m_sALabel.data(), config.m_sALabel.size());

        if(config.m_bColorLabel && !fileMode)
        {
            auto color = internal::GetResetColor();
            buffer.sputn(color.data(), color.size());
        }
    }

    void FillMessageToBuffer(std::stringbuf& buffer, const LogConfig& config, std::string_view sMessage, bool fileMode)
    {
        if(!config.m_bLogMessage)
            return;

        if(config.m_bColorMessage && !fileMode)
            buffer.sputn(config.m_sColorMessage.data(), config.m_sColorMessage.size());

        if(!config.m_sBMessage.empty())
            buffer.sputn(config.m_sBMessage.data(), config.m_sBMessage.size());

        buffer.sputn(sMessage.data(), sMessage.size());

        if(!config.m_sAMessage.empty())
            buffer.sputn(config.m_sAMessage.data(), config.m_sAMessage.size());

        if(config.m_bColorMessage && !fileMode)
        {
            auto color = internal::GetResetColor();
            buffer.sputn(color.data(), color.size());
        }
    }

    void FillFileToBuffer(std::stringbuf& buffer, const LogConfig& config, std::string_view sFile, bool fileMode)
    {
        if(!config.m_bLogFile)
            return;

        if(config.m_bColorFile && !fileMode)
            buffer.sputn(config.m_sColorFile.data(), config.m_sColorFile.size());

        if(!config.m_sBFile.empty())
            buffer.sputn(config.m_sBFile.data(), config.m_sBFile.size());

        buffer.sputn(sFile.data(), sFile.size());

        if(!config.m_sAFile.empty())
            buffer.sputn(config.m_sAFile.data(), config.m_sAFile.size());

        if(config.m_bColorFile && !fileMode)
        {
            auto color = internal::GetResetColor();
            buffer.sputn(color.data(), color.size());
        }
    }

    void FillTraceFunctionToBuffer(std::stringbuf& buffer, const LogConfig& config, std::string_view func, bool fileMode)
    {
        if(!config.m_sBTraceFunction.empty())
            buffer.sputn(config.m_sBTraceFunction.data(), config.m_sBTraceFunction.size());

        buffer.sputn(func.data(), func.size());

        if(!config.m_sATraceFunction.empty())
            buffer.sputn(config.m_sATraceFunction.data(), config.m_sATraceFunction.size());
    }

    void FillTraceLineToBuffer(std::stringbuf& buffer, const LogConfig& config, int line, bool fileMode)
    {
        if(!config.m_sBTraceLine.empty())
            buffer.sputn(config.m_sBTraceLine.data(), config.m_sBTraceLine.size());

        auto l = std::to_string(line);
        buffer.sputn(l.data(), l.size());

        if(!config.m_sATraceLine.empty())
            buffer.sputn(config.m_sATraceLine.data(), config.m_sATraceLine.size());
    }

    void FillTraceFileToBuffer(std::stringbuf& buffer, const LogConfig& config, std::string_view file, bool fileMode)
    {
        if(!config.m_sBTraceFile.empty())
            buffer.sputn(config.m_sBTraceFile.data(), config.m_sBTraceFile.size());

        buffer.sputn(file.data(), file.size());

        if(!config.m_sATraceFile.empty())
            buffer.sputn(config.m_sATraceFile.data(), config.m_sATraceFile.size());
    }

    void FillTraceDataToBuffer(std::stringbuf& buffer, const LogConfig& config, Backtrace& bt, bool fileMode)
    {
        for(auto i = 0; i < bt.m_nLineNumbers.size(); i++)
        {
            for(auto& oder : config.m_logOrderTrace)    
            {
                switch(oder)
                {
                    case LogOrder::Function:
                        FillTraceFunctionToBuffer(buffer, config, bt.m_sFunctionNames.at(i), fileMode);
                        break;
                    case LogOrder::Line:
                        FillTraceLineToBuffer(buffer, config, bt.m_nLineNumbers.at(i), fileMode);
                        break;
                    case LogOrder::File:
                        FillTraceFileToBuffer(buffer, config, bt.m_sFileNames.at(i), fileMode);
                        break;
                    default:
                        break;
                }
            }

            if(!config.m_sLeftOverTrace.empty())
                buffer.sputn(config.m_sLeftOverTrace.data(), config.m_sLeftOverTrace.size());
        }
    }

    void FillTraceToBuffer(std::stringbuf& buffer, const LogConfig& config, Backtrace bt, bool fileMode)
    {
        if(!config.m_bLogTrace)
            return;

        if(config.m_bColorTrace && !fileMode)
            buffer.sputn(config.m_sColorTrace.data(), config.m_sColorTrace.size());

        if(!config.m_sBTrace.empty())
            buffer.sputn(config.m_sBTrace.data(), config.m_sBTrace.size());

        TrimFunctionName(bt);
        TrimFile(bt);
        DelAfterMain(bt);

        FillTraceDataToBuffer(buffer, config, bt, fileMode);

        if(!config.m_sATrace.empty())
            buffer.sputn(config.m_sATrace.data(), config.m_sATrace.size());

        if(config.m_bColorTrace && !fileMode)
        {
            auto color = internal::GetResetColor();
            buffer.sputn(color.data(), color.size());
        }
    }

    void FillBuffer(std::stringbuf& buffer, const LogConfig& config, std::string_view sLevel, std::string_view sLabel, std::string_view sMessage, std::string_view sFunction, std::string_view sFile, int nLine, const Backtrace& bt, bool fileMode)
    {
        auto& oder = config.m_logOrder;

        for(auto& order : oder)
        {
            switch(order)
            {
                case LogOrder::Time:
                    FillTimeToBuffer(buffer, config, fileMode);
                    break;
                case LogOrder::Date:
                    FillDateToBuffer(buffer, config, fileMode);
                    break;
                case LogOrder::Function:
                    FillFunctionToBuffer(buffer, config, sFunction, fileMode);
                    break;
                case LogOrder::Line:
                    FillLineToBuffer(buffer, config, nLine, fileMode);
                    break;
                case LogOrder::Level:
                    FillLevelToBuffer(buffer, config, sLevel, fileMode);
                    break;
                case LogOrder::Label:
                    FillLabelToBuffer(buffer, config, sLabel, fileMode);
                    break;
                case LogOrder::Message:
                    FillMessageToBuffer(buffer, config, sMessage, fileMode);
                    break;
                case LogOrder::File:
                    FillFileToBuffer(buffer, config, sFile, fileMode);
                    break;
                case LogOrder::Trace:
                    FillTraceToBuffer(buffer, config, bt, fileMode);
                    break;
                default:
                    break;
            }
        }

        if(!config.m_sLeftOver.empty())
            buffer.sputn(config.m_sLeftOver.data(), config.m_sLeftOver.size());
    }

#pragma endregion FillBuffer

    LC_API std::string BuildMessage(std::string_view sLevel, std::string_view sLabel, std::string_view sMessage, std::string_view sFunction, std::string_view sFile, int nLine, const Backtrace& bt, bool fileMode)
    {
        auto configOpt = internal::GetLogConfig(sLevel);
        if(!configOpt.has_value())
            return "";

        auto& config = configOpt.value().get();
        auto& oder = config.m_logOrder;

        std::stringbuf buffer;
        FillBuffer(buffer, config, sLevel, sLabel, sMessage, sFunction, sFile, nLine, bt, fileMode);

        return buffer.str();
    }

    LC_API void WriteToConsole(std::string_view sMessage)
    {
        std::print("{}\n", sMessage);
    }

    LC_API void WriteToFile(FileObserver& fOb, std::string_view sMessage)
    {
        fOb.write(sMessage.data(), sMessage.size());
    }
}