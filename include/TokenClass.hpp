#pragma once

class Token{
public:
    char kind;
    double value;
};

class TokenStream{
public:
    void putback(Token t);
    Token get();
private:
    bool full = false;
   Token buffer;
};
