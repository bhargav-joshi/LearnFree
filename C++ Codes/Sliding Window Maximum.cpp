/*
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    priority_queue<pair<int,int>>maxh;
    vector<int>res;
        for(int i=0;i<k;i++)
            maxh.push({nums[i],i});
         res.push_back(maxh.top().first);
        
        for(int i=k;i<nums.size();i++)
        {
            maxh.push({nums[i],i});
            while(!(maxh.top().second>i-k))
                maxh.pop();
            res.push_back(maxh.top().first);
        }
      return res;
    }
};
