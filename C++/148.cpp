#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <map>
#include <deque>
#include <queue>
#include <functional>
using namespace std;

struct ListNode {
    int val;
    ListNodenext;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == NULL) {
            return head;
        }
        priority_queue<int, vector<int>, greater<int>> p;
        ListNode* oriHead = head;
        do {
            p.push(head->val);
            head = head->next;
        } while(head!=NULL);
        head = oriHead;
        do {
            head->val = p.top();
            p.pop();
            head = head->next;
        } while(head!=NULL);
        return oriHead;
    }
};