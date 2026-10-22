// For each nums[i], distance to the nearest number whose binary form is a palindrome.
// Precompute all binary palindromes below 2^13, then lower_bound per query.
class Solution {
    static bool isPalindrome(int x) {
        int rev = 0;
        for (int t = x; t; t >>= 1) rev = rev << 1 | (t & 1);
        return rev == x;
    }

public:
    vector<int> minOperations(vector<int>& nums) {
        vector<int> pals;
        for (int i = 1; i < (1 << 13); i++) {
            if (isPalindrome(i)) pals.push_back(i);
        }

        vector<int> ans;
        for (int x : nums) {
            auto it = lower_bound(pals.begin(), pals.end(), x);
            int best = *it - x;
            if (it != pals.begin()) {
                best = min(best, x - *prev(it));
            }
            ans.push_back(best);
        }
        return ans;
    }
};
