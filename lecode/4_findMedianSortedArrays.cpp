#include <iostream>
#include <vector>
using namespace std;

class Solution {
    //当总长度l为奇数时，k=(l+1)/2
public:
    int getKthElement(const vector<int>& nums1, const vector<int>& nums2, int k)
    {
        int m = nums1.size();
        int n = nums2.size();
        int indexStart1 = 0;
        int indexStart2 = 0;

        while (true) {
            //当数组为空时,选择另外一个数组的中位数
            if (indexStart1 == m) {
                return nums2[indexStart2 + k - 1];
            }
            if (indexStart2 == n) {
                return nums1[indexStart1 + k - 1];
            }
            if (k == 1) {
                return min(nums1[indexStart1], nums2[indexStart2]);
            }

            //判断每个数组中第k小的数是否越界
            int indexMedian1 = min(indexStart1 + k / 2 - 1, m - 1);
            int indexMedian2 = min(indexStart2 + k / 2 - 1, n - 1);
            int pivot1 = nums1[indexMedian1];
            int pivot2 = nums2[indexMedian2];
            if (pivot1 <= pivot2) {
                k -= indexMedian1 - indexStart1 + 1;
                indexStart1 = indexMedian1 + 1;
            } else {
                k -= indexMedian2 - indexStart2 + 1;
                indexStart2 = indexMedian2 + 1;
            }
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int totalL = nums1.size() + nums2.size();
        if (totalL % 2 == 1) {
            return getKthElement(nums1, nums2, (totalL + 1) / 2);
        } else {
            return (getKthElement(nums1, nums2, totalL / 2) + getKthElement(nums1, nums2, totalL / 2 + 1)) / 2.0;
        }
    }
};
