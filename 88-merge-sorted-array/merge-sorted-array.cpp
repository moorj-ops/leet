class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            int i=m-1;//nums1 ka end pt
            int j=n-1;//nums2 ka end pt
            int k=(n+m)-1;
            while(i>=0 && j>=0){
                if(nums1[i]<nums2[j]){
                    nums1[k]=nums2[j];
                    k--;
                    j--;
                }
                else{
                    nums1[k]=nums1[i];
                    i--;
                    k--;
                }
            }
            //if nums2 elemnts are still remaining
            while(j>=0){
                nums1[k]=nums2[j];
                k--;
                j--;
            }

        
    }
};