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
    ListNode* mergeTwoLists(ListNode* left, ListNode* right) {
        if (!left) {
            return right;
        }
        if (!right) {
            return left;
        }
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;
        while (left && right) {
            if (left->val < right->val) {
                temp->next = left;
                temp = left;
                left = left->next;
            } else {
                temp->next = right;
                temp = right;
                right = right->next;
            }
        }
        if (right) {
            temp->next = right;
        }
        if (left) {
            temp->next = left;
        }
        return dummyNode->next;
    }

    ListNode* findMiddle(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast  && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

public:
    ListNode* sortList(ListNode* head) {
        if (!head || !(head->next)) {
            return head;
        }
        ListNode* middle = findMiddle(head);
        ListNode* right = middle->next;
        ListNode* left = head;
        middle->next = NULL;
        left = sortList(left);
        right = sortList(right);
        return mergeTwoLists(left, right);
    }
};