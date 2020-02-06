#include <vector>
#include <string>
#include <algorithm>
using namespace std;


bool comps(string &s1, string &s2) {
    return s1.length() > s2.length();
}
class Solution {
public:
    bool endsWith(string s,string sub) {
            return s.rfind(sub)==(s.length()-sub.length())?true:false;
    }
    
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(), words.end(), comps);
        int ans = 0;
        for (int i = 1; i < words.size(); ) {
            bool flag = true;
            for (int j = 0; j < i; j++) {
                if (endsWith(words[j], words[i])) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                ans += words[i].size()+1;
                i++;
            } else {
                words.erase(words.begin() + i);
            }
        }
        return ans + words[0].size()+1;
    }
};