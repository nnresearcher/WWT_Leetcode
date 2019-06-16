#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <vector>
using namespace std;
//https://leetcode-cn.com/problems/maximum-product-subarray/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n==1){
            return nums[0];
        }
        int sj = 1;
        int si = 1;
        int ans = 0;
        int min = 1;
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] == 0){
                sj = 1;
                si = 1;
                min = 1;
                if (ans<0){
                    ans = 0;
                }
                continue;
            }
            
            sj *= nums[i];
            
            if (min>0){
                if (si < min){
                    min = si;
                }
            }
            else{
                if (si<0 && si>min){
                    min = si;
                }
            }
            
            if (sj>0){
                if(sj>ans){
                    ans = sj;
                }
            }
            else if (sj/min>ans){
                ans = sj/min;
            }
            si *=nums[i];
        }
        return ans;
        
    }
};

int main(){
    Solution solutions;
    vector<int> s = {2,-5,-2,-4,3};

    int a = solutions.maxProduct(s);

    cout<<a<<endl;
    system("pause");
    return 0;
}