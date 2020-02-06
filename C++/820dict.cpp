#include <vector>
#include <string>
#include <array>
#include <algorithm>
#include <unordered_map>
#include <iostream>
using namespace std;
bool comps(string &s1, string &s2) {
    return s1.length() > s2.length();
}
struct trieNode {
    unordered_map<char, trieNode*> children;
};

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(), words.end(), comps);
        trieNode *root = new trieNode();
        int ans = 0;
        for (int i = 0; i < words.size(); i++)
        {
            update(root, words[i], ans);
        }
        return ans;
    }

    void update(trieNode *dicts, string word, int &length) {
        reverse(word.begin(), word.end());
        bool updateflag = false;
        trieNode * tmpdict = dicts;
        for (int i = 0; i < word.size(); i++) {
            if (tmpdict->children.count(word[i]) == 0) {
                updateflag = true;
                trieNode *root = new trieNode();
                tmpdict->children[word[i]] = root;
            }
            tmpdict = tmpdict->children[word[i]];
        }
        if (updateflag) {
            length += word.size() + 1;
        }
    }
};

int main(){
    Solution solution;
    vector<pair<vector<string>, int>> testCase;

    int s = 10;
    vector<string> inputs;
    inputs.push_back("time");
    inputs.push_back("me");
    inputs.push_back("bell");
    pair<vector<string>, int> case_1(inputs, s);

    testCase.push_back(case_1);

    for (int i = 0; i < testCase.size(); i++) {
        pair<vector<string>, int> test_case = testCase[i];
        vector<string> inputString = test_case.first;
        int outputString = test_case.second;
        int solution_ans = solution.minimumLengthEncoding(inputString);
        if (solution_ans == outputString) {
            cout << i + 1 << "th case is right."  << endl;
        } else {
            cout << i + 1 << "th case is wrong!!" << endl;
            // cout << i + 1 << "th case input is: " << inputString << endl;
            // cout << i + 1 << "th case ans is: " << outputString << endl;
            // cout << i + 1 << "th case output is: " << solution_ans << endl;
        }
        cout << "****************************" << endl;
    }
    system("PAUSE");
    return 0;
}