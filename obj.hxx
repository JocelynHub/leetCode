class Solution {
public:
    int getKthElement(const vector<int> &nums1, const vector<int> &nums2, int k)
    {
        int m = nums1.size();
        int n = nums2.size();
        int index1 =0, index2 = 0;
        while(true)
        {
            if(index1 == m)
                return nums2[index2 + k - 1];//因为只剩一个数组的情况下，它本身有序，所以往后数 当前的K个
            if(index2 == n)
                return nums1[index1 + k - 1];
            if(k == 1)//表示 删除对方的最后一步
                return min(nums1[index1], nums2[index2]);
            
            int newIndex1 = min(index1 + k / 2 - 1, m - 1);//保全操作，在当前index基础上 加上 折半的量值
            int newIndex2 = min(index2 + k / 2 - 1, n - 1);
            
            int pivot1 = nums1[newIndex1];
            int pivot2 = nums2[newIndex2];
            
            if(pivot1 < pivot2)//谁小，删谁的
            {
                k -= newIndex1 - index1 + 1;//上一步如果需要第9个大数值，如果删去前面3个后，要找的就是剩下的 第6个大数值
                index1 = newIndex1 + 1;
            }
            else
            {
                k -= newIndex2 - index2 + 1;
                index2 = newIndex2 + 1;
            }
        }
    }
    
    //递归调用
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int totalLength = nums1.size() + nums2.size();
        if(totalLength % 2 == 1)
            return getKthElement(nums1, nums2, (totalLength + 1) / 2);
        else
            return (getKthElement(nums1, nums2, totalLength / 2)) + (getKthElement(nums1, nums2, totalLength / 2 + 1)) / 2.0;
    }

};