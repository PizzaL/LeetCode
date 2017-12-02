#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    double findMedian(vector<int>& nums1, int s1, int e1, vector<int>& num2, int e1, int e2)
    {
        
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        return findMedian(nums1, 0, nums1.size()-1, nums2, 0, nums2.size()-1);
    }
};

int main()
{
	Solution solution;
    cout << solution.findNthDigit(11);
	return 0;
}