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

    ListNode* partition(ListNode* head, int x) {

        auto* lessHead = new ListNode(0);
        auto* greaterHead = new ListNode(0);

        ListNode* less = lessHead;
        ListNode* greater = greaterHead;

        while (head) {

            if (head->val < x) {
                less -> next = head;
                less = less -> next;
            } else {
                greater -> next = head;
                greater = greater -> next;
            }

            head = head -> next;
        }

        greater -> next = nullptr;
        less -> next = greaterHead -> next;

        ListNode* result = lessHead -> next;
        delete lessHead;
        delete greaterHead;

        return result;
    }


};

