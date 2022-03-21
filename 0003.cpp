class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_map<char, int> map_char_to_offset;
        int start = 0;
        int end = 0;
        int max_length = 0;
        while (end < s.size()) {
            char current_char = s[end];
            if (map_char_to_offset.find(current_char) == map_char_to_offset.end()) {
                map_char_to_offset[current_char] = end;
                end++;
            } else {
                int diff = end - start;
                if (diff > max_length) {
                    max_length = diff;
                }

                start = map_char_to_offset[current_char] + 1;
                end = start;
                map_char_to_offset.clear();
            }
        }

        int diff = end - start;
        if (diff > max_length) {
            max_length = diff;
        }

        return max_length;
    }
};