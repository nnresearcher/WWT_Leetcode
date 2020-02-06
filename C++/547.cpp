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
    void DP(vector<vector<int>>& M, int people, set<int>& quan) {
        for (int i = 0; i < M[people].size(); i++) {
            if (M[people][i] == 1) {
                if (quan.count(i) == 0) {
                    quan.insert(i);
                    DP(M, i, quan);
                }
                    M[people][i] = 0;
                    M[people][i] = 0;
            }
        }
    }
    int findCircleNum(vector<vector<int>>& M) {
        int ans = 0;
        for (int i = 0; i < M.size(); i++) {
            for (size_t j = 0; j < M[i].size(); j++) {
                if (M[i][j] == 1) {
                    ans++;
                    set<int> quan;
                    DP(M, i, quan);
                }
            }
        }
        return ans;
    }
};