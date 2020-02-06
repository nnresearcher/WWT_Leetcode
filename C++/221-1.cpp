#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int length = 0;
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return length;
        }
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                while(isRight(matrix, length+1, i, j)) {
                    length++;
                }
            }
        }
        return length*length;
    }

    bool isRight(vector<vector<char>>& matrix, int length, int x, int y) {
        if ((x + length)> matrix.size() || (y + length) > matrix[0].size()) {
            return false;
        }
        for (int i = x; i < x + length; i++) {
            for (int j = y; j < y + length; j++) {
                if (matrix[i][j] != '1') {
                    return false;
                }
            }
        }
        return true;
    }
};

int main(){
    Solution solution;
    vector<pair<vector<vector<char>>, int>> testCase;
    vector<char> s;
    s.push_back('1');
    s.push_back('0');
    s.push_back('1');
    s.push_back('0');
    s.push_back('0');
    vector<vector<char>> inputs;
    inputs.push_back(s);
    s.clear();
    s.push_back('1');
    s.push_back('0');
    s.push_back('1');
    s.push_back('1');
    s.push_back('1');
    inputs.push_back(s);
    s.clear();
    s.push_back('1');
    s.push_back('1');
    s.push_back('1');
    s.push_back('1');
    s.push_back('1');
    inputs.push_back(s);
    s.push_back('1');
    s.push_back('0');
    s.push_back('0');
    s.push_back('1');
    s.push_back('0');
    inputs.push_back(s);
    pair<vector<vector<char>>, int> case_1(inputs, 4);
    testCase.push_back(case_1);
    for (int i = 0; i < testCase.size(); i++) {
        pair<vector<vector<char>>, int> test_case = testCase[i];
        vector<vector<char>> inputString = test_case.first;
        int outputString = test_case.second;
        int solution_ans = solution.maximalSquare(inputString);
        if (solution_ans == outputString) {
            cout << i + 1 << "th case is right."  << endl;
        } else {
            cout << i + 1 << "th case is wrong!!" << endl;
            // cout << i + 1 << "th case input is: " << inputString << endl;
            cout << i + 1 << "th case ans is: " << outputString << endl;
            cout << i + 1 << "th case output is: " << solution_ans << endl;
        }
        cout << "****************************" << endl;
    }
    system("PAUSE");
    return 0;
}
