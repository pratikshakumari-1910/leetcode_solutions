class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int result = 0;
        int n = nums.size();
        int sum = 0;
        unordered_map<int,int>mpp;

        mpp[0]=1;

        for(int i = 0; i<n;i++)
        {
            sum += nums[i];
        
            int rem = sum % k;
            if(rem<0)
            {
                rem+=k;
            }
            if(mpp.find(rem)!=mpp.end())
            {
                result += mpp[rem];
            }
            mpp[rem]++;

        }
        return result;
    }
};