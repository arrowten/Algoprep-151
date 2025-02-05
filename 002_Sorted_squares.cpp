//Question 2
//LC problem 977. Squares of a rotated array

#include <iostream>
#include <vector>
#include <algorithm>

void sorted_squares(std::vector<int>& nums) {
    if(nums.size() == 0) return;
    
    int N = nums.size();
    
    for(int i = 0; i < N; i++) {
        nums[i] = nums[i] * nums[i];        //Square the elements
    }

    std::sort(nums.begin(), nums.end());    //Sort the elements
}

int main() {
    std::vector<int> nums = {-4, -1, 0, 3, 10};
    std::vector<int> nums2 = {-7, -3, 2, 3, 11};

    sorted_squares(nums);
    sorted_squares(nums2);

    for(int i: nums) {
        std::cout << i << '\t';
    }

    std::cout << '\n';

    for(int i: nums2) {
        std::cout << i << '\t';
    }

    std::cout << '\n';
}