class Solution {
public:
    bool hasValidPath(auto& A) {
        int m = A.size(), n = A[0].size();

        if ((m + n - 1) & 1 || (A[0][0] & 1))
            return 0;

        vector dp(m + 1, vector<bitset<102>>(n + 1));
        dp[0][0].set(0);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                auto b = (dp[i][j] << 1) >> ((A[i][j] & 1) << 1);

                dp[i + 1][j] |= b;
                dp[i][j + 1] |= b;
            }
        }

        return dp[m][n - 1].test(0);
    }
};