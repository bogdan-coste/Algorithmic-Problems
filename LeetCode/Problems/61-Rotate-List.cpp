#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if (!head || !head->next || k == 0) return head;

        ListNode* tailNode = head;
        int cnt = 1;
        while (tailNode->next) {
            tailNode = tailNode -> next;
            cnt++;
        }

        tailNode->next = head;

        k = k % cnt;

        ListNode* newTail = head;
        int times = cnt - k - 1;

        while (times > 0) {
            newTail = newTail -> next;
            times--;
        }

        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};
