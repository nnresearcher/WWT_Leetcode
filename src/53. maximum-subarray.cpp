#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <vector>
using namespace std;
//https://leetcode-cn.com/problems/maximum-subarray/
class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int n = nums.size();
        if (n==1){
            return nums[0];
        }
        int min_sum = 0;
        int sj = 0;
        int si = 0;
        int ans = -2147483647;
        for(int i = 0; i < n; i++){
            sj += nums[i];
            if (si<min_sum){
                min_sum = si;
            }
            if (sj-min_sum>ans){
                ans = sj-min_sum;
            }
            si +=nums[i];
        }
        return ans;
    }
};