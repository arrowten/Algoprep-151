//Question 4
//LC problem 152. Maximum subarray product

#include <iostream>
#include <vector>

int maximum_subarray_product(std::vector<int>& nums) {
    if(nums.size() == 0) return 0;

    int size = nums.size();
    int left_product = 1, right_product = 1;
    int maximum = nums[0];  //Stores the maximum product

    for(int i = 0; i < size; i++) {
        //If any of left_product or right_product becomes 0, update it to 1
        left_product = (left_product == 0) ? 1 : left_product;
        right_product = (right_product == 0) ? 1 : right_product;

        //Prefix product
        left_product *= nums[i];

        //Suffix product
        right_product *= nums[size - i - 1];

        //Update the maximum product
        maximum = std::max(maximum, std::max(left_product, right_product));
    }

    return maximum;
}

int main() {
    std::vector<int> nums = {2, 3, -2, 4};
    std::vector<int> nums2 = {-2, 0, 1};
    std::vector<int> nums3 = {2, 3, -2, -5, 6, -1, 4};

    std::cout << maximum_subarray_product(nums) << '\n';
    std::cout << maximum_subarray_product(nums2) << '\n';
    std::cout << maximum_subarray_product(nums3) << '\n';
}