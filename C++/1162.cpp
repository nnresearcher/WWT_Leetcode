#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <map>
#include <deque>
#include <functional>
using namespace std;

class Solution {
public:
    void InitList(deque<pair<pair<int, int>, int>>& tmpList, vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    pair<pair<int, int>, int> positionInfo = {{i ,j}, 0};
                    tmpList.push_back(positionInfo);
                }
            }
        }
    }

    void updateList(deque<pair<pair<int, int>, int>> &tmpList, vector<vector<int>>& grid) {

    }

    int maxDistance(vector<vector<int>>& grid) {
        deque<pair<pair<int, int>, int>> tmpList;
        InitList(tmpList, grid);
        pair<pair<int, int>, int> point;
        while (!tmpList.empty()) {
            point = tmpList.front();
            tmpList.pop_front();
            pair<int ,int> position = point.first;
            int raw = grid.size() - 1;
            int column = grid[0].size() - 1;
            if ((position.first < raw) && (grid[position.first + 1][position.second] == 0)) {
                pair<pair<int, int>, int> positionInfo = {{position.first + 1, position.second}, point.second + 1};
                tmpList.push_back(positionInfo);
                grid[position.first + 1][position.second] = 1;
            }
            if ((position.first > 0) && (grid[position.first - 1][position.second] == 0)) {
                pair<pair<int, int>, int> positionInfo = {{position.first - 1, position.second}, point.second + 1};
                tmpList.push_back(positionInfo);
                grid[position.first - 1][position.second] = 1;
            }
            if ((position.second > 0) && (grid[position.first][position.second - 1] == 0)) {
                pair<pair<int, int>, int> positionInfo = {{position.first, position.second - 1}, point.second + 1};
                tmpList.push_back(positionInfo);
                grid[position.first][position.second - 1] = 1;
            }
            if ((position.second < column) && (grid[position.first][position.second + 1] == 0)) {
                pair<pair<int, int>, int> positionInfo = {{position.first, position.second + 1}, point.second + 1};
                tmpList.push_back(positionInfo);
                grid[position.first][position.second + 1] = 1;
            }
        }
        return point.second;
    }
};