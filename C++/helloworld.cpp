#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <vector>
#include <math.h>
using namespace std;
//https://leetcode-cn.com/problems/maximum-product-subarray/


class Solution {
public:
    string decodeString(string s) {
        string s1;
        string s2;
        int n = s.length();
        int num = 0;
        char temp;
        int ten = 0;
        for (int index = 0; index < n; index++){
            if(s[index]!=']'){
                s1.push_back(s[index]);
                continue;
            }
            else{
                while(true){
                    temp = s1[s1.length()-1];
                    s1.pop_back();
                    if (temp != '['){
                        s2 = temp + s2;
                        continue;
                    }
                    else{
                        while (true){
                            if( (s1.length()!=0) && (isdigit(s1[s1.length()-1])) ){
                                temp = s1[s1.length()-1];
                                s1.pop_back();
                                num = num + (temp -'0')*pow(10,ten);
                                ten++;
                                continue;
                            }
                            else{
                                for(int j = 0; j < num; j++){
                                    s1 += s2;
                                }
                                ten = 0;
                                num = 0;
                                s2.clear();
                                break;
                            }
                        }
                        break;
                    }
                }
            }
        }
        return s1;
    }
};

int main(){
    Solution solutions;
    string s = "3[1[a]2[bc]]";
    string ans = "aaabcbc";

    string a = solutions.decodeString(s);

    cout<<"a: "<<a<<endl;
    system("pause");
    return 0;
}