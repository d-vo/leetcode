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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int carryover = 0;

        ListNode *first = nullptr;
        ListNode *current = nullptr;
        while (true) {
            if (!l1 and !l2 and carryover == 0) {
                break;
            }

            int val1 = l1 ? l1->val : 0;
            int val2 = l2 ? l2->val : 0;

            int sum = val1 + val2 + carryover;

            carryover = 0;
            if (sum > 9) {
                carryover = 1;
                sum -= 10;
            }

            if (current) {
                current->next = new ListNode(sum);
                current = current->next;
            } else {
                current = new ListNode(sum);
                first = current;
            }


            if (l1) {
                l1 = l1->next;
            }

            if (l2) {
                l2 = l2->next;
            }
        }
        return first;
    }
};