#define PI 3.1415
#define e 2.71

#include "CalculatorFunction.hpp"
#include "TokenClass.hpp"
#include "ErrorClass.hpp"
#include "globals.hpp"
#include "utility.hpp"
using namespace std;

double Primary(){
    Token t = ts.get();
    switch(t.kind){
        case '(':
            {
                double d = Expression();
                t = ts.get();
                if(t.kind != ')'){
                    throw Error("missing )");
                    return -1;
                }
                return d;
            }
        case '{':
            {
                double s = Expression();
                t = ts.get();
                if(t.kind != '}'){
                    throw Error("missing }");
                    return -1;
                }
                return s;
            }
        case TokenNumber:
            return t.value;
        case 'p':
            {
                t = ts.get();
                if(t.kind != 'i'){
                    throw Error("p is unknown");
                    return -1;
                }
                return PI;
            }
        case 'e':
            return e;
        case '-':
            return -Primary();
        default:
            throw Error("Primary missing");
            return -1;
    }
}

double Postfix(){
    double fact = Primary();
    Token t = ts.get();
    while(true){
        switch(t.kind){
            case '!':
                {
                    fact = factorial(fact);
                    t = ts.get();
                    break;
                }
            default:
                ts.putback(t);
                return fact;
        }
    }
}

double Term(){
    double term = Postfix();
    Token t = ts.get();
    while(true){
        switch(t.kind){
            case '*':
                {
                    term *= Postfix();
                    t = ts.get();
                    break;
                }
            case '/':
                {
                    double c = Postfix();
                    if(c == 0){
                        throw Error("0 division");
                        return -1;
                    }
                    term /= c;
                    t = ts.get();
                    break;
                }
            case '%':
                {
                    double n = Postfix();
                    if(term == static_cast<int>(term) ||
                       n == static_cast<int>(n)){
                        term = static_cast<int>(term)%static_cast<int>(n);
                        t = ts.get();
                        break;
                    }
                    else{
                        throw Error("not int for %");
                        return -1;
                    }
                }
            default:
                ts.putback(t);
                return term;
        }
    }
}

double Expression(){
    double expr = Term();
    Token t = ts.get();
    while(true){
        switch(t.kind){
            case '+':
                expr += Term();
                t = ts.get();
                break;
            case '-':
                expr -= Term();
                t = ts.get();
                break;
            default:
                ts.putback(t);
                return expr;
        }
    }
}
