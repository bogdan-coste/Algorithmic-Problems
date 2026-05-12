#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x_) : val(x_), next(nullptr) {};
    ListNode(int x_, ListNode* next_) : val(x_), next(next_) {};
};

class Solution {

public:

    ListNode* deleteDuplicates(ListNode* head) {

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        ListNode* curr = head;

        while (curr) {

            if (curr -> next && curr -> val == curr -> next->val) {

                while (curr -> next && curr -> val == curr -> next -> val) {
                    curr = curr -> next;
                }

                prev -> next = curr -> next;
            } else {
                prev = prev -> next;

            }

            curr = curr -> next;
        }

        return dummy.next;
    }

};

