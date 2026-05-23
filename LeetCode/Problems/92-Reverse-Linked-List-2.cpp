#include <iostream>
#include <ostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    static ListNode* reverseBetween(ListNode* head, int left, int right) {

        auto* dummy = new ListNode(0, head);

        auto* prevNode = dummy;
        auto* currNode = dummy -> next;

        for (int i = 0; i < left - 1; i++) {
            prevNode = prevNode -> next;
            currNode = currNode -> next;
        }

        ListNode* sequenceFirstNode = currNode;
        ListNode* prevNodeBkp = nullptr;

        for (int i = 0; i < right - left + 1; i++) {
            ListNode* following = currNode -> next;
            currNode -> next = prevNodeBkp;
            prevNodeBkp = currNode;
            currNode = following;
        }

        prevNode -> next = prevNodeBkp;
        sequenceFirstNode -> next = currNode;

        return dummy -> next;
    }
};

int main() {
    auto* tail = new ListNode(5);
    auto* node4 = new ListNode(4, tail);
    auto* node3 = new ListNode(3, node4);
    auto* node2 = new ListNode(2, node3);
    auto* node1 = new ListNode(1, node2);
    auto* head = new ListNode(0, node1);

    ListNode* newHead = Solution::reverseBetween(head, 2, 4);

    ListNode* current = newHead;
    while (current) {
        std::cout << current->val << std::endl;
        current = current->next;
    }

    while (newHead) {
        ListNode* next = newHead->next;
        delete newHead;
        newHead = next;
    }

    return 0;
}
