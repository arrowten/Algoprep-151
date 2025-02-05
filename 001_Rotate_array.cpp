//Question 1
//LC problem 189. Rotate array

#include <iostream>
#include <vector>
#include <algorithm>

void rotate_array(std::vector<int>& nums, int k) {
    if(nums.size() == 0 || k == 0) return;
    if(k > nums.size()) k = k % nums.size();

    std::reverse(nums.begin(), nums.end() - k); //Reversing the first N - k elements
    std::reverse(nums.end() - k, nums.end());   //Reversing the last k elements 
    std::reverse(nums.begin(), nums.end());     //Reversing all elements
}

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> nums2 = {-1, -100, 3, 99};
    
    rotate_array(nums, 3);
    rotate_array(nums2, 2);

    for(int i: nums) {
        std::cout << i << '\t';
    }

    std::cout << '\n';

    for(int i: nums2) {
        std::cout << i << '\t';
    }

    std::cout << '\n';
}