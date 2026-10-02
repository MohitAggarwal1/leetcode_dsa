class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers are not palindromes
        if (x < 0) {
            return false;
        }
        
        long long rev = 0; // Use long long to prevent integer overflow
        int num = x;
        
        while (num != 0) {
            rev = rev * 10 + num % 10;
            num = num / 10;
        }
        
        return (rev == x);
    }
};
