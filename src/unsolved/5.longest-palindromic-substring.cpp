#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <cstdlib>
using namespace std;
//https://leetcode-cn.com/problems/longest-palindromic-substring/
class Solution {
public:
    string longestPalindrome(string s) {
        string ans;
        ans = s[0];
        if (s.length()==0){return "";}
        else if (s.length()==1){return s;}
        else if (s.length()==2){if (s[0]==s[1]){return s;}else{return ans;}}
        bool odd = true;
        bool even = true;

        int center_point = 0;
        int max_length = 1;
        int length = 1;
        while (true) {
            if ((length)%2){
                cout<<"################################"<<endl;
                cout<<"test length is "<<length+1<<endl;
                if (center_point+1-(length+1)/2<0){
                    cout<< "Down" <<endl;
                    cout<< "add center_point, from"<< center_point << " to " << center_point+1<<endl;
                    cout<< "test length to 2."<<endl;
                    center_point++;
                    length = 1;
                    continue;
                }
                if (length+1+center_point+1-(length+1)/2>s.length())
                {
                    if (center_point==(s.length()-1)){
                        cout<<"center_point is largest"<<endl;
                        cout<< "center_point:"<<center_point<<"s.length()"<<s.length()<<endl;
                        return ans;
                    }
                    else{
                        cout<< "add center_point, from"<< center_point << " to " << center_point+1<<endl;
                        cout<< "test length to 2."<<endl;
                        center_point++;
                        length = 1;
                        continue;
                    }
                }
                cout<<"test str:"<< s.substr(center_point+1-(length+1)/2, length+1)<<endl;
                even = PalindromeTest(s.substr(center_point+1-(length+1)/2, length+1));
                if (even){
                    cout<<"test str is ok!"<<endl;
                    cout<<"max_length:"<<max_length<<endl;
                    cout<<"length:"<<length<<endl;
                    if (max_length<length+1){
                       cout<<"max_length<length change max_length to "<<length<<endl;
                        ans = s.substr(center_point+1-(length+1)/2, length+1);
                        max_length = length;
                    }
                    
                }
                else
                {
                    cout<<"test str is not ok"<<endl;
                }
                cout<<"add length to " << length+1<<endl;
                length++;
            }
            else
            {
                cout<<"***********************************"<<endl;
                cout<<"test length is "<<length+1<<endl;
                if (center_point-(length+1)/2<0){
                    cout<< "Down" <<endl;
                    cout<< "add center_point, from"<< center_point << " to " << center_point+1<<endl;
                    cout<< "test length to 2."<<endl;
                    center_point++;
                    length = 1;
                    continue;
                }
                if (center_point-(length+1)/2+length+1>s.length()){
                    cout<<"top!!!!"<<endl;
                    if (center_point==(s.length()-1)){
                        cout<<"center_point is largest"<<endl;
                        cout<< "center_point:"<<center_point<<" s.length(): "<<s.length()<<endl;
                        return ans;
                    }
                    else{
                        cout<< "add center_point, from"<< center_point << " to " << center_point+1<<endl;
                        cout<< "test length to 2."<<endl;
                        center_point++;
                        length = 1;
                        continue;
                    }
                    
                }
                cout<<"test str:"<< s.substr(center_point-(length+1)/2, length+1)<<endl;
                odd = PalindromeTest(s.substr(center_point-(length+1)/2, length+1));
                if (odd){
                    cout<<"test str is ok"<<endl;
                    if (max_length<length+1){
                        cout<<"max_length<length change max_length to "<<length<<endl;
                        ans = s.substr(center_point-(length+1)/2, length+1);
                        max_length = length;
                    }
                    
                }
                else
                {
                    cout<<"test str is not ok"<<endl;
                }
                cout<<"add length to " << length+1<<endl;
                length++;
              
            }
            if (odd==false && even == false){
                odd = true;
                even = true;
                cout<< "odd==false && even == false, add center_point from "<<center_point<<" to "<<center_point+1<<endl;
                center_point++;
                length=1;
                continue;
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
    s = "caba";
    string ans = "aba";

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

