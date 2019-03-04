#include <iostream>
#include <cstdlib>
#include <map>

#include "log_utility.h"

#define VERSION "v4.0b"

void parseArguments(int argc, char **argv);
void printHelp();

int main(int argc, char **argv)
{
    LogUtility *log = new LogUtility();

    log->print("main:22", "preprocessor: this is a debug message", MsgDebug);
    log->print("main:23", "tokenizer: this is an info message", MsgInfo);
    log->print("main:24", "assembler: this is a warning message", MsgWarning);
    log->print("main:25", "core: this is an error message", MsgError);
    
    return 0;
}


