/*
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
*/

//APPROACH 1: usage of XOR operation
class Solution {
public:
   
       int search(vector<int>& nums, int target) {
    int left = 0, right = nums.size();
    while (left < right) {
        int mid = (left + right) / 2;
        if (nums[mid] == target) return mid;
        if ((nums[mid] >= nums[0]) ^ (target >= nums[0]) ^ (nums[mid] < target)) 
            left = mid + 1;
        else right = mid;
    }
    return -1;
} 
    
};

//APPROACH 2: Usage of binary search
class Solution {
public:
    int subArrPart (vector<int>& arr, int num){
        if(num >= arr[0]){
            return 1;
        }

        return 2;
    }
    
    int binarySearch (vector<int>& arr, int target, int l, int r){
        if(l > r) return -1;
        
        
        int mid = (l + r)/2;

        if(arr[mid] < target){
            if(subArrPart(arr,arr[mid]) == subArrPart(arr,target)){
                return binarySearch(arr, target, mid+1, r);    
            }
             
            return binarySearch(arr, target, l, mid-1);           
        }
        else if(arr[mid] > target){
            if(subArrPart(arr,arr[mid]) == subArrPart(arr,target)){
                return binarySearch(arr, target, l, mid-1);
            }
            
            return binarySearch(arr, target, mid+1, r);            
        }
        
        return mid;
    }
    
    int search(vector<int>& arr, int target) {
        int ans = binarySearch(arr, target, 0, arr.size()-1);
        return ans;
    }
};
