int maxSubArray(vector<int>& nums) {
      int maxi=nums[0];
        int* sum=new int[nums.size()+1];
        sum[0]=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            sum[i]=max(sum[i-1]+nums[i],nums[i]);
            maxi=max(maxi,sum[i]);
        }
       
       return maxi; 
    }
