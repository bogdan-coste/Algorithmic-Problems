#include <iostream>
#include <vector>

bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
    int left = 0;
    int right = matrix[0].size() * matrix.size() - 1;

    int nCols = matrix[0].size();

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (matrix[mid / nCols][mid % nCols] == target) {
            return true;
        }

        if (matrix[mid / nCols][mid % nCols] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return false;
}

int main() {
    std::vector<std::vector<int>> nums1 = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 13;
    std::cout << searchMatrix(nums1, target);
}
