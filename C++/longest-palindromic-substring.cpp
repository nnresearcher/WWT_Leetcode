#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
// https://leetcode-cn.com/problems/longest-palindromic-substring/comments/
class Solution {
public:
    string longestPalindrome(string s) {
        int ans_beg = 0;
        int ans_length = 0;
        if ((s.length() == 1) || (s.length() == 0)) {
            return s;
        }
        for (int i = 0; i < (s.length()-ans_length/2); i++) {
            checkDfsAccordingLength(s, ans_length + 2, i, ans_beg, ans_length);
            checkDfsAccordingLength(s, ans_length + 1, i, ans_beg, ans_length);
        }
        if (ans_length == 0) {
            return "";
        } else {
            string ans(s.begin() + ans_beg, s.begin() + ans_beg + ans_length);
            return ans;
        }
    }

    void checkDfsAccordingLength(string &s, int length, int index, int &ans_beg, int &ans_length) {
        if (length % 2 == 1) {
            if ((index - length / 2 >= 0) && (index + length / 2 < s.length())) {
                dfs(s, index - length / 2, index + length / 2, ans_beg, ans_length);
            }
        } else {
            if ((index - length / 2 >= 0) && (index + length / 2 - 1 < s.length())) {
                dfs(s, index - length / 2, index + length / 2 - 1, ans_beg, ans_length);
            }
        }
    }

    void dfs(const string &s, int leftIndex, int rightIndex, int &ans_beg, int &ans_length) {
        string tmp(s.begin() + leftIndex, s.begin() + rightIndex + 1);
        if (isBackString(tmp)) {
            if (tmp.length() > ans_length) {
                ans_beg = leftIndex;
                ans_length = tmp.length();
            }
            if (leftIndex > 0) {
                dfs(s, leftIndex - 1, rightIndex, ans_beg, ans_length);
            }
            if (rightIndex < (s.length() - 1)) {
                dfs(s, leftIndex, rightIndex + 1, ans_beg, ans_length);
            }
            if ((leftIndex > 0) && (rightIndex < s.length()-1)) {
                dfs(s, leftIndex - 1, rightIndex + 1, ans_beg, ans_length);
            }
        }
    }

    bool isBackString(string &s) {
        string reString = s;
        reverse(reString.begin(), reString.end());
        if (reString == s) {
            return true;
        } else {
            return false;
        }
    }
};


int main(){
    Solution solution;
    vector <pair<string, string>> testCase;

    pair<string, string> case_1("bb", "bb");
    pair<string, string> case_2("babad", "bab");
    pair<string, string> case_3("tattarrattat", "tattarrattat");
    pair<string, string> case_4("ababababa", "ababababa");
    pair<string, string> case_5("ccc", "ccc");
    testCase.push_back(case_1);
    testCase.push_back(case_2);
    testCase.push_back(case_3);
    testCase.push_back(case_4);
    testCase.push_back(case_5);
    for (int i = 0; i < testCase.size(); i++) {
        pair<string, string> test_case = testCase[i];
        string inputString = test_case.first;
        string outputString = test_case.second;
        string solution_ans = solution.longestPalindrome(inputString);
        if (solution_ans == outputString) {
            cout << i + 1 << "th case is right."  << endl;
        } else {
            cout << i + 1 << "th case is wrong!!" << endl;
            cout << i + 1 << "th case input is: " << inputString << endl;
            cout << i + 1 << "th case ans is: " << outputString << endl;
            cout << i + 1 << "th case output is: " << solution_ans << endl;
        }
        cout << "****************************" << endl;
    }
    system("PAUSE");
    return 0;
}