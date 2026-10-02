class Solution {
public:
    void solve(int open, int close, string curr, vector<string>& ans) {
        // If all brackets are used
        if (open == 0 && close == 0) {
            ans.push_back(curr);
            return;
        }

        // Add '(' if available
        if (open > 0) {
            solve(open - 1, close, curr + "(", ans);
        }

        // Add ')' only when there is an unmatched '('
        if (close > open) {
            solve(open, close - 1, curr + ")", ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        solve(n, n, "", ans);

        return ans;
    }
};