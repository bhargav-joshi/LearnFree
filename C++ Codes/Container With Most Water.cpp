/*
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
      int water=0;
      int start=0,end=height.size()-1;
        while(start<end)
            {
            int heights=min(height[start],height[end]
);
            water=max(water,(end-start)*heights);
            while(start<end && height[start]<=heights)
                start++;
            while(start<end && height[end]<=heights)
                end--;
            
        }
        return water;
    }
};
