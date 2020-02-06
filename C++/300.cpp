#include <vector>
#include <set>
#include <array>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        if (nums.size() == 1 || nums.size() == 0) {
            return nums.size();
        }
        int ans = 1;
        vector<int> dp;
        dp.push_back(1);
        for (int i = 1; i < nums.size(); i++) {
            dp.push_back(1);
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    if (dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                    }
                }
            }
            if (dp[i] > ans){
                ans = dp[i];
            }
        }
        return ans;
    }
};