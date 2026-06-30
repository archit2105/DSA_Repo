class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> ans;
        for(int i =0;i<n;i++){
            for(int j = i+1;j<n;j++){
                set<long long> st;
                for(int k = j+1;k<n;k++){
                    long long sum = nums[i] + nums[j];
                    sum +=nums[k];
                    long long more = target - sum;
                    if(st.find(more) != st.end()){
                        vector<int> temp = {nums[i],nums[j],nums[k],static_cast<int>(more)};
                        sort(temp.begin(),temp.end());
                        ans.insert(temp);
                    }
                    st.insert(nums[k]);
                }
            }
        } vector<vector<int>> final(ans.begin(),ans.end());
        return final;
    }
};