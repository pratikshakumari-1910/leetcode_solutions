class Solution {
public:
    int KadanesMax(vector<int>&nums,int n)
    {
        int maxSum = nums[0];
        int sum = nums[0];
        for(int i = 1; i<n;i++)
        {
            sum = max(sum+nums[i],nums[i]);
            maxSum = max(sum,maxSum);
        }
        return maxSum;
    }
    int KadanesMin(vector<int>&nums,int n)
    {
        int minSum = nums[0];
        int sum = nums[0];
        for(int i = 1; i<n;i++)
        {
            sum = min(sum+nums[i],nums[i]);
            minSum = min(sum,minSum);
        }
        return minSum;
    }
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int SUM = accumulate(nums.begin(),nums.end(),0);

        int minSum = KadanesMin(nums,n);
        
        int maxSum = KadanesMax(nums,n);

        int result = max(abs(minSum),abs(maxSum));

        return result;
    }
};