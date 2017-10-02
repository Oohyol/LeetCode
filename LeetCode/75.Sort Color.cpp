/*Given an array with n objects colored red, white or blue, 
sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.
Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
Note:
You are not suppose to use the library's sort function for this problem.*/


#include<iostream>
#include<vector>
using namespace std;

//quicksort
class Solution {
public:
int partition(vector<int>&nums,int l,int r)
{
int temp=nums[l];
int j=l;
for(int i=l+1;i<=r;i++)
{
if(nums[i]<temp)
{
j++;
swap(nums[j],nums[i]);
}
}
swap(nums[j],nums[l]);
return j;

}
void quicksort(vector<int>& nums,int l,int r)
{
if(l>=r)
return;
int p=partition(nums,l,r);
quicksort(nums,l,p-1);
quicksort(nums,p+1,r);
}

void sortColors(vector<int>& nums) {

return    quicksort(nums,0,nums.size()-1);
}

};

//桶排序
class Solution {
public:
	void sortColors(vector<int>& nums) {
		int a[3] = { 0 };
		for (int i = 0;i<nums.size();i++)
		{
			assert(nums[i] >= 0 && nums[i] <= 2);
			a[nums[i]]++;
		}
		int index = 0;
		for (int i = 0;i<a[0];i++)
			nums[index++] = 0;
		for (int i = 0;i<a[1];i++)
			nums[index++] = 1;
		for (int i = 0;i<a[2];i++)
			nums[index++] = 2;
	}
};

//插入排序
class Solution {
public:
	void sortColors(vector<int>& nums) {
		for (int i = 1;i<nums.size();i++)
		{
			int temp = nums[i];
			int j = i;
			while (j>0 && nums[j - 1]>temp)
			{
				nums[j] = nums[j - 1];
				j--;
			}
			nums[j] = temp;
		}
	}
};