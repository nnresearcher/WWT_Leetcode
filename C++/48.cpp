#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;


class Solution {
public:
    int uniquePaths(int m, int n) {
        int ans = 0;
        map<pair<int, int>, int> dpSave;
        int cache = 0;
        ans = dp(m-1, n-1, ans, dpSave, cache);
        return ans;
    }

    int dp(int m, int n, int ans, map<pair<int, int>, int>& dpSave, int cache) {
        if (m == 0 && n == 0) {
            ans++;
            return ans;
        }
        
        pair<int, int> tmp(m, n);
        if (dpSave.count(tmp) != 0) {
            ans += dpSave[tmp];
            return ans;
        } else {
            dpSave[tmp] = 0;
        }
        int ans_2 = 0;
        if (m != 0) {
            ans_2 = dp(m-1, n, ans, dpSave, cache);
        }
        if (n != 0) {
            if (m != 0) {
                ans_2 = dp(m, n-1, ans_2, dpSave, cache);
            } else {
                ans_2 = dp(m, n-1, ans, dpSave, cache);
            }
        }
        dpSave[tmp] = ans_2 - ans;
        return ans_2;
    }
};

int main(){
    Solution solution;
    int m = 3;
    int n = 2;
    int solution_ans = solution.uniquePaths(m,n);
    cout << solution_ans << endl;
    system("PAUSE");
    return 0;
}