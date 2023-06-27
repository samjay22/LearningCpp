class Solution {
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int totalSize = nums1.size() + nums2.size();
    if (totalSize % 2 == 1) {
        return findKthElement(nums1, 0, nums2, 0, totalSize / 2 + 1);
    } else {
        double median1 = findKthElement(nums1, 0, nums2, 0, totalSize / 2);
        double median2 = findKthElement(nums1, 0, nums2, 0, totalSize / 2 + 1);
        return (median1 + median2) / 2.0;
    }
}

int findKthElement(vector<int>& nums1, int start1, vector<int>& nums2, int start2, int k) {
    if (start1 >= nums1.size()) {
        return nums2[start2 + k - 1];
    }
    if (start2 >= nums2.size()) {
        return nums1[start1 + k - 1];
    }
    if (k == 1) {
        return min(nums1[start1], nums2[start2]);
    }
    
    int midVal1 = (start1 + k / 2 - 1 < nums1.size()) ? nums1[start1 + k / 2 - 1] : INT_MAX;
    int midVal2 = (start2 + k / 2 - 1 < nums2.size()) ? nums2[start2 + k / 2 - 1] : INT_MAX;
    
    if (midVal1 < midVal2) {
        return findKthElement(nums1, start1 + k / 2, nums2, start2, k - k / 2);
    } else {
        return findKthElement(nums1, start1, nums2, start2 + k / 2, k - k / 2);
    }
}
};
