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

    ListNode* reverseLL(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode* newHead = reverseLL(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }

public:
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* part2 = slow->next;
        slow->next = NULL;

        ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = head;

        ListNode* curr = dummyHead;
        ListNode* temp1 = head;
        ListNode* temp2 = reverseLL(part2);

        bool flag = false;

        while (temp1 != NULL && temp2 != NULL) {
            if (!flag) {
                curr->next = temp1;
                curr = temp1;
                temp1 = temp1->next;
                flag = true;
            } else {
                curr->next = temp2;
                curr = temp2;
                temp2 = temp2->next;
                flag = false;
            }
        }

        while (temp1 != NULL) {
            if (!flag) {
                curr->next = temp1;
                curr = temp1;
                temp1 = temp1->next;
                flag = true;
            }
        }

        while (temp2 != NULL) {
            if (flag) {
                curr->next = temp2;
                curr = temp2;
                temp2 = temp2->next;
                flag = false;
            }
        }
    }
};