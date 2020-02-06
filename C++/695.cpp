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

    int calArea(vector<vector<int>>& grid, deque<pair<int, int>> &position){
        int area = 1;
        int raw = grid.size() - 1;
        int column = grid[0].size() - 1;
        while(!position.empty()) {
            pair<int, int> point = position.front();
            position.pop_front();
        
            if ((point.first < raw) && (grid[point.first + 1][point.second] == 1)) {
                area++;
                grid[point.first + 1][point.second] = 0;
                position.push_back({point.first + 1, point.second});

            }
            if ((point.first > 0) && (grid[point.first - 1][point.second] == 1)) {
                area++;
                grid[point.first - 1][point.second] = 0;
                position.push_back({point.first - 1, point.second});
            }
            if ((point.second > 0) && (grid[point.first][point.second - 1] == 1)) {
                area++;
                grid[point.first][point.second - 1] = 0;
                position.push_back({point.first, point.second - 1});
            }
            if ((point.second < column) && (grid[point.first][point.second + 1] == 1)) {
                area++;
                grid[point.first][point.second + 1] = 0;
                position.push_back({point.first, point.second + 1});
            }
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    deque<pair<int, int>> position = {{i, j}};
                    int tmp = calArea(grid, position);
                    ans = ans > tmp ? ans : tmp;
                }
                
            }
        }
        return ans;
    }
};


int main(){
    Solution solution;
    vector<vector<int>> inp = {{0, 1}};
    solution.maxAreaOfIsland(inp);
    system("PAUSE");
    return 0;
}