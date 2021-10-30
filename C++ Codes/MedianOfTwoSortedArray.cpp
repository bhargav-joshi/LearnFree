/*
INPUT : nums1 = [1,2], nums2 = [3,4]
OUTPUT : 2.50000
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        if(nums2.size() < nums1.size()) {
            
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int low = 0, high = nums1.size();
        
        while(low <= high) {
            
            int mid = (low+high)/2;
            int mid1 = (nums1.size()+nums2.size()+1)/2-mid;
            
            int l1 = mid == 0 ? INT_MIN : nums1[mid-1];
            int l2 = mid1 == 0 ? INT_MIN : nums2[mid1-1];
            
            int r1 = mid == nums1.size() ? INT_MAX : nums1[mid];
            int r2 = mid1 == nums2.size() ? INT_MAX : nums2[mid1];
            
            if(l1 <= r2 && l2 <= r1) {
                
                if(nums1.size()%2 == nums2.size()%2) {
                    
                    return double(max(l1, l2) + min(r1, r2))/2;
                }
                else {
                    
                    return (double)max(l1, l2);
                }
            }
            else if(l1 > r2) {
                
                high = mid-1;
            }
            else {
                
                low = mid+1;
            }
        }
        
        return 0.0;
    }
};
