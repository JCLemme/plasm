#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>

#ifndef CORE
#define CORE

// Types of instruction operands. 
typedef enum OperandType
{
    TypeEnum = 1,
    TypeValue = 2,
    TypeAddress = 3,
    TypeError = -1
} OperandType;

// Instruction argument. Includes a calculated offset from the word beginning.
typedef struct InstructionArgument
{
    // (Usually) single-character ID for the argument.
    std::string id;
    
    // Type of argument.
    OperandType type;
    
    // Used to specify which enum this argument is referring to.
    std::string value;
    
    // Default value of the argument.
    std::string default_value;
    
    
} InstructionArgument;

class Core
{
    public:
    Core();
    ~Core();
    
    // Load in a JSON core file.
    int load(std::string filename);
    
    // Data data data
    std::string name, author, contact;
    
    std::string include_path;
    bool output_pad;
    
    int word_length;
    std::string endianness;
    
    
};

#endif
