//Question 3
//LC problem 53. Maximum subarray sum

#include <iostream>
#include <vector>

int maximum_subarray_sum(std::vector<int>& nums) {
    if(nums.size() == 0) return 0;

    int size = nums.size();
    int maximum_so_far = nums[0]; //Stores the overall maximum sum
    int sum = nums[0]; //Stores the maximum sum ending at the current index

    //Traverse array from the second element
    for(int i = 1; i < size; i++) {
        //Update sum
        sum = std::max(nums[i], sum + nums[i]);

        //Update the overall maximum sum if necessary
        maximum_so_far = std::max(maximum_so_far, sum);
    }

    return maximum_so_far;
}

int main() {
    std::vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    std::vector<int> nums2 = {1};
    std::vector<int> nums3 = {5, 4, -1, 7, 8};

    std::cout << maximum_subarray_sum(nums) << '\n';
    std::cout << maximum_subarray_sum(nums2) << '\n';
    std::cout << maximum_subarray_sum(nums3) << '\n';
}