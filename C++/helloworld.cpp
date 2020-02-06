#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <vector>
#include <math.h>
#include <unordered_set>
using namespace std;
//https://leetcode-cn.com/problems/longest-consecutive-sequence/


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int length;
        int max_length = 0;
        int temp = 0;
        unordered_set<int> c1;
        for(int i = 0; i < nums.size(); i++){
            c1.insert(nums.at(i));
        }
        for(int i = 0; i<nums.size(); i++){
            length = 0;
            temp = nums.at(i);
            if (c1.erase(temp)){
                length++;
                while(c1.erase(++temp)){
                    length++;
                }
                temp = nums.at(i);
                while(c1.erase(--temp)){
                    length++;
                }
            }
            if (length>max_length){
                max_length = length;
            }
        }
        return max_length;
    }
};

int main(){
    Solution solutions;
    vector<int> s = {100, 4, 200, 1, 3, 2};
    int ans = 4;

    int a = solutions.longestConsecutive(s);

    cout<<"a: "<<a<<endl;
    system("pause");
    return 0;
}