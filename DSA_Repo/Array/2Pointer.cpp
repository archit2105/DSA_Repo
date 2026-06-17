/**
 * Problem: Two Sum (LeetCode 1)
 * URL: https://leetcode.com/problems/two-sum/
 * * Approach 1 (Two-Pointer): Time Complexity: O(n log n), Space Complexity: O(1) [If we just need to check existence]
 * Approach 2 (Hash Map):     Time Complexity: O(n),     Space Complexity: O(n) [Required to return original indices]
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // Approach 1: Two-Pointer Approach (Only works for checking existence, as sorting destroys original indices)
    bool hasTwoSum(vector<int> nums, int target) { // Passed by value so we don't mutate the original array in main
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = nums.size() - 1;
        
        while (i < j) {
            if (nums[i] + nums[j] == target) {
                return true;
            }
            if (nums[i] + nums[j] < target) {
                i++;
            } else {
                j--;
            }
        }
        return false;
    }

    // Approach 2: Hash Map Approach (Tracks original indices perfectly)
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp; // Using unordered_map for O(1) average lookup
        for (int i = 0; i < nums.size(); i++) {
            int a = nums[i];
            int more = target - a;

            if (mp.find(more) != mp.end()) {
                return {mp[more], i};
            }
            mp[a] = i;
        }
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