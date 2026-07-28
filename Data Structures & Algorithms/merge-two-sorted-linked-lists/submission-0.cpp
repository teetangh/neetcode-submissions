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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == NULL && list2 == NULL)
            return NULL;
        else if (list1 == NULL)
            return list2;
        else if (list2 == NULL)
            return list1;

        ListNode* dummyHead = new ListNode(-1);
        if (list1->val <= list2->val) {
            dummyHead->next = list1;
        } else
            dummyHead->next = list2;
        ListNode* curr = dummyHead;

        while (list1 != NULL && list2 != NULL) {
            if (list1->val <= list2->val) {
                curr->next = list1;
                curr = list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                curr = list2;
                list2 = list2->next;
            }
        }

        while (list1 != NULL) {
            curr->next = list1;
            curr = list1;
            list1 = list1->next;
        }

        while (list2 != NULL) {
            curr->next = list2;
            curr = list2;
            list2 = list2->next;
        }

        return dummyHead->next;
    }
};