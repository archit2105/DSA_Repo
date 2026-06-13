/**
 * Problem: Search Insert Position (LeetCode 35)
 * URL: https://leetcode.com/problems/search-insert-position/
 * * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size() - 1;
        int possibleInd = nums.size(); // safer default

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (nums[mid] == target) {
                return mid;
            } 
            else if (nums[mid] < target) {
                s = mid + 1;
            } 
            else {
                possibleInd = mid;
                e = mid - 1;
            }
        }

        return possibleInd;
    }
};

int main() {
    Solution solution;

    // Test Case 1: Target is found in the array
    vector<int> nums1 = {1, 3, 5, 6};
    int target1 = 5;
    int result1 = solution.searchInsert(nums1, target1);
    cout << "Test Case 1 - Expected: 2, Got: " << result1 << endl;

    // Test Case 2: Target is not found, needs to be inserted in the middle
    vector<int> nums2 = {1, 3, 5, 6};
    int target2 = 2;
    int result2 = solution.searchInsert(nums2, target2);
    cout << "Test Case 2 - Expected: 1, Got: " << result2 << endl;

    // Test Case 3: Target is not found, needs to be inserted at the end
    vector<int> nums3 = {1, 3, 5, 6};
    int target3 = 7;
    int result3 = solution.searchInsert(nums3, target3);
    cout << "Test Case 3 - Expected: 4, Got: " << result3 << endl;

    return 0;
}