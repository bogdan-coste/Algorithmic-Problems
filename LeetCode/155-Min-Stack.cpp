#ifndef UNTERMEHMEN_GEHEIMANTWORT_STACK_HPP
#define UNTERMEHMEN_GEHEIMANTWORT_STACK_HPP

#include <optional>
#include <set>
#include <vector>

class MinStack {
public:

    std::vector<int> data;
    std::vector<int> minStack;

    MinStack() {};

    void push(int val) {
        data.push_back(val);

        if (minStack.empty() || val <= minStack.back()) {
            minStack.push_back(val);
        }
    }

    void pop() {

        if (data.back() == minStack.back()) {
            minStack.pop_back();
        }

        data.pop_back();
    }

    int top() const {
        return data.back();
    }

    int getMin() {

        return minStack.back();
    }

};

#endif //UNTERMEHMEN_GEHEIMANTWORT_STACK_HPP
