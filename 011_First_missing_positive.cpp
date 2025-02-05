#include <iostream>
#include <vector>
#include <map>

int first_missing_positive(std::vector<int>& nums) {
    if(nums.size() == 0) return 0;

    bool contains_one = false;

    //If 1 found, then break
    for(int i: nums) {
        if(i == 1) {
            contains_one = true;
            break;
        }
    }

    //If not found, return 1
    if(!contains_one) return 1;

    int size = nums.size();

    //If only 1 element exists, return 2
    if(size == 1) return 2;

    //Make all numbers less than or equal to 0 and greater than the size as 1
    for(int i = 0; i < size; i++) {
        if(nums[i] <= 0 || nums[i] > size) nums[i] = 1;
    }

    //Negate the numbers
    for(int i = 0; i < size; i++) {
        int x = std::abs(nums[i]);

        if(nums[x - 1] > 0) nums[x - 1] *= -1;
    }

    //If found positive, return it
    for(int i = 0; i < size; i++) {
        if(nums[i] > 0) return i + 1;
    }

    return size + 1;
}

int main() {
    std::vector<int> nums = {1, 2, 0};
    std::vector<int> nums2 = {3, 4, -1, 1};
    std::vector<int> nums3 = {7, 8, 9, 11, 12};

    std::cout << first_missing_positive(nums) << '\n';
    std::cout << first_missing_positive(nums2) << '\n';
    std::cout << first_missing_positive(nums3) << '\n';
}