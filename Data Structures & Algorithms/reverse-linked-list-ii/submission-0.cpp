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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == NULL || head->next == NULL)
            return head;

        if (left == right)
            return head;

        ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = head;
        ListNode* leftEnd = dummyHead;
        ListNode* rightEnd = dummyHead;

        for (int i = 1; i < left; i++)
            leftEnd = leftEnd->next;
        for (int i = 1; i < right + 1; i++)
            rightEnd = rightEnd->next;

        ListNode* leftStart = leftEnd->next;
        ListNode* rightStart = rightEnd->next;

        leftEnd->next = NULL;
        rightEnd->next = NULL;

        leftEnd->next = reverseLL(leftStart);
        leftStart->next = rightStart;
        return dummyHead->next;
    }
};