#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <map>
#include <deque>
#include <queue>
#include <functional>
#include <set>
using namespace std;

class Solution {
public:
    int updateLive(vector<vector<int>>& board, int i, int j) {
        vector<int> info;
        int raw = board.size() - 1;
        int column = board[0].size() - 1;
        int liveCore = 0;
        if (i > 0) {
            liveCore += board[i - 1][j];
            if (j > 0) {
                liveCore += board[i - 1][j - 1];
            }
            if (j < column) {
                liveCore += board[i - 1][j + 1];
            }
        }
        if (j > 0) {
            liveCore += board[i][j - 1];
        }
        if (j < column) {
            liveCore += board[i][j + 1];
        }
        if (i < raw) {
            liveCore += board[i + 1][j];
            if (j > 0) {
                liveCore += board[i + 1][j - 1];
            }
            if (j < column) {
                liveCore += board[i + 1][j + 1];
            }
        }
        if (board[i][j] == 0) {
            if (liveCore == 3) {
                return 1;
            }
        } else {
            if ((liveCore < 2) || (liveCore > 3)) {
                return 0;
            } else {
                return 1;
            }
        }
        
        if (liveCore == 2 || liveCore == 3) {
            return 1;
        }
        if (liveCore == 3) {
            return 3;
        } else {
            return 2;
        }
    }

    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> oldBoard = board;
        for (int i = 0; i < oldBoard.size(); i++) {
            for (int j = 0; j < oldBoard[i].size(); j++) {
                int info = updateLive(oldBoard, i, j);
                if ((board[i][j] == 0) && (info == 3)) {
                    board[i][j] = 1;
                } else if ((info == 0) || (info == 2)) {
                    board[i][j] = 0;
                }
            }
        }
    }
};

int main(){
    Solution solution;
    vector<vector<int>> inp = {{0,1,0},{0,0,1},{1,1,1},{0,0,0}};
    solution.gameOfLife(inp);
    system("PAUSE");
    return 0;
}

