/*Given an array of n positive integers and a positive integer s,
find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.

click to show more practice.

Credits:
Special thanks to @Freezen for adding this problem and creating all test cases.

*/

class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		int l = 0, r = -1;
		int sum = 0;
		int res = nums.size() + 1;
		while (l<nums.size())
		{
			if (r + 1<nums.size() && sum<s)
				sum += nums[++r];
			else
				sum -= nums[l++];

			if (sum >= s)
				res = min(res, r - l + 1);
		}
		if (res == nums.size() + 1)
			return 0;

		return res;
	}
};