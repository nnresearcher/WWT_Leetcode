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

    void dp(vector<vector<int>>& ans, vector<int> nums, vector<int> Ans) {
        if (!nums.empty()) {
            ans.push_back(Ans);
        }

        for (int i = 0; i < nums.size(); i++)
        {
            vector<int> tmpNums = nums;
            vector<int> tmpAns = Ans;
            tmpNums.erase(tmpNums.begin() + i);
            tmpAns.push_back(nums[i]);
            dp(ans, tmpNums, tmpAns);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> Ans;
        dp(ans, nums, Ans);
        return ans;
    }
};