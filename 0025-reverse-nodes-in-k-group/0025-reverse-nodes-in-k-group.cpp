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
    ListNode* reverseLinkedList(ListNode* head) {

        ListNode* temp = head;

        ListNode* prev = NULL;

        while (temp != NULL) {

            ListNode* front = temp->next;

            temp->next = prev;

            prev = temp;

            temp = front;
        }

        return prev;
    }

    ListNode* getkthNode(ListNode* temp, int k) {

        k -= 1;
        while (temp != NULL && k > 0) {
            k--;

            temp = temp->next;
        }

        return temp;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevLast = NULL;
        int cnt = 0;
        while (temp) {
            ListNode* kthNode = getkthNode(temp, k);
            if (!kthNode) {
                prevLast->next = temp;
                break;
            }
            ListNode* nextNode = kthNode->next;
            kthNode->next = NULL;
            reverseLinkedList(temp);
            if (cnt == 0) {
                head = kthNode;
            } else {
                prevLast->next = kthNode;
            }
            prevLast = temp;
            temp = nextNode;
            cnt++;
        }
        return head;
    }
};