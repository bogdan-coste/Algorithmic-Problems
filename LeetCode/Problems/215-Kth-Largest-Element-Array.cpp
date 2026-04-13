#include <algorithm>   // std::swap, std::ranges::nth_element
#include <iostream>    // (optional) for debugging
#include <vector>      // std::vector
#include <cstdlib>     // rand(), srand() – used in manual quickselect

/**
 * @brief Collection of algorithms to find the k-th largest element in an array.
 *
 * Three approaches are implemented:
 * 1. Manual Quickselect (with random pivot) – demonstrates understanding of the algorithm.
 * 2. std::ranges::nth_element (C++20) – production‑ready, O(n) average.
 * 3. Counting sort – fastest when integer values lie in a small known range.
 *
 * All methods assume 1‑based k (e.g., k=1 → largest element).
 */
class QuickSelect {
private:
    /**
     * @brief Partitions the subarray [left, right] around a pivot.
     *        All elements greater than the pivot are moved to the left side.
     *        Used for finding the k-th largest (descending order partition).
     *
     * @param nums  The vector (modified in‑place).
     * @param left  Left index (inclusive).
     * @param right Right index (inclusive) – pivot is initially at nums[right].
     * @return int  Final index of the pivot after partitioning.
     *
     * @note After partition:
     *       - indices [left, i-1] contain values > pivot
     *       - index i contains the pivot
     *       - indices [i+1, right] contain values <= pivot
     */
    int partition(std::vector<int>& nums, int left, int right) {
        int pivot = nums[right];
        int i = left;   // marks the boundary of the "greater than pivot" region

        for (int j = left; j < right; ++j) {
            if (nums[j] > pivot) {                 // want larger elements on the left
                std::swap(nums[i], nums[j]);
                ++i;
            }
        }
        std::swap(nums[right], nums[i]);            // place pivot in its final position
        return i;
    }

public:
    /**
     * @brief Manual implementation of Quickselect (recursive, random pivot).
     *        Expected O(n) time, worst‑case O(n²) but randomisation makes it unlikely.
     *        Space: O(log n) due to recursion.
     *
     * @param nums  Vector of integers (modified in‑place).
     * @param left  Left bound of current search range (inclusive).
     * @param right Right bound (inclusive).
     * @param k     0‑based index of the desired element (k-th largest, 0‑based).
     * @return int  The k-th largest element.
     *
     * @note Caller must convert 1‑based k to 0‑based before calling.
     * @note For real usage, prefer solveDefined() which uses std::ranges::nth_element.
     */
    int solve(std::vector<int>& nums, int left, int right, int k) {
        // Base case: only one element left
        if (left == right) {
            return nums[left];
        }

        // Random pivot selection – avoids worst‑case O(n²) on sorted input
        // For better randomness, consider using std::mt19937, but rand() is simpler.
        int randomIdx = left + rand() % (right - left + 1);
        std::swap(nums[randomIdx], nums[right]);   // move pivot to the end

        int pivotIdx = partition(nums, left, right);

        if (pivotIdx == k) {
            return nums[pivotIdx];
        } else if (pivotIdx < k) {
            // k-th largest lies to the right (elements <= pivot)
            return solve(nums, pivotIdx + 1, right, k);
        } else {
            // k-th largest lies to the left (elements > pivot)
            return solve(nums, left, pivotIdx - 1, k);
        }
    }

    /**
     * @brief Uses std::ranges::nth_element (C++20) to find the k-th largest.
     *        This is the recommended production solution.
     *
     * @param nums Vector of integers (modified in‑place).
     * @param k    1‑based k (e.g., k=1 → largest).
     * @return int The k-th largest element.
     *
     * @tparam Uses default ascending order comparator (std::less).
     *         The nth element is placed at index (size - k).
     *
     * @note Complexity: average O(n), guaranteed O(n) in practice (introselect).
     * @note If C++20 is not available, replace with std::nth_element (same signature).
     */
    int solveDefined(std::vector<int>& nums, int k) {
        int n = nums.size();
        // nth_element partially sorts so that the element at position (n - k)
        // is the k-th largest when sorted in ascending order.
        std::ranges::nth_element(nums.begin(), nums.begin() + n - k, nums.end());
        return nums[n - k];
    }
};

/**
 * @brief Counting sort solution for the k-th largest element.
 *        Works only because the problem guarantees -10^4 <= nums[i] <= 10^4.
 *        Extremely fast: O(n + R) where R = 20001, no recursion, perfect cache locality.
 *
 * @param nums Vector of integers (read‑only, not modified).
 * @param k    1‑based k (e.g., k=1 → largest).
 * @return int The k-th largest element.
 *
 * @note Time complexity: O(n + 20001) ≈ O(n) with a very small constant.
 * @note Space complexity: O(20001) ≈ 80 KB (for int array) – negligible.
 * @note Edge case: k is assumed to be valid (1 ≤ k ≤ nums.size()).
 */
int usingCountSort(std::vector<int>& nums, int k) {
    // Range of possible values: from -10000 to 10000 inclusive → 20001 distinct values.
    // We shift by +10000 to map -10000 → 0, 10000 → 20000.
    std::vector<int> countSort(20001, 0);   // value‑initialized to zero

    // Count frequencies
    for (int num : nums) {
        countSort[num + 10000]++;
    }

    // Traverse from largest value (index 20000) down to smallest (0).
    // Decrement k by the frequency of each value; when k <= 0, we have found the k-th largest.
    for (int i = 20000; i >= 0; --i) {
        k -= countSort[i];
        if (k <= 0) {
            return i - 10000;   // convert index back to original value
        }
    }

    return -1;   // should never be reached for valid input (defensive return)
}

int main() {
    std::vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;   // want 2nd largest → 5

    // Method 1: manual quickselect (requires seeding rand() once)
    srand(time(nullptr));
    QuickSelect qs;
    int ans1 = qs.solve(nums, 0, nums.size() - 1, k - 1);  // convert to 0‑based
    std::cout << "Manual quickselect: " << ans1 << std::endl;

    // Method 2: std::ranges::nth_element (C++20)
    // Note: solveDefined modifies nums; make a copy if needed.
    std::vector<int> nums2 = {3, 2, 1, 5, 6, 4};
    int ans2 = qs.solveDefined(nums2, k);
    std::cout << "std::nth_element: " << ans2 << std::endl;

    // Method 3: counting sort
    std::vector<int> nums3 = {3, 2, 1, 5, 6, 4};
    int ans3 = usingCountSort(nums3, k);
    std::cout << "Counting sort: " << ans3 << std::endl;

    return 0;
}
