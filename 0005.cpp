class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0;
        int length = 0;

        if (s.size() == 1) {
            return s;
        }

        for (size_t i = 0; i < s.size(); i++) {
            int left = i;
            int right = i;
            while( s[right] == s[right+1] and right < s.size()-1 ){
                right++;
            }

            while (right<s.size()-1 and left>0 and s[right+1]==s[left-1]){
                right++;
                left--;
            }

            if( right - left +1 > length){
                start = left;
                length = right - left + 1;
            }
        }

        // Second argument is lenght, not end!
        return s.substr(start, length);
    }

};