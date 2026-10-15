class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size(),id{};
        int sum{};
        vector<int> fr(101);
        for (int l = 0; l < n; l++) {
            int cnt{};
            id++;
            for (int r = l; r < n; r++) {
                cnt += (fr[nums[r]] != id);
                fr[nums[r]] = id;
                sum += pow(cnt, 2);
            }
        }
        return sum;
    }
};