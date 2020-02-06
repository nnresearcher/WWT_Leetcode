#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <map>
#include <functional>
using namespace std;
bool comp(vector<int> v1, vector<int> v2) {
    return ((v1[0] < v2[0]) || (v1[0] == v2[0] && v1[1] > v2[1]));
}
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), comp);
        vector<vector<int>> AnsPeople = people;
        vector<int> index;
        for (int i = 0; i < people.size(); i++)
        {
            index.push_back(i);
        }
        for (int i = 0; i < people.size(); i++)
        {
            int tmpIndex = index[people[i][1]];
            AnsPeople[tmpIndex] = people[i];
            index.erase(index.begin() + people[i][1]);
        }
        return AnsPeople;
    }
};

int main(){
    Solution solution;
    vector<vector<int>> inp = {{7,0}, {4,4}, {7,1}, {5,0}, {6,1}, {5,2}};
    solution.reconstructQueue(inp);
    system("PAUSE");
    return 0;
}