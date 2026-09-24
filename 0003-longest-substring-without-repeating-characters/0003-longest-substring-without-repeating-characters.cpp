class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;
        int left = 0;
        unordered_map<char, int> count;

        for (int right = 0; right < s.length(); right++) {
            char c = s[right];
            count[c] = count[c] + 1;
            
            while (count[c] > 1) {
                char leftChar = s[left];
                count[leftChar] = count[leftChar] - 1;
                left++;
            }
            
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;        
    }
};