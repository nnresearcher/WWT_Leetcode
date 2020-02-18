#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> ans(num1.size() + num2.size(), 0);
        string ret = "";
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        for (int i = 0; i < num1.size(); i++)
        {
            for (int j = 0; j < num2.size(); j++)
            {
                int position = (i + j);
                int tmp = (num1[i] - '0')(num2[j] - '0');
                ans[position] += tmp;
            }
        }
        int upTmp = 0;
        int ohterTemp = 0;
        for (int i = 0; i < ans.size(); i++)
        {
            ans[i] += ohterTemp;
            ohterTemp = ans[i] / 10;
            ret = to_string(ans[i] % 10) + ret;
        }
        while (ret[0] == '0')
        {
            ret.erase(ret.begin());
        }
        if (ret == ""){
            ret = "0";
        }
        return ret;
    }
};

#include <vector>
int main(){
    Solution solution;
    vector <pair<pair<string, string>, string>> testCase;

    pair<string, string> case_1_input("123", "456");
    pair<pair<string, string>, string> case_1(case_1_input, "56088");
    pair<string, string> case_2_input("0", "0");
    pair<pair<string, string>, string> case_2(case_2_input, "0");
    // pair<string, int> case_2(" ", 1);
    // pair<string, int> case_3("abba", 2);
    // pair<string, int> case_4("ababababa", "ababababa");
    // pair<string, int> case_5("ccc", "ccc");
    testCase.push_back(case_1);
    testCase.push_back(case_2);
    // testCase.push_back(case_3);
    // testCase.push_back(case_4);
    // testCase.push_back(case_5);
    for (int i = 0; i < testCase.size(); i++) {
        pair<pair<string, string>, string> test_case = testCase[i];
        pair<string, string> inputString = test_case.first;
        string input_1 = inputString.first;
        string input_2 = inputString.second;
        string outputString = test_case.second;
        string solution_ans = solution.multiply(input_1, input_2);
        if (solution_ans == outputString) {
            cout << i + 1 << "th case is right."  << endl;
        } else {
            cout << i + 1 << "th case is wrong!!" << endl;
            cout << i + 1 << "th case input is: " << input_1 << " / " << input_2 << endl;
            cout << i + 1 << "th case ans is: " << outputString << endl;
            cout << i + 1 << "th case output is: " << solution_ans << endl;
        }
        cout << "****************************" << endl;
    }
    system("PAUSE");
    return 0;
}