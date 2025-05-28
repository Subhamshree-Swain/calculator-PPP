#include <iostream>
#include <string>
using namespace std;

int main(){
    string name;
    cin >> name;
    if(name == "1"){
        cin.putback(name[0]);
    }
    char output;
    cin >> output;
    cout << output << endl;
    return 0;
}

