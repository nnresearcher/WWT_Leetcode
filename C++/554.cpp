#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    void updateWall(vector<vector<int>>& wall) {
        for (int i = 0; i < wall.size(); i++) {
            for (int j = 1; j < wall[i].size(); j++) {
                wall[i][j] += wall[i][j-1];
            }
        }
    }

    int leastBricks(vector<vector<int>>& wall) {
        updateWall(wall);
        int ans = wall.size();
        dfs(wall, ans);
        return ans;
    }

    void dfs(vector<vector<int>>& wall, int &ans) {
        int tmpAns = 0;
        for (int i = 0; i < wall.size(); i++) {
            for (int j = 0; j < wall[i].size()-1; j++) {
                tmpAns = calNum(wall, wall[i][j]);
                if (tmpAns < ans) {
                    ans = tmpAns;
                }
            }
        }
    }

    int calNum(vector<vector<int>>& wall, int bian) {
        int ans = wall.size();
        bool flag = false;
        for (int i = 0; i < wall.size(); i++) {
            for (int j = 0; j < wall[i].size()-1; j++) {
                if (bian < wall[i][j]) {
                    continue;
                }
                if (bian == wall[i][j]) {
                    ans--;
                    continue;
                }
            }
        }
        return ans;
    }
};