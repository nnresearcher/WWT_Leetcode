#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <map>
#include <deque>
#include <queue>
#include <functional>
using namespace std;

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n, 0);
        for (int i = 0; i < bookings.size(); i++) {
            vector<int> booking = bookings[i];
            for (int j = booking[0]; j <= booking[1]; j++) {
                ans[j-1] += booking[2];
            }
        }
        return ans;
    }
};