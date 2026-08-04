class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mpp;
        int longest = 0;

        for (int num : nums) {

            if (mpp[num])
                continue;      // Skip duplicates

            int left = mpp[num - 1];
            int right = mpp[num + 1];

            int len = left + right + 1;

            mpp[num] = len;
            mpp[num - left] = len;
            mpp[num + right] = len;

            longest = max(longest, len);
        }

        return longest;
    }
};