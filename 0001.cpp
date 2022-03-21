class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        std::unordered_map<int, int> map_diff_to_idx;
        for (int idx = 0; idx < nums.size(); idx++) {
            int diff = target - nums[idx];
            if (map_diff_to_idx.find(diff) != map_diff_to_idx.end()) {
                return std::vector < int > {idx, map_diff_to_idx[diff]};
            }
            map_diff_to_idx[nums[idx]] = idx;
        }
        return std::vector<int>();
    }
};