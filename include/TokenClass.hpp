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
    void ignoreTill(char c);
private:
    bool full = false;
   Token buffer;
};
