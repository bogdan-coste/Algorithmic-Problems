class MedianFinder {
    std::vector<int> low;
    std::vector<int> high;

public:
    MedianFinder() {
        low.reserve(50000);
        high.reserve(50000);
    }

    inline void addNum(int num) {
        if (low.empty() || num <= low.front()) {
            low.push_back(num);
            std::push_heap(low.begin(), low.end());
        } else {
            high.push_back(num);
            std::push_heap(high.begin(), high.end(), std::greater<int>());
        }

        if (low.size() > high.size() + 1) {
            high.push_back(low.front());
            std::push_heap(high.begin(), high.end(), std::greater<int>());

            std::pop_heap(low.begin(), low.end());
            low.pop_back();
        } else if (high.size() > low.size()) {
            low.push_back(high.front());
            std::push_heap(low.begin(), low.end());

            std::pop_heap(high.begin(), high.end(), std::greater<int>());
            high.pop_back();
        }
    }

    inline double findMedian() {
        if (low.size() > high.size()) {
            return low.front();
        }
        return (low.front() + high.front()) / 2.0;
    }
};
