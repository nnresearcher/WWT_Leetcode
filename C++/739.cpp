#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> ans;
        ans.push_back(0);
        if (T.size() == 0) {
            return ans;
        }

        for (int i = T.size() - 2; i >= 0; i--) {
            for (int j = i+1; j < T.size() ; j+=ans[T.size() - j - 1]) {
                if (T[i] < T[j]) {
                    ans.push_back(j - i);
                    break;
                } else if (ans[T.size() - j - 1] == 0) {
                    ans.push_back(0);
                    break;
                }
                cout << "i" << i << endl;
                cout << "j" << j << endl;
                cout << "T[i]" << endl;
                cout << "T[j]" << endl;
                cout << "tmp" << ans[T.size() - j - 1] << endl;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(){
    Solution solution;
    vector<pair<vector<int>, vector<int>>> testCase;
    vector<int> s;
    s.push_back(73);
    s.push_back(74);
    s.push_back(75);
    s.push_back(71);
    s.push_back(69);
    s.push_back(72);
    s.push_back(76);
    s.push_back(73);
    vector<int> a;
    a.push_back(1);
    a.push_back(1);
    a.push_back(4);
    a.push_back(2);
    a.push_back(1);
    a.push_back(1);
    a.push_back(0);
    a.push_back(0);
    pair<vector<int>, vector<int>> case_1(s, a);
    testCase.push_back(case_1);
    for (int i = 0; i < testCase.size(); i++) {
        pair<vector<int>, vector<int>> test_case = testCase[i];
        vector<int> inputString = test_case.first;
        vector<int> outputString = test_case.second;
        vector<int> solution_ans = solution.dailyTemperatures(inputString);
        if (solution_ans == outputString) {
            cout << i + 1 << "th case is right."  << endl;
        } else {
            cout << i + 1 << "th case is wrong!!" << endl;
            // cout << i + 1 << "th case input is: " << inputString << endl;
            //cout << i + 1 << "th case ans is: " << outputString << endl;
            // cout << i + 1 << "th case output is: " << solution_ans << endl;
        }
        cout << "****************************" << endl;
    }
    system("PAUSE");
    return 0;
}
