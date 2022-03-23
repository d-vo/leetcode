class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        if (x == 0) {
            return true;
        }

        // Assemble number other way round
        size_t orig_x = x;
        size_t inv_x = 0;
        while (x > 0) {
            int last_number = x % 10;
            inv_x = 10 * inv_x + last_number;
            x /= 10;
        }

        if (inv_x == orig_x) {
            return true;
        }
        return false;
    }
};