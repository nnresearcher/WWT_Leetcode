
#include <string>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        for (int a = 1; a < 4; a++) {
            for (int b = 1; b < 4; b++) {
                for (int c = 1; c < 4; c++) {
                    if (a+b+c >= s.size() ||  s.size()-(a+b+c)>4) {
                        continue;
                    }
                    int num1 = stoi(s.substr(0, a));
                    int num2 = stoi(s.substr(a, b));
                    int num3 = stoi(s.substr(a+b, c));
                    int num4 = stoi(s.substr(a+b+c));
                    cout << "a:" << a << " " << num1 << endl;
                    cout << "b:" << b << " " << num2 << endl;
                    cout << "c:" << c << " " << num3 << endl;
                    cout << "num4:" << num4 << endl;
                    if ((num1 <= 255) && (num2 <= 255) && (num3 <= 255) && (num4 <= 255)) {
                        string tmp = to_string(num1)
                                    + "." + to_string(num2)
                                    + "." + to_string(num3)
                                    + "." + to_string(num4);
                        if (tmp.size() == (s.size()+3)){
                            ans.push_back(tmp);
                        }
                    }
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution solution;
    vector <pair<string, vector<string>>> testCase;

    string case_1_inupt("25525511135");
    vector<string> case_1_output;
    case_1_output.push_back("255.255.11.135");
    case_1_output.push_back("255.255.111.35");
    pair<string, vector<string>> case_1(case_1_inupt, case_1_output);

    string case_2_inupt("0000");
    vector<string> case_2_output;
    case_2_output.push_back("0.0.0.0");
    pair<string, vector<string>> case_2(case_2_inupt, case_2_output);

    string case_3_inupt("010010");
    vector<string> case_3_output;
    case_3_output.push_back("0.10.0.10");
    case_3_output.push_back("0.100.1.0");
    pair<string, vector<string>> case_3(case_3_inupt, case_3_output);

    string case_4_inupt("0279245587303");
    vector<string> case_4_output;
    case_4_output.push_back("0.10.0.10");
    case_4_output.push_back("0.100.1.0");
    pair<string, vector<string>> case_4(case_4_inupt, case_4_output);




    // pair<string, vector<string>> case_2(" ", 1);
    // pair<string, vector<string>> case_3("abba", 2);
    // pair<string, int> case_4("ababababa", "ababababa");
    // pair<string, int> case_5("ccc", "ccc");
    testCase.push_back(case_1);
    testCase.push_back(case_2);
    testCase.push_back(case_3);
    testCase.push_back(case_4);
    // testCase.push_back(case_5);
    for (int i = 0; i < testCase.size(); i++) {
        pair<string, vector<string>> test_case = testCase[i];
        string inputString = test_case.first;
        vector<string> outputString = test_case.second;
        vector<string> solution_ans = solution.restoreIpAddresses(inputString);
        if (solution_ans == outputString) {
            cout << i + 1 << "th case is right."  << endl;
        } else {
            cout << i + 1 << "th case is wrong!!" << endl;
            cout << i + 1 << "th case input is: " << inputString << endl;
            cout << i + 1 << "th case ans is: ";
            for (int i = 0; i < outputString.size(); i++)
            {
                cout << outputString[i] << " ";
            }
            cout << endl;
            cout << i + 1 << "th case output is: ";
            for (int i = 0; i < solution_ans.size(); i++)
            {
                cout << solution_ans[i] << " ";
            }
            cout << endl;
        }
        cout << "****************************" << endl;
    }
    system("PAUSE");
    return 0;
}