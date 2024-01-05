#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
    int p1 = 0, p2 = 0;
    int current_element = 0;
    int sorted_array[m + n]; 

    while(p1 < m || p2 < n)
    {   
        if (p1 == m)
        {
            current_element = nums2[p2++];
        } else if (p2 == n) 
        {
            current_element = nums1[p1++];
        } else if (nums1[p1] > nums2[p2]) 
        {
            current_element = nums2[p2++];
        } else {
            current_element = nums1[p1++];
        }
        sorted_array[p1 + p2 - 1] = current_element;
    }

    for (int i = 0; i != m + n; ++i)
    {
        nums1[i] = sorted_array[i];
    }
}

int main()
{
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3;
    vector<int> nums2 = {2, 5, 6};
    int n = 3;
    
    merge(nums1, m, nums2, n);

    return 0;
}