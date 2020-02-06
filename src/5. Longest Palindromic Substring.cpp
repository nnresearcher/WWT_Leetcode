#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <cstdlib>
using namespace std;
https://leetcode-cn.com/problems/longest-palindromic-substring/submissions/
class Solution {
public:
    string longestPalindrome(string s) {
        string ans;
        ans = s[0];
        if (s.length()==0){return "";}
        else if (s.length()==1){return s;}
        else if (s.length()==2){if (s[0]==s[1]){return s;}else{return ans;}}
        int centerpoint = 1;
        int leftpoint = 1;
        int rightpoint = 1;

        int left = 0;
        int right = 1;
        string ret1 = MaxLengthPalindrome(s, centerpoint, leftpoint, rightpoint, ans);
        string ret2 = MaxLengthPalindrometwo(s, left, right, 0, 0, ans);
        if( ret1.length() > ret2.length()){
            return ret1;
        }
        else{
            return ret2;
        }
        
        
    }

    string MaxLengthPalindrome(string s, int centerpoint, int leftpoint, int rightpoint, string ans){
        while(centerpoint + rightpoint < s.length()){
            if (centerpoint - leftpoint <0){
                centerpoint++;
                if(centerpoint + rightpoint >= s.length()){
                    return ans;
                }
            }
            if(PalindromeTest(s.substr(centerpoint - leftpoint, leftpoint + rightpoint+1))){
                ans = s.substr(centerpoint - leftpoint, leftpoint + rightpoint+1);
                //这里出现了死循环
                return MaxLengthPalindrome(s, centerpoint, leftpoint + 1, rightpoint + 1, ans);
            }
            else{
                centerpoint++;
            }
        }
        return ans;
    }

    string MaxLengthPalindrometwo(string s, int left, int right, int leftpoint, int rightpoint, string ans){
        while(right + rightpoint < s.length()){
            if (left - leftpoint <0){
                left++;
                right++;
                if(right + rightpoint >= s.length()){
                    return ans;
                }
            }
            if(PalindromeTest(s.substr(left - leftpoint,  right + rightpoint-left + leftpoint+1))){
                ans = s.substr(left - leftpoint, right + rightpoint-left + leftpoint+1);
                return MaxLengthPalindrometwo(s, left, right, leftpoint+1, rightpoint+1, ans);
            }
            else{
                left++;
                right++;
            }
        }
        return ans;
    }
    bool PalindromeTest(string s){
        int len = s.length();
        for(int i = 0; i < (len / 2); i++){ 
            if(s[i] != s[len - 1 - i]){
                return false;
            }
        }
        return true;
    }
};
int TestSolution(string right_ans, string output){
    if (right_ans==output)
    {
        return 1;
    }
    else{
        return 0;
    }
}
int main(){
    Solution solution;
    string s;
    string solution_ans;
    /* 
    cout<<"First test case:"<<endl;
    s = "babad";
    string ans1 = "bab";
    string ans2 = "aba";
    
    solution_ans = solution.longestPalindrome(s);

    if ( (solution_ans== ans1) || (solution_ans == ans2) )
    {
        cout<< "First test case is right."<<endl;
        
    }
    else
    {
        cout<< "wrong ans."<<endl;
        cout<< "right ans:"<<ans1<<" "<< ans2 <<endl;
        cout<< "your ans:"<<solution_ans<<endl;
    }

    */
    /*
    cout<<"Second test case:"<<endl;
    s = "cbbd";
    string ans = "bb";

    solution_ans = solution.longestPalindrome(s);

    if (solution_ans == ans)
    {
        cout<< "Second test case is right."<<endl;
    }
    else
    {
        cout<< "wrong ans."<<endl;
        cout<< "right ans:"<<ans<<endl;
        cout<< "your ans:"<<solution_ans<<endl;
    }
    */
    cout<<"Third test case:"<<endl;
    s = "babad";
    string ans = "bab";

    solution_ans = solution.longestPalindrome(s);

    if (solution_ans == ans)
    {
        cout<< "Third test case is right."<<endl;
    }
    else
    {
        cout<< "wrong ans."<<endl;
        cout<< "right ans:"<<ans<<endl;
        cout<< "your ans:"<<solution_ans<<endl;
    }

    system("PAUSE");
    return 0;
}

