#include <iostream>
#include "TokenClass.hpp"
#include "ErrorClass.hpp"
using namespace std;

void TokenStream::putback(Token t){
    if(full) throw Error("Buffer overflow");
    buffer = t;
    full = true;
}

Token TokenStream::get(){
    if(full){
        full = false;
        return buffer;
    }

    char c;
    cin >> c;

    switch(c){
        case '(':
        case ')':
        case '{':
        case '}':
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
        case ';':
        case 'q':
        case 'p':
        case 'i':
        case 'e':
            return Token{c};
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            {
                cin.putback(c);
                double value;
                cin >> value;
                return Token{'8', value};
            }
        default:
            throw Error("Token get() function failed");
    }
}

TokenStream ts;
