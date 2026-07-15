class Solution {
public:
    int find(vector<int>& nums, int target,int low,int high){
        int mid=(high-low)/2 +low;
        if(low>high) return -1;
        if(nums[mid]==target)  return mid;
        if(nums[mid]>=nums[low]){
            if(target<nums[mid]&&target>=nums[low]) return find(nums,target,low,mid-1);
            else return find(nums,target,mid+1,high);
        }
        else{
            if(target>nums[mid]  &&  target<=nums[high]) return find(nums,target,mid+1,high);
            else return find(nums,target,low,mid-1);}
         }

    int search(vector<int>& nums, int target) {
        return find(nums,target,0,nums.size()-1);
        }
};