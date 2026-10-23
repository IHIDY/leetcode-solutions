// 15. 3Sum
// Sort, fix nums[i], then two pointers on the right side for a pair summing to -nums[i].
// Duplicates are skipped by comparing with the previous element (the array is sorted).
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;

        for (int i = 0; i < n - 2; i++) {
            if (nums[i] > 0) break;                          // smallest is already > 0
            if (i > 0 && nums[i] == nums[i - 1]) continue;   // dedupe first number

            int l = i + 1, r = n - 1;
            while (l < r) {
                int s = nums[i] + nums[l] + nums[r];
                if (s < 0) {
                    l++;
                } else if (s > 0) {
                    r--;
                } else {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    l++, r--;
                    while (l < r && nums[l] == nums[l - 1]) l++;   // dedupe second number
                    while (l < r && nums[r] == nums[r + 1]) r--;   // dedupe third number
                }
            }
        }
        return ans;
    }
};
