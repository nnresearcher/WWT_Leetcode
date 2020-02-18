#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <map>
#include <deque>
#include <queue>
#include <functional>
using namespace std;
class NestedInteger {
  public:
    // Constructor initializes an empty nested list.
    NestedInteger();

    // Constructor initializes a single integer.
    NestedInteger(int value);

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Set this NestedInteger to hold a single integer.
    void setInteger(int value);

    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni);

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};
// 给定 s = "[123,[456,[789]]]",

// 返回一个 NestedInteger 对象包含一个有两个元素的嵌套列表：

// 1. 一个 integer 包含值 123
// 2. 一个包含两个元素的嵌套列表：
//     i.  一个 integer 包含值 456
//     ii. 一个包含一个元素的嵌套列表
//          a. 一个 integer 包含值 789
// 给定 s = "324",

// 你应该返回一个 NestedInteger 对象，其中只包含整数值 324。
class Solution {
public:
    vector<string> SplitString(string s) {
        vector<string> ans;
        // 123,[234]
        // [234,123],123
        int flag = 0;
        int index = 0;
        string sFront = "";
        while (1) {
            if ((flag == 0 && s[0] == ',') || s.empty()) {
                if (!s.empty()) s.erase(s.begin());
                ans.push_back(sFront);
                ans.push_back(s);
                break;
            }
            if (s[0] == '[') flag++;
            if (s[0] == ']') flag--;
            sFront.push_back(s[0]);
            s.erase(s.begin());
        }
        return ans;
    }
    NestedInteger deserialize(string s) {
        if (s.size() == 0 || s == "[]") return NestedInteger(); // '[]' || ''
        if (s[0] != '[' && (s.find(',') == string::npos))   return NestedInteger(stoi(s)); // 345
        NestedInteger ans = NestedInteger();
        vector<string> strings;
        cout << "1: " << s << endl;
        if (s[0] == '[') {
            
            s.pop_back();
            s.erase(s.begin());
            strings = SplitString(s);
            ans.add(deserialize(s));
        } else {
            strings = SplitString(s);
            for (int i = 0; i < strings.size(); i++) {
                if (strings[i] != "") {
                    if (strings[i][0] == '[') {
                        ans.add(deserialize(s));
                    } else {
                        ans.setInteger(stoi(strings[i]));
                    }
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    string s = "[-1,-2]";
    solution.deserialize(s);
    system("PAUSE");
    return 0;
}

