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

        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr != NULL) {
            ListNode* temp = curr->next;

            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        return prev;
    }

public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return true;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* part2 = slow->next;
        slow->next = NULL;
        slow = head;

        ListNode* part2reversed = reverseLL(part2);

        while (slow != NULL && part2reversed != NULL) {
            if (slow->val != part2reversed->val)
                return false;
            slow = slow->next;
            part2reversed = part2reversed->next;
        }

        return true;
    }
};