class Solution {
public:
    
    bool validPalindromeHelper (string &s, int left, int right, bool chanceRemaining) {
        while (left < right) {
            if (s[left] == s[right]) {
                left ++;
                right --;
            }
            else if (chanceRemaining) {
                return validPalindromeHelper(s, left+1, right, false) || validPalindromeHelper(s, left, right-1, false);
            }
            else {
                return false;
            }
        }
        return true;
    }

    bool validPalindrome(string s) {
        return validPalindromeHelper(s, 0, s.size() - 1, true);
    }
};