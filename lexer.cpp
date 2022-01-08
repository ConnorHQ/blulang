#include <iostream>

enum token {
    tok_eof = -1,
    tok_extern = -3,

    tok_function = -2,

    tok_identifier = -4,
    tok_num = -5,
};

static std::string IdentifierStr;
static double numVal;


static int getTok() {
    static int LastChar = ' ';
    while (isspace(LastChar))
    {
        LastChar = getchar();
    }
    if (isalpha(LastChar))
    {
        IdentifierStr = LastChar;
        while (isalnum((LastChar = getchar())))
        {
            IdentifierStr += LastChar;
            if (IdentifierStr == "func")
                return tok_function;
            if (IdentifierStr == "extern")
                return tok_extern;
            return tok_identifier;
        }
    }
    if (isdigit(LastChar) || LastChar == '.') {
        std::string NumStr;
        do
        {
            NumStr += LastChar;
            LastChar = getchar();
        } while (isdigit(LastChar) || LastChar == '.');
        
        numVal = strtod(NumStr.c_str(), 0);

        return tok_num;
    }
    if (LastChar == '#') {
        // Comment until end of line.
        do
            LastChar = getchar();
        while (LastChar != EOF && LastChar != '\n' && LastChar != '\r');

        if (LastChar != EOF)
            return getTok();
    }
    if (LastChar == EOF)
        return tok_eof;
    int ThisChar = LastChar;
    LastChar = getchar();
    return ThisChar;
}