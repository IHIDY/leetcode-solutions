// 2461. Maximum Sum of Distinct Subarrays With Length K
// Sliding window: add nums[i], remove nums[i - k], check when the window is full.
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0, sum = 0;
        unordered_map<int, int> cnt;

        for (int i = 0; i < nums.size(); i++) {
            cnt[nums[i]]++;
            sum += nums[i];

            if (i >= k) {
                int out = nums[i - k];
                if (--cnt[out] == 0) cnt.erase(out);
                sum -= out;
            }

            if (i >= k - 1 && cnt.size() == k) {
                ans = max(ans, sum);
            }
        }
        return ans;
    }
};
