#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <map>
#include <deque>
#include <queue>
#include <functional>
using namespace std;

class Solution {
public:
    void Init(string &s, deque<int> &num, deque<char> &str) {
        string tmp = "";
        while (!s.empty()) {
            if (s[0] == ' ') {
                s.erase(s.begin());
            } else if (s[0] == '+' || 
                       s[0] == '-' ||
                       s[0] == '*' ||
                       s[0] == '/') {
                num.push_back(stoi(tmp));
                tmp = "";
                str.push_back(s[0]);
                s.erase(s.begin());
            } else {
                tmp.push_back(s[0]);
                s.erase(s.begin());
            }
        }
        num.push_back(stoi(tmp));
        return;
    }

    void calculateAdd(deque<int>& num, deque<char>& str) {
        int numFirst = num.front();
        num.pop_front();
        int numSecond = num.front();
        num.pop_front();
        if (str.front() == '+') {
            int ans = numFirst + numSecond;
            num.push_front(ans);
        } else {
            int ans = numFirst - numSecond;
            num.push_front(ans);
        }
        str.pop_front();
        return;
    }

    void calculateChen(deque<int>& num, deque<char>& str) {
        int numFirst = num.front();
        num.pop_front();
        int numSecond = num.front();
        num.pop_front();
        if (str[0] == '*') {
            int ans = numFirst * numSecond;
            num.push_front(ans);
        } else {
            int ans = numFirst / numSecond;
            num.push_front(ans);
        }
        str.pop_front();
    }

    int calculate(string s) {
        deque<int> num;
        deque<char> str;
        Init(s, num, str);
        while (!str.empty()) {
            if (str[0] == '*' || str[0] == '/') {
                calculateChen(num, str);
            } else {
                if ((str.size() > 1) && (str[1] == '*' || str[1] == '/')) {
                    int tmpNum = num.front();
                    num.pop_front();
                    char tmpStr = str.front();
                    str.pop_front();
                    calculateChen(num, str);
                    num.push_front(tmpNum);
                    str.push_front(tmpStr);
                } else {
                    calculateAdd(num, str); 
                }
            }
        }
        return num.front();
    }
};