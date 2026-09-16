class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size() ;
        int n2 = nums2.size() ;
        if(n1>n2) return findMedianSortedArrays(nums2,nums1) ;
        int n = n1 + n2 ;
        int left = (n+1)/2 ;
        int low = 0 ;
        int high = n1 ;
        while(low<=high){
            int mid1 = ( low + high ) / 2 ;
            int mid2 = left - mid1 ;
            int a = mid1==0 ? INT_MIN : nums1[mid1-1] ;
            int b = mid1==n1 ? INT_MAX : nums1[mid1] ;
            int c = mid2==0 ? INT_MIN : nums2[mid2-1] ;
            int d = mid2==n2 ? INT_MAX : nums2[mid2] ;
            if(a<=d && c<=b){
                if(n&1) return max(a,c) ;
                return (max(a,c)+min(b,d))/2.0 ;
            }
            else if(a>d) high = mid1 - 1 ;
            else 
                low = mid1 + 1 ;
        }
        return 0 ;
    }
};
