#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    string s = "123";
    
    string c = "236";
    int a = stoi(c.substr(0,2));
    cout << a;
    cout << endl;
    return 0;
}