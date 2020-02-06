#include <vector>
#include <set>
#include <iostream>
using namespace std;



class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        vector<int> ans;
        set<pair<int, int>> hasPostion;
        if (matrix.size() == 0) {
            return ans;
        }
        int row = matrix.size();
        int law = matrix[0].size();
        string state = "left";
        int positionX = 0;
        int positionY = 0;
        int tmpX = 0;
        int tmpY = 0;
        do {
            tmpX = positionX;
            tmpY = positionY;
            ans.push_back(matrix[positionX][positionY]);
            cout<<matrix[positionX][positionY]<<endl;
            pair<int, int> cc(tmpX,tmpY);
            hasPostion.insert(cc);
            updatePosition(matrix, hasPostion, positionX, positionY, state);
        } while (tmpX != positionX || tmpY != positionY);
        return ans;
        
    }
    void nextState(string &state) {
        if (state == "left") {
            state = "down";
        } else if (state == "down") {
            state = "right";
        } else if (state == "right") {
            state = "up";
        } else {
            state = "left";
        }
        return;
    }
    void updatePosition(vector<vector<int>> &matrix, set<pair<int, int>> &hasPostion, int &x, int &y, string &state) {
        int row = matrix.size() - 1;
        int law = matrix[0].size() - 1;
        int cout = 0;
        if (y < law) {
            pair<int, int> position(x, y+1);
            cout += (hasPostion.count(position) ^ 1);
        }
        if (y > 0) {
            pair<int, int> position(x, y-1);
            cout += (hasPostion.count(position) ^ 1);
        }
        if (x < row) {
            pair<int, int> position(x+1, y);
            cout += (hasPostion.count(position) ^ 1);
        }
        if (x > 0) {
            pair<int, int> position(x-1, y);
            cout += (hasPostion.count(position) ^ 1);
        }

        if (cout == 0) {
            return;
        }
        if (state == "left") {
            pair<int, int> position(x, y+1);
            if ((y < law && hasPostion.count(position) == 0)) {
                y++;
                return;
            } else {
                nextState(state);
                updatePosition(matrix, hasPostion, x, y, state);
                return;
            }
        }

        if (state == "down") {
            pair<int, int> position(x+1, y);
            if (x < row && hasPostion.count(position) == 0){
                x++;
                return;
            } else {
                nextState(state);
                updatePosition(matrix, hasPostion, x, y, state);
                return;
            }
        }

        if (state == "right") {
            pair<int, int> position(x, y-1);
            if (y > 0 && hasPostion.count(position) == 0) {
                y--;
                return;
            } else {
                nextState(state);
                updatePosition(matrix, hasPostion, x, y, state);
                return;
            }
        }

        if (state == "up") {
            pair<int, int> position(x-1, y);
            if (x > 0 && (hasPostion.count(position) == 0)) {
                x--;
                return;
            } else {
                nextState(state);
                updatePosition(matrix, hasPostion, x, y, state);
                return;
            }
        }
        
    }
};

int main(){
    Solution solution;
    vector<pair<vector<vector<int>>, vector<int>>> testCase;

    vector<int> s;
    s.push_back(1);
    s.push_back(2);
    s.push_back(3);
    vector<vector<int>> inputs;
    inputs.push_back(s);
    s.clear();
    s.push_back(4);
    s.push_back(5);
    s.push_back(6);
    inputs.push_back(s);
    s.clear();
    s.push_back(7);
    s.push_back(8);
    s.push_back(9);
    inputs.push_back(s);
    s.clear();
    s.push_back(1);
    s.push_back(2);
    s.push_back(3);
    s.push_back(6);
    s.push_back(9);
    s.push_back(8);
    s.push_back(7);
    s.push_back(4);
    s.push_back(5);

    pair<vector<vector<int>>, vector<int>> case_1(inputs, s);
    // pair<vector<vector<int>>, vector<int>> case_2("babad", "bab");
    // pair<vector<vector<int>>, vector<int>> case_3("tattarrattat", "tattarrattat");
    // pair<vector<vector<int>>, vector<int>> case_4("ababababa", "ababababa");
    // pair<vector<vector<int>>, vector<int>> case_5("ccc", "ccc");
    testCase.push_back(case_1);
    // testCase.push_back(case_2);
    // testCase.push_back(case_3);
    // testCase.push_back(case_4);
    // testCase.push_back(case_5);
    for (int i = 0; i < testCase.size(); i++) {
        pair<vector<vector<int>>, vector<int>> test_case = testCase[i];
        vector<vector<int>> inputString = test_case.first;
        vector<int> outputString = test_case.second;
        vector<int> solution_ans = solution.spiralOrder(inputString);
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