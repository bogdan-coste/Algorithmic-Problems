#include <vector>
#include <queue>

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        
      auto cmp = [](ListNode* a, ListNode* b){return a -> val > b -> val;};
      std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(cmp)> pq(cmp);

      for(ListNode* head: lists){
        if(head){
          pq.push(head);
        }
      }

      ListNode dummy(0);
      ListNode* tail = &dummy;

      while(!pq.empty()){
        ListNode* smallest = pq.top();
        pq.pop();
        tail -> next = smallest;
        tail = tail -> next;
        if(smallest -> next){
          pq.push(smallest -> next);
        }
      }

      return dummy.next;
    }
};

int main() {

  return 0;
}
