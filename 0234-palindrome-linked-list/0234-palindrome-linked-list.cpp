/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    bool rec(ListNode* head,ListNode* &curr){
        if(!head){
            return true;
        }
        bool ans=rec(head->next,curr);
        if(head->val!=curr->val){
            return false;
        }
        curr=curr->next;
        return ans;
    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode* curr=head;
        return rec(head,curr);
    }
};