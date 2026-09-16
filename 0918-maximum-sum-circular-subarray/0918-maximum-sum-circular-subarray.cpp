class Solution {
public:
    int KadanesMax(vector<int> &nums, int n)
    {
            int sum = nums[0];
            int maxSum = nums[0];
            for(int i=1;i<n;i++)
            {
                sum = max(sum+nums[i], nums[i]);
                maxSum = max(maxSum,sum);
            }
            return maxSum;
    }
    int KadanesMin(vector<int> &nums, int n)
    {
            int sum = nums[0];
            int minSum = nums[0];
            for(int i=1;i<n;i++)
            {
                sum = min(sum+nums[i], nums[i]);
                minSum = min(minSum,sum);
            }
            return minSum;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();

        //1.
        int tSum = accumulate(nums.begin(),nums.end(),0);
        //2.
        int minSum = KadanesMin(nums,n);
        //3
        int maxSum = KadanesMax(nums,n);
        //4
        int circularSum = tSum - minSum;
        //5
        if(maxSum > 0)
        {
            return max(maxSum, circularSum);
        }
        return maxSum;
    }
};