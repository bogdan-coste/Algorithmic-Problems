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
    static ListNode* reverse(ListNode* head) {

        ListNode* prevNode = nullptr;
        ListNode* current = head;

        while (current) {
            ListNode* following = current -> next;
            current -> next = prevNode;
            prevNode = current;
            current = following;
        }

        return prevNode;
    }
};

int main() {
    auto* tail = new ListNode(5);
    auto* node4 = new ListNode(4, tail);
    auto* node3 = new ListNode(3, node4);
    auto* node2 = new ListNode(2, node3);
    auto* node1 = new ListNode(1, node2);
    auto* head = new ListNode(0, node1);

    ListNode* newHead = Solution::reverse(head);

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
