#define PI 3.1415
#define e 2.71


#include "CalculatorFunction.hpp"
#include "TokenClass.hpp"
#include "ErrorClass.hpp"
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
        case '8':
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
        default:
            throw Error("Primary missing");
            return -1;
    }
}

double Term(){
    double term = Primary();
    Token t = ts.get();
    while(true){
        switch(t.kind){
            case '*':
                {
                    term *= Primary();
                    t = ts.get();
                    break;
                }
            case '/':
                {
                    double c = Primary();
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
                    double n = Primary();
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
                expr += Primary();
                t = ts.get();
                break;
            case '-':
                expr -= Primary();
                t = ts.get();
                break;
            default:
                ts.putback(t);
                return expr;
        }
    }
}
