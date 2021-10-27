// https://leetcode.com/problems/two-sum/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_set<int> s;   vector<int> ans(2); 
        for(int i=0; i<nums.size();i++){
            s.insert(nums[i]);
                 int val = target - nums[i];
            if(s.find(val)!=s.end())
            {
                for(int j=0; j<nums.size();j++)
                    {if(nums[j]==val && j!=i)
                            {ans[0]=i;
                     ans[1]=j;}
                     }
            }
        
        
        }
        
     
        
     return ans;   
    }
};
