// https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/


#include <deque>
#include <iostream>
#include <set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) {
            return 0;
        }
        int maxLength = 0;
        deque<char> ansVector;
        set<char> mapKey;
        for (int i = 0; i < s.length(); i++)
        {
            if (mapKey.count(s[i]) == 0) {
                mapKey.insert(s[i]);
                ansVector.push_back(s[i]);
                if (ansVector.size() > maxLength) {
                    maxLength = ansVector.size();
                }
            } else {
                char tmp;
                do {
                    tmp = ansVector.front();
                    ansVector.pop_front();
                    mapKey.erase(tmp);
                    
                } while(tmp != s[i]);
                ansVector.push_back(s[i]);
                mapKey.insert(s[i]);
            }
        }
        return maxLength;
    }
};


#include <vector>
int main(){
    Solution solution;
    vector <pair<string, int>> testCase;

    pair<string, int> case_1("abcabcbb", 3);
    pair<string, int> case_2(" ", 1);
    pair<string, int> case_3("abba", 2);
    // pair<string, int> case_4("ababababa", "ababababa");
    // pair<string, int> case_5("ccc", "ccc");
    testCase.push_back(case_1);
    testCase.push_back(case_2);
    testCase.push_back(case_3);
    // testCase.push_back(case_4);
    // testCase.push_back(case_5);
    for (int i = 0; i < testCase.size(); i++) {
        pair<string, int> test_case = testCase[i];
        string inputString = test_case.first;
        int outputString = test_case.second;
        int solution_ans = solution.lengthOfLongestSubstring(inputString);
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