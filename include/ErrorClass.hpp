#pragma once

#include <string>
using namespace std;

class Error{
public:
    string message;
    Error(string issue){
        message = issue;
    }
};
