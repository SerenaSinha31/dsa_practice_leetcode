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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head; // Edge cases
        
        ListNode dummy(0);
        dummy.next = head;
        ListNode* pre = &dummy;
        
        // Move `pre` to the node immediately before the sublist
        for (int i = 1; i < left; ++i) {
            pre = pre->next;
        }
        
        // Start reversing from `left` to `right`
        ListNode* current = pre->next;
        for (int i = 0; i < right - left; ++i) {
            ListNode* temp = current->next;
            current->next = temp->next;
            temp->next = pre->next;
            pre->next = temp;
        }
        
        return dummy.next;
    }
};