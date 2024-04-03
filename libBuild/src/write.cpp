#include "write.hpp"

#include <sstream>
#include "hdr/util.hpp"
#include "logConfig.hpp"
#include "logCraftConfig.hpp"

namespace lc::internal
{

#pragma region FillBuffer

    void FillTimeToBuffer(std::stringbuf& buffer, const LogConfig& config)
    {
        if(!config.m_bLogTime)
            return;

        if(config.m_bColorTime)
            buffer.sputn(config.m_sColorTime.data(), config.m_sColorTime.size());

        auto time = eutil::getCurrentTime(config.m_sLogTimeFormat);
        buffer.sputn(time.data(), time.size());

        if(config.m_bColorTime)
        {
            auto color = internal::GetResetColor();
            buffer.sputn(color.data(), color.size());
        }
    }

    void FillDateToBuffer(std::stringbuf& buffer, const LogConfig& config)
    {
        if(!config.m_bLogDate)
            return;

        if(config.m_bColorDate)
            buffer.sputn(config.m_sColorDate.data(), config.m_sColorDate.size());

        auto date = eutil::getCurrentTime(config.m_sLogDateFormat);
        buffer.sputn(date.data(), date.size());

        if(config.m_bColorDate)
        {
            auto color = internal::GetResetColor();
            buffer.sputn(color.data(), color.size());
        }
    }

    void FillFunctionToBuffer(std::stringbuf& buffer, const LogConfig& config, std::string_view sFunction)
    {
        if(!config.m_bLogFunction)
            return;

        if(config.m_bColorFunction)
            buffer.sputn(config.m_sColorFunction.data(), config.m_sColorFunction.size());

        buffer.sputn(sFunction.data(), sFunction.size());

        if(config.m_bColorFunction)
        {
            auto color = internal::GetResetColor();
            buffer.sputn(color.data(), color.size());
        }
    }

    void FillLineToBuffer(std::stringbuf& buffer, const LogConfig& config, int nLine)
    {
        if(!config.m_bLogLine)
            return;

        if(config.m_bColorLine)
            buffer.sputn(config.m_sColorLine.data(), config.m_sColorLine.size());

        buffer.sputn(std::to_string(nLine).data(), std::to_string(nLine).size());

        if(config.m_bColorLine)
        {
            auto color = internal::GetResetColor();
            buffer.sputn(color.data(), color.size());
        }
    }

    void FillLevelToBuffer(std::stringbuf& buffer, const LogConfig& config, std::string_view sLevel)
    {
        if(!config.m_bLogLevel)
            return;

        if(config.m_bColorLevel)
            buffer.sputn(config.m_sColorLevel.data(), config.m_sColorLevel.size());

        buffer.sputn(sLevel.data(), sLevel.size());

        auto& lcConfig = internal::GetLogCraftConfig();
        if(lcConfig.m_bAllignLeft)
        {
            auto nMaxLevelWidth = lcConfig.m_nCurrentMaxLevelWidth;
            auto nLevelWidth = sLevel.size();
            auto nDiff = nMaxLevelWidth - nLevelWidth;

            buffer.sputn(std::string(nDiff, ' ').data(), nDiff);
        }
        
        if(config.m_bColorLevel)
        {
            auto color = internal::GetResetColor();
            buffer.sputn(color.data(), color.size());
        }
    }

    void FillLabelToBuffer(std::stringbuf& buffer, const LogConfig& config, std::string_view sLabel)
    {
        if(sLabel == "")
            return;

        if(config.m_bColorLabel)
            buffer.sputn(config.m_sColorLabel.data(), config.m_sColorLabel.size());

        buffer.sputn(sLabel.data(), sLabel.size());

        if(config.m_bColorLabel)
        {
            auto color = internal::GetResetColor();
            buffer.sputn(color.data(), color.size());
        }
    }

    void FillMessageToBuffer(std::stringbuf& buffer, const LogConfig& config, std::string_view sMessage)
    {
        if(!config.m_bLogMessage)
            return;

        if(config.m_bColorMessage)
            buffer.sputn(config.m_sColorMessage.data(), config.m_sColorMessage.size());

        buffer.sputn(sMessage.data(), sMessage.size());

        if(config.m_bColorMessage)
        {
            auto color = internal::GetResetColor();
            buffer.sputn(color.data(), color.size());
        }
    }

    void FillBuffer(std::stringbuf& buffer, const LogConfig& config, std::string_view sLevel, std::string_view sLabel, std::string_view sMessage, std::string_view sFunction, std::string_view sFile, int nLine)
    {
        auto& oder = config.m_logOrder;

        for(auto& order : oder)
        {
            switch(order)
            {
                case LogOrder::Time:
                    FillTimeToBuffer(buffer, config);
                    break;
                case LogOrder::Date:
                    FillDateToBuffer(buffer, config);
                    break;
                case LogOrder::Function:
                    FillFunctionToBuffer(buffer, config, sFunction);
                    break;
                case LogOrder::Line:
                    FillLineToBuffer(buffer, config, nLine);
                    break;
                case LogOrder::Level:
                    FillLevelToBuffer(buffer, config, sLevel);
                    break;
                case LogOrder::Label:
                    FillLabelToBuffer(buffer, config, sLabel);
                    break;
                case LogOrder::Message:
                    FillMessageToBuffer(buffer, config, sMessage);
                    break;
                default:
                    break;
            }
        }
    }

#pragma endregion FillBuffer

    LOGCRAFT_API std::string CombineArguments(std::string_view sMessage, std::format_args args)
    {
        return std::vformat(sMessage, args);
    }

    LOGCRAFT_API std::string BuildMessage(std::string_view sLevel, std::string_view sLabel, std::string_view sMessage, std::string_view sFunction, std::string_view sFile, int nLine)
    {
        auto configOpt = internal::GetLogConfig(sLevel);
        if(!configOpt.has_value())
            return "";

        auto& config = configOpt.value().get();
        auto& oder = config.m_logOrder;

        std::stringbuf buffer;
        FillBuffer(buffer, config, sLevel, sLabel, sMessage, sFunction, sFile, nLine);

        return buffer.str();
    }

    LOGCRAFT_API void WriteToConsole(std::string_view sMessage)
    {
        std::printf("%s\n", sMessage.data());
    }

    LOGCRAFT_API void WriteToFile(std::string_view sFileName, std::string_view sMessage)
    {

    }
}