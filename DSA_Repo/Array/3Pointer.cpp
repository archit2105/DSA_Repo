/**
 * Problem: 3Sum (LeetCode 15)
 * URL: https://leetcode.com/problems/three-sum/
 * * Approach 1 (Hashing):     Time Complexity: O(n^2 * log(no. of unique triplets)), Space Complexity: O(n) + O(no. of unique triplets)
 * -> Uses a hashset to find the third element and a sorted set to eliminate duplicate triplets.
 * * Approach 2 (Two-Pointer): Time Complexity: O(n^2 + n log n) -> O(n^2), Space Complexity: O(1) (excluding output)
 * -> Optimal. Sorts the array and skips duplicate elements manually to avoid using a set.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    // Approach 1: Hashing / Better Approach
    vector<vector<int>> threeSumHashing(vector<int>& nums) {
        set<vector<int>> st; // Set to store unique triplets automatically sorted
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            set<int> hashset; // Stores elements between index i and j
            for (int j = i + 1; j < n; j++) {
                // Formula: nums[i] + nums[j] + third = 0 -> third = -(nums[i] + nums[j])
                int third = -(nums[i] + nums[j]);
                
                // If the required third element exists in our hashset, we found a triplet
                if (hashset.find(third) != hashset.end()) {
                    vector<int> temp = {nums[i], nums[j], third};
                    sort(temp.begin(), temp.end()); // Sort to ensure uniqueness in the outer set
                    st.insert(temp);
                }
                // Track the current element for future pairs with element i
                hashset.insert(nums[j]);
            }
        }
        // Convert the set of triplets back to a vector
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }

    // Approach 2: Two-Pointer Approach (Optimal)
    vector<vector<int>> threeSumTwoPointer(vector<int>& nums) {
        // Step 1: Sort the array to unlock the two-pointer technique and easily skip duplicates
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            // Optimization / Duplicate Skip 1: 
            // If the current element is the same as the previous, skip it to avoid duplicate triplets.
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            int j = i + 1;     // Left pointer starting just after i
            int k = n - 1;     // Right pointer starting at the end of the array

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                // Case 1: Sum is too high -> decrement the right pointer to get a smaller value
                if (sum > 0) {
                    --k;
                }
                // Case 2: Sum is too low -> increment the left pointer to get a larger value
                else if (sum < 0) {
                    j++;
                } 
                // Case 3: Sum is exactly 0 -> Triplet found!
                else {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    ans.push_back(temp);
                    
                    // Move both pointers inward
                    j++;
                    k--;
                    
                    // Duplicate Skip 2: Skip identical elements for 'j' to avoid duplicates
                    while (j < k && nums[j] == nums[j - 1]) j++;
                    // Duplicate Skip 3: Skip identical elements for 'k' to avoid duplicates
                    while (j < k && nums[k] == nums[k + 1]) k--;
                }
            } 
        }
        return ans; 
    }
};

int main() {
    Solution solution;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    cout << "--- Testing Approach 1: Hashing ---" << endl;
    vector<vector<int>> res1 = solution.threeSumHashing(nums);
    for (const auto& triplet : res1) {
        cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "] ";
    }
    cout << endl;

    cout << "\n--- Testing Approach 2: Two-Pointer (Optimal) ---" << endl;
    vector<vector<int>> res2 = solution.threeSumTwoPointer(nums);
    for (const auto& triplet : res2) {
        cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "] ";
    }
    cout << endl;

    return 0;
}

/* ============================================================================
 * DRY RUN DOCUMENTATION
 * ============================================================================
 *
 * Input: nums = {-1, 0, 1, 2, -1, -4}
 *
 * ----------------------------------------------------------------------------
 * DRY RUN: APPROACH 2 (Two-Pointer / Optimal)
 * ----------------------------------------------------------------------------
 * Step 1: Sort the array -> nums = [-4, -1, -1, 0, 1, 2], size n = 6
 *
 * --- Outer Loop i = 0 ---
 * nums[i] = -4
 * Pointers: j = 1 (val = -1), k = 5 (val = 2)
 * * Loop Iteration 1: sum = -4 + (-1) + 2 = -3. Since -3 < 0 -> j++ (j becomes 2)
 * * Loop Iteration 2: j = 2 (val = -1), k = 5 (val = 2). sum = -4 + (-1) + 2 = -3. -> j++ (j becomes 3)
 * * Loop Iteration 3: j = 3 (val = 0), k = 5 (val = 2). sum = -4 + 0 + 2 = -2. -> j++ (j becomes 4)
 * * Loop Iteration 4: j = 4 (val = 1), k = 5 (val = 2). sum = -4 + 1 + 2 = -1. -> j++ (j becomes 5)
 * Loop ends (j is no longer < k). No triplets found with -4.
 *
 * --- Outer Loop i = 1 ---
 * nums[i] = -1
 * Pointers: j = 2 (val = -1), k = 5 (val = 2)
 * * Loop Iteration 1: sum = -1 + (-1) + 2 = 0. TARGET MATCHED!
 * - Action: Push back [-1, -1, 2] to answers.
 * - Move pointers: j++ (becomes 3), k-- (becomes 4).
 * - Duplicate Check for j: nums[3] (0) != nums[2] (-1). No skip.
 * - Duplicate Check for k: nums[4] (1) != nums[5] (2). No skip.
 * * Loop Iteration 2: Current j = 3 (val = 0), k = 4 (val = 1)
 * - sum = -1 + 0 + 1 = 0. TARGET MATCHED!
 * - Action: Push back [-1, 0, 1] to answers.
 * - Move pointers: j++ (becomes 4), k-- (becomes 3).
 * Loop ends (j < k breaks).
 *
 * --- Outer Loop i = 2 ---
 * nums[i] = -1
 * Check: i > 0 and nums[2] == nums[1] (-1 == -1). 
 * Action: SKIP iteration entirely to prevent matching the exact same pairs we just found!
 *
 * --- Outer Loop i = 3 ---
 * nums[i] = 0
 * Pointers: j = 4 (val = 1), k = 5 (val = 2)
 * * Loop Iteration 1: sum = 0 + 1 + 2 = 3. Since 3 > 0 -> k-- (k becomes 4)
 * Loop ends.
 *
 * Remaining elements for i won't have enough elements to form triplets (j < k constraint).
 *
 * Final Result: [[-1, -1, 2], [-1, 0, 1]]
 * ============================================================================
 */