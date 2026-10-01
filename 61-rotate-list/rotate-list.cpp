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
    int toSwap = 404;
    int temp = 404;
    ListNode* rotate(ListNode* head, int k) {
        if(k == 0)
            return head;
        ListNode* h = head;
        
        while(h != nullptr) {
            temp = h->val;
            if(toSwap != 404)
                h->val = toSwap;
            toSwap = temp;
            h = h->next;
        }

        head->val = toSwap;
        toSwap = 404;

        return rotate(head, --k);
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr)
            return head;
        int N = 0;
        ListNode* h = head;
        
        while(h != nullptr) {
            N++;
            h = h->next;
        }
        k %= N;
        return rotate(head, k);
    }
};