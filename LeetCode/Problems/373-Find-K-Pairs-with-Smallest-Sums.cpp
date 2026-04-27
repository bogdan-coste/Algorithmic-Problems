#pragma GCC optimize("O3", "unroll-loops")

#include <iostream>
#include <vector>
#include <algorithm>

struct Element {
    int sum;
    int i;
    int j;
};

class Solution {
public:
    std::vector<std::vector<int>> kSmallestPairs(std::vector<int>& nums1, std::vector<int>& nums2, int k) {
        std::vector<Element> heap;
        std::vector<std::vector<int>> res;

        const int n1 = nums1.size();
        const int n2 = nums2.size();
        const int minimalDist = std::min(k, n1);

        res.reserve(k);
        heap.reserve(minimalDist);

        auto comp = [](const Element& a, const Element& b) {
            return a.sum > b.sum;
        };
        
        for (int i = 0; i < minimalDist; ++i) {
            heap.push_back({nums1[i] + nums2[0], i, 0});
        }
        std::make_heap(heap.begin(), heap.end(), comp); 

        while (k-- > 0 && !heap.empty()) {
            std::pop_heap(heap.begin(), heap.end(), comp);
            Element he = heap.back();
            heap.pop_back();

            res.push_back({nums1[he.i], nums2[he.j]});

            if (he.j + 1 < n2) { 
                heap.push_back({nums1[he.i] + nums2[he.j + 1], he.i, he.j + 1});
                std::push_heap(heap.begin(), heap.end(), comp);
            }
        }

        return res;
    }
};
