#include <iostream>
#include <vector>

class ExprAST
{
public:
    virtual ~ExprAST();
};

class numExperAST : public ExprAST {
    double val;
public:
    numExperAST(double val): val(val) {}
};

class varExprAST : public ExprAST
{
    std::string Name;
public:
    varExprAST(const std::string &Name) : Name(Name) {}
};

class binaryExprAST : public ExprAST
{
    char Op;
    std::unique_ptr<ExprAST> LHS, RHS;
public:
    binaryExprAST(
        char op, std::unique_ptr<ExprAST> LHS,
        std::unique_ptr<ExprAST> RHS
    ) :Op(op), LHS(std::move(LHS)), RHS(std::move(RHS)){}
};

class callExprAST : public ExprAST {
    std::string Callee;
    std::vector<std::unique_ptr<ExprAST>> Args;
public:
    callExprAST(const std::string &Callee, std::vector<std::unique_ptr<ExprAST>> Args)
    : Callee(Callee), Args(std::move(Args)) {}
};
