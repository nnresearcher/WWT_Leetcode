#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <map>
#include <deque>
#include <queue>
#include <set>
#include <functional>
using namespace std;


class Solution {
public:

    int dfs(map<int, vector<int>> &Tree, int node, set<int> usedNode, int& ans) {
        vector<int> length;
        usedNode.insert(node);
        for (int i = 0; i < Tree[node].size(); i++) {
            if (usedNode.count(Tree[node][i]) == 0) {
                length.push_back(1 + dfs(Tree, Tree[node][i], usedNode, ans));
            }
        }

        sort(length.begin(), length.end(), greater<int>());
        if (length.size() > 1) {
            if (length[0] + length[1] > ans) {
                ans = length[0] + length[1];
            }
            return (length[0]);
        } else if (length.size() == 1) {
            if (length[0] > ans) {
                ans = length[0];
            }
            return length[0];
        } else {
            return 0;
        }
    }

    int treeDiameter(vector<vector<int>>& edges) {
        map<int, vector<int>> Tree;
        for (int i = 0; i < edges.size(); i++) {
            Tree[edges[i][0]].push_back(edges[i][1]);
            Tree[edges[i][1]].push_back(edges[i][0]);
        }
        set<int> usedNode;
        int ans = 0;
        (void) dfs(Tree, edges[0][0], usedNode, ans);
        return ans;
    }
};