/**
 * Problem: Two Sum (LeetCode 1)
 * URL: https://leetcode.com/problems/two-sum/
 * * Approach 1 (Two-Pointer): Time Complexity: O(n log n), Space Complexity: O(1)
 * -> Used when we only need to verify if a valid pair EXISTS.
 * * Approach 2 (Hash Map):     Time Complexity: O(n),     Space Complexity: O(n)
 * -> Required when we need to return the ORIGINAL indices of the numbers.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // Approach 1: Two-Pointer Approach
    // Note: Passed by value (vector<int> nums) instead of reference because sorting 
    // mutates the array. Passing by value creates a local copy, leaving main's array intact.
    bool hasTwoSum(vector<int> nums, int target) {
        // Step 1: Sort the array to use the two-pointer property
        sort(nums.begin(), nums.end());
        
        int i = 0;                  // Left pointer starting at the smallest element
        int j = nums.size() - 1;    // Right pointer starting at the largest element
        
        while (i < j) {
            int currentSum = nums[i] + nums[j];
            
            // Case 1: Found the target pair
            if (currentSum == target) {
                return true;
            }
            // Case 2: Sum is too small -> move left pointer rightward to get a larger value
            else if (currentSum < target) {
                i++;
            } 
            // Case 3: Sum is too big -> move right pointer leftward to get a smaller value
            else {
                j--;
            }
        }
        // No pair found that adds up to the target
        return false;
    }

    // Approach 2: Hash Map Approach (One-Pass)
    vector<int> twoSum(vector<int>& nums, int target) {
        // Map to store: Key = Number itself, Value = Its original index in the array
        unordered_map<int, int> mp; 
        
        for (int i = 0; i < nums.size(); i++) {
            int a = nums[i];          // Current element
            int more = target - a;    // Complement needed to reach the target (a + more = target)

            // Look up if the required complement ('more') has already been seen in the map
            if (mp.find(more) != mp.end()) {
                // If found, return the index of the complement and the current index
                return {mp[more], i};
            }
            
            // If not found, store the current element and its index for future lookups
            mp[a] = i;
        }
        // Return default fallback if no solution exists
        return {-1, -1};
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    cout << "--- Testing Approach 1: Two-Pointer (Existence Check) ---" << endl;
    bool exists = solution.hasTwoSum(nums, target);
    cout << "Pair exists? (1 for Yes, 0 for No): " << exists << endl;

    cout << "\n--- Testing Approach 2: Hash Map (Index Retrieval) ---" << endl;
    vector<int> indices = solution.twoSum(nums, target);
    cout << "Indices - Expected: [0, 1], Got: [" << indices[0] << ", " << indices[1] << "]" << endl;

    return 0;
}

/* ============================================================================
 * DRY RUN DOCUMENTATION
 * ============================================================================
 *
 * Input: nums = {2, 7, 11, 15}, target = 9
 *
 * ----------------------------------------------------------------------------
 * DRY RUN: APPROACH 1 (Two-Pointer)
 * ----------------------------------------------------------------------------
 * 1. Array is sorted: [2, 7, 11, 15] (Already sorted in this case)
 * 2. Initialize pointers: i = 0 (val = 2), j = 3 (val = 15)
 * * Loop Iteration 1:
 * - currentSum = nums[i] + nums[j] -> 2 + 15 = 17
 * - Check: Is 17 == 9? No.
 * - Check: Is 17 < 9? No.
 * - Else (17 > 9): Sum is too large. Decrement right pointer to reduce sum.
 * - j updates to 2.
 * * Loop Iteration 2:
 * - i = 0 (val = 2), j = 2 (val = 11)
 * - currentSum = 2 + 11 = 13
 * - 13 > 9 -> Decrement right pointer.
 * - j updates to 1.
 * * Loop Iteration 3:
 * - i = 0 (val = 2), j = 1 (val = 7)
 * - currentSum = 2 + 7 = 9
 * - 9 == 9 -> Target found! Returns TRUE.
 *
 * ----------------------------------------------------------------------------
 * DRY RUN: APPROACH 2 (Hash Map / One-Pass)
 * ----------------------------------------------------------------------------
 * Map state initialized as empty: {}
 *
 * Iteration i = 0:
 * - a = nums[0] = 2
 * - more = target - a -> 9 - 2 = 7
 * - Search: Is 7 present in map? No.
 * - Action: Insert current element into map -> mp[2] = 0
 * - Map State: { 2: 0 }
 *
 * Iteration i = 1:
 * - a = nums[1] = 7
 * - more = target - a -> 9 - 7 = 2
 * - Search: Is 2 present in map? YES! (At index 0)
 * - Action: Match found. Return indices {mp[2], i} -> {0, 1}
 * - Execution finishes instantly.
 * ============================================================================
 */