/**
 * Problem: Binary Search (LeetCode 704)
 * URL: https://leetcode.com/problems/binary-search/
 * * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
       int s = 0;
       int e = nums.size() - 1;
       
       while (s <= e) {
            int mid = s + (e - s) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] > target) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
       } 
       return -1;
    }
};

int main() {
    Solution solution;

    // Test Case 1: Target exists in the array
    vector<int> nums1 = {-1, 0, 3, 5, 9, 12};
    int target1 = 9;
    int result1 = solution.search(nums1, target1);
    cout << "Test Case 1 - Expected: 4, Got: " << result1 << endl;

    // Test Case 2: Target does not exist in the array
    vector<int> nums2 = {-1, 0, 3, 5, 9, 12};
    int target2 = 2;
    int result2 = solution.search(nums2, target2);
    cout << "Test Case 2 - Expected: -1, Got: " << result2 << endl;

    return 0;
}