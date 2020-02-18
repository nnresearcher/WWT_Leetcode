#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <functional>
#include <set>
using namespace std;


struct TreeNode {
    int val;
    TreeNodeleft;
    TreeNoderight;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> queueList;
        vector<int> ans;
        queueList.push(root);
        while(!queueList.empty()) {
            TreeNode* tmpTop = queueList.top();
            queueList.pop();
            ans.push_back(tmpTop->val);
            queueList.push(tmpTop->right);
            queueList.push(tmpTop->left);
        }
        return ans;
    }
};