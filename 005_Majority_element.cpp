//Question 5
//LC problem 169. Majority element

#include <iostream>
#include <vector>

int majority_element(std::vector<int>& nums) {
    int current = 0, count = 0;
    
    for(int i: nums) {
        if(count == 0) {
            current = i;
        }

        count += (i == current) ? 1 : -1;   //Count the number of majority element
    }

    return current;
}

int main() {
    std::vector<int> nums = {3, 2, 3};
    std::vector<int> nums2 = {2, 2, 1, 1, 1, 2, 2};

    std::cout << majority_element(nums) << '\n';
    std::cout << majority_element(nums2) << '\n';
}