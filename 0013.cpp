class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> lookup;
        lookup['I'] = 1;
        lookup['V'] = 5;
        lookup['X'] = 10;
        lookup['L'] = 50;
        lookup['C'] = 100;
        lookup['D'] = 500;
        lookup['M'] = 1000;

        if (s.size() == 1) {
            return lookup[s[0]];
        }

        int sum = 0;
        for (size_t i = 0; i < s.size() - 1; i++) {
            if (lookup[s[i]] >= lookup[s[i + 1]]) {
                sum += lookup[s[i]];
            } else if (lookup[s[i]] < lookup[s[i + 1]]) {
                sum += lookup[s[i + 1]] - lookup[s[i]];
                i++;
            }
            if (i == s.size() - 2) {
                sum += lookup[s[i + 1]];
            }
        }

        return sum;
    }
};