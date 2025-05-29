#include <iostream>
#include "TokenClass.hpp"
#include "ErrorClass.hpp"
#include "CalculatorFunction.hpp"
#include "globals.hpp"

using namespace std;

int main(){
    double val = 0; 
    try{
        while(cin){
            Token t = ts.get();
            if(t.kind == 'q') break;
            if(t.kind == ';'){
                cout << "==> " << val << "\n\n";
            }
            else{
                ts.putback(t);
                val = Expression();        
            }
        }
    }
    catch(Error& obj){
        cerr << obj.message << endl;
        return -1;
    }
    catch(exception& obj){
        cerr << obj.what() << endl;
        return -1;
    }
    catch(...){
        cerr << "Error occured" << endl;
        return -1;
    }
    return 0;
}
