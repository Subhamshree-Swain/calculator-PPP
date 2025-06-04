#include <iostream>
#include "ErrorClass.hpp"
#include "utility.hpp"

using namespace std;

int main(){
    try{
        calculate();
    }
    catch(Error& obj){
        cerr << obj.message << '\n';
        keep_window_open("~~");
        return -1;
    }
    catch(exception& obj){
        cerr << obj.what() << '\n';
        keep_window_open("~~");
        return -1;
    }
    catch(...){
        cerr << "Error occured" << '\n';
        keep_window_open("~~");
        return -1;
    }
    return 0;
}
