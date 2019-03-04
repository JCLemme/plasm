#include "log_utility.h"

LogUtility::LogUtility()
{
    abortTypes = MsgError;
    hiddenTypes = (MessageType)0;//MsgDebug;
    color = true;
}

LogUtility::~LogUtility()
{

}

void LogUtility::setColorMode(bool newColor)
{
    color = newColor;
}

MessageType LogUtility::getHiddenTypes()
{
    return hiddenTypes;
}

void LogUtility::setHiddenTypes(MessageType hidden)
{
    hiddenTypes = hidden;
}

MessageType LogUtility::getAbortTypes()
{
    return abortTypes;
}

void LogUtility::setAbortTypes(MessageType aborted)
{
    abortTypes = aborted;
}

void LogUtility::print(std::string location, std::string message, MessageType type)
{
    if((hiddenTypes & static_cast<int>(type)) == 0)
    {
        std::streambuf *outBuf;
        std::string typePrefix, typeColor;
        
        switch(type)
        {
            case(MsgDebug): typePrefix = "debug:"; typeColor = "\033[1;36m"; outBuf = std::cout.rdbuf(); break;
            case(MsgInfo): typePrefix = "info:"; typeColor = "\033[1;32m"; outBuf = std::cout.rdbuf(); break;
            case(MsgWarning): typePrefix = "warning:"; typeColor = "\033[1;33m"; outBuf = std::cerr.rdbuf(); break;
            case(MsgError): typePrefix = "error:"; typeColor = "\033[1;31m"; outBuf = std::cerr.rdbuf(); break;
        }
        
        if((hiddenTypes & static_cast<int>(type)) == 0)
        {
            std::ostream outStream(outBuf);
            
            if(color)
                outStream << "\033[1;37m" << location << ": " << typeColor << typePrefix << " " << "\033[0m" << message << "\n";
            else
                outStream << location << ": " << typePrefix << " " << message << "\n";
        }
        
        if((abortTypes & type) > 0)
            exit(-1);
    }
}
