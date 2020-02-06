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
        for (int i = 0; i < coins.size(); i++)
        {
            cache[coins[i]] = 1;
        }
        
        ans = dp(coins, amount, cache);
        return ans;
    }

    int dp(vector<int>& coins, int amount, map<int, int> &cache) {
        if (amount == 0) {
            return 0;
        }
        if (cache.count(amount) != 0){
            return cache[amount];
        }
        int tmpAns = -1;
        for (int i = 0; i < coins.size(); i++) {
            if (amount < coins[i]) {
                continue;
            }
            int flag = dp(coins, amount-coins[i], cache) + 1;
            if (((tmpAns == -1) || (tmpAns > flag)) && (flag != 0)) {
                tmpAns = flag;
            }
        }
        if (tmpAns != -1) {
            cache[amount] = tmpAns;
        } else {
            cache[amount] = -1;
        }
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