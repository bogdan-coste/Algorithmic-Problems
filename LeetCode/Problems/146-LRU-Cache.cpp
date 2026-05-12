#include <iostream>
#include <unordered_map>

class LRUCache {

private:

    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;
        Node(int key_, int value_) : key(key_), value(value_), prev(nullptr), next(nullptr) {};
    };

    int capacity;
    std::unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;

    void addToFront(Node* newNode) {
        newNode->next = tail;
        newNode->prev = tail->prev;
        tail->prev->next = newNode;
        tail->prev = newNode;
    }

    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveToFront(Node* node) {
        remove(node);
        addToFront(node);
    }

    Node* popTail() {
        Node* lru = head->next;
        remove(lru);
        return lru;
    }
public:

    LRUCache(int _capacity) : capacity(_capacity) {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    ~LRUCache() {
        Node* curr = head;
        while (curr->next) {
            curr = curr->next;
            delete curr->prev;
        }
        delete curr;
    }

    int get(int key) {
        auto it = cache.find(key);

        if (it == cache.end()) {
            return -1;
        }

        Node* node = it->second;

        moveToFront(node);
        return node->value;
    }

    void put(int key, int value) {
        auto it = cache.find(key);
        if (it != cache.end()) {
            Node* node = it->second;
            node->value = value;
            moveToFront(node);
        }else {

            Node* newNode = new Node(key, value);
            cache.emplace(key, newNode);
            addToFront(newNode);

            if (cache.size() > capacity) {
                Node* lru = popTail();
                cache.erase(lru->key);
                delete lru;
            }
        }
    }
};

