#include "ErrorClass.hpp"
#include <iostream>
#include "TokenClass.hpp"
#include "CalculatorFunction.hpp"
#include "globals.hpp"

double factorial(double x){
    if(x != static_cast<int>(x)){
        throw Error("factorial: Non integer detected");
        return -1;
    }
    if(x < 0){
        throw Error("factorial: Negative number");
        return -1;
    }

    if(x == 0) return 1;
    int result = 1;
    for(int i = 1; i <= x; ++i){
        result = result * i;
    }

    return result;
}

void keep_window_open(string s){
    if(s == "") return;
    cin.clear();
    cin.ignore(120, '\n');
    for(;;){
        cout << "Please enter " << s << " to exit\n";
        string ss;
        while(cin >> ss && ss != s)
            cout << "Please enter " << s << " to exit\n";
        return;
    }
}

void calculate(){
    double val = 0;
    while(cin){
        // cout << ">>> ";
        Token t = ts.get();
        if(t.kind == quit) break;
        if(t.kind == print){
            cout << "==> " << val << "\n\n";
        }
        else{
            ts.putback(t);
            val = Expression();        
        }
    }
}

void clean_up_mess(){
    ts.ignoreTill(print);
    return;
}
