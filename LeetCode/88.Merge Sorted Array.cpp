/*Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.
The number of elements initialized in nums1 and nums2 are m and n respectively.*/

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		vector<int> temp1 = nums1;
		for (int i = 0, j = 0, k = 0;i<m + n;i++)
		{
			if (j >= m)
			{
				nums1[i] = nums2[k];
				k++;
			}
			else if (k >= n)
			{
				nums1[i] = temp1[j];
				j++;
			}
			else if (temp1[j]<nums2[k])
			{
				nums1[i] = temp1[j];
				j++;
			}
			else
			{
				nums1[i] = nums2[k];
				k++;
			}

		}
	}
};