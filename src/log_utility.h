#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

#ifndef LOG_UTILITY
#define LOG_UTILITY

enum MessageType
{
    MsgDebug = 1,
    MsgInfo = 2,
    MsgWarning = 4,
    MsgError = 8
};

class LogUtility
{
    public:
    LogUtility();
    ~LogUtility();
    
    void setColorMode(bool newColor);
    
    MessageType getHiddenTypes();
    void setHiddenTypes(MessageType hidden);
    
    MessageType getAbortTypes();
    void setAbortTypes(MessageType aborted);
    
    void print(std::string location, std::string message, MessageType type);
    
    private:
    MessageType abortTypes;
    MessageType hiddenTypes;
    bool color;
};
    
inline MessageType operator|(MessageType a, MessageType b)
{return static_cast<MessageType>(static_cast<int>(a) | static_cast<int>(b));}

#endif
