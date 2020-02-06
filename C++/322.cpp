#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <map>
#include <functional>
using namespace std;


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end(), greater<int>());
        int ans = 0;
        map<int, int> cache;
        int bestAns = -1;
        ans = dp(coins, amount, ans, cache, bestAns);
        return ans;
    }

    int dp(vector<int>& coins, int amount, int ans, map<int, int> &cache, int bestAns) {
        if (amount == 0) {
            if ((bestAns == -1) || (bestAns > ans)) {
                bestAns = ans;
            }
            return ans;
        } else if (amount < coins[coins.size() - 1]) {
            return -1;
        }
        if (cache.count(amount) != 0){
            return ans + cache[amount];
        }
        if (ans == bestAns) {
            return -1;
        }
        int tmpAns = -1;
        for (int i = 0; i < coins.size(); i++) {
            if (amount < coins[i]) {
                continue;
            }
            int flag = dp(coins, amount-coins[i], ans+1, cache, bestAns);
            if (((tmpAns == -1) || (tmpAns > flag)) && (flag != -1)) {
                tmpAns = flag;
            }
        }
        cache[amount] = tmpAns - ans;
        return tmpAns;
    }
};


int main(){
    Solution solution;
    vector<int> m = {186,419,83,408};
    int n = 6249;
    int solution_ans = solution.coinChange(m,n);
    cout << solution_ans << endl;
    system("PAUSE");
    return 0;
}