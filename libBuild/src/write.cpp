#include "write.hpp"
#include "logConfig.hpp"

#include <sstream>
#include "util.hpp"

namespace lc::internal
{

#pragma region FillBuffer

    void FillTimeToBuffer(std::stringbuf& buffer, const LogConfig& config)
    {
        if(!config.m_bLogTime)
            return;

        if(config.m_bColorTime)
        {
        }

        auto time = eutil::getCurrentTime(config.m_sLogTimeFormat);

        if(config.m_bColorTime)
        {
        }
    }

    void FillDateToBuffer(std::stringbuf& buffer, const LogConfig& config)
    {
        if(!config.m_bLogDate)
            return;

        if(config.m_bColorDate)
        {
        }

        auto date = eutil::getCurrentTime(config.m_sLogDateFormat);

        if(config.m_bColorDate)
        {
        }
    }

    void FillFunctionToBuffer(std::stringbuf& buffer, const LogConfig& config, std::string_view sFunction)
    {
        if(!config.m_bLogFunction)
            return;

        if(config.m_bColorFunction)
        {
        }

        buffer.sputn(sFunction.data(), sFunction.size());

        if(config.m_bColorFunction)
        {
        }
    }

    void FillLineToBuffer(std::stringbuf& buffer, const LogConfig& config, int nLine)
    {
        if(!config.m_bLogLine)
            return;

        if(config.m_bColorLine)
        {
        }

        buffer.sputn(std::to_string(nLine).data(), std::to_string(nLine).size());

        if(config.m_bColorLine)
        {
        }
    }

    void FillLevelToBuffer(std::stringbuf& buffer, const LogConfig& config, std::string_view sLevel)
    {
        if(!config.m_bLogLevel)
            return;

        if(config.m_bColorLevel)
        {
        }

        buffer.sputn(sLevel.data(), sLevel.size());

        if(config.m_bColorLevel)
        {
        }
    }

    void FillMessageToBuffer(std::stringbuf& buffer, const LogConfig& config, std::string_view sMessage)
    {
        if(!config.m_bLogMessage)
            return;

        if(config.m_bColorMessage)
        {
        }

        buffer.sputn(sMessage.data(), sMessage.size());

        if(config.m_bColorMessage)
        {
        }
    }

#pragma endregion FillBuffer

    LOGCRAFT_API std::string BuildMessage(std::string_view sLevel, std::string_view sLabel, std::string_view sMessage, std::string_view sFunction, std::string_view sFile, int nLine)
    {
        auto configOpt = internal::GetLogConfig(sLevel);
        if(!configOpt.has_value())
            return "";

        auto& config = configOpt.value().get();
        auto& oder = config.m_logOrder;

        std::stringbuf buffer;

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
                    FillLevelToBuffer(buffer, config, sLabel);
                    break;
                case LogOrder::Message:
                    FillMessageToBuffer(buffer, config, sMessage);
                    break;
                default:
                    break;
            }
        }
        return buffer.str();
    }

    LOGCRAFT_API void WriteToConsole(std::string_view sMessage)
    {

    }

    LOGCRAFT_API void WriteToFile(std::string_view sFileName, std::string_view sMessage)
    {

    }
}