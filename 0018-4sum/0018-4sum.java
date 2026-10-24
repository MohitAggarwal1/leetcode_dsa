class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> ans = new ArrayList<>();
        int n = nums.length;

        // Sort to use two pointers and skip duplicates
        Arrays.sort(nums);

        for(int i = 0; i < n; i++) {
            // Skip duplicate first elements
            if(i > 0 && nums[i] == nums[i - 1]) continue;

            for(int j = i + 1; j < n; j++) {
                // Skip duplicate second elements
                if(j > i + 1 && nums[j] == nums[j - 1]) continue;

                int k = j + 1;
                int l = n - 1;

                // Find the remaining two elements using two pointers
                while(k < l) {
                    long sum = (long) nums[i] + nums[j] + nums[k] + nums[l];

                    if(sum == target) {
                        // Found a valid quadruplet
                        ans.add(Arrays.asList(
                            nums[i], nums[j], nums[k], nums[l]
                        ));

                        k++;
                        l--;

                        // Skip duplicate third elements
                        while(k < l && nums[k] == nums[k - 1]) k++;

                        // Skip duplicate fourth elements
                        while(k < l && nums[l] == nums[l + 1]) l--;
                    }
                    else if(sum < target) {
                        // Need a larger sum
                        k++;
                    }
                    else {
                        // Need a smaller sum
                        l--;
                    }
                }
            }
        }

        return ans;
    }
}