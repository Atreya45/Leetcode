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
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head||!(head->next)||!k){
            return head;
        }
        int len=0;
        ListNode* lenCal=head;
        while(lenCal->next){
            lenCal=lenCal->next;
            len++;
        }
        len++;
        lenCal->next=head;
        k=k%len;
        int stepsToNewTail = len - k;
        ListNode* newTail = head;
        for (int i = 1; i < stepsToNewTail; ++i) {
            newTail = newTail->next;
        }
        head=newTail->next;
        newTail->next=NULL;
        return head;
    }
};