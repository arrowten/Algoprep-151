//Question 16
//LC problem 1. Two sum

#include <iostream>
#include <vector>
#include <map>

std::pair<int, int> two_sum(std::vector<int>& nums, int target) {
    if(nums.size() == 0) return std::pair<int, int>{-1, -1};

    std::map<int, int> mp;
    int size = nums.size();
    std::pair<int, int> p{-1, -1};

    for(int i = 0; i < size; i++) {
        int d = target - nums[i];
        
        if(mp.find(d) != mp.end()) {
            return {mp[d], i};
        }

        mp[nums[i]] = i;
    }

    return p;
}

void print(std::pair<int, int> result) {
    std::cout << result.first << ", " << result.second << '\n'; 
}

int main() {
    std::vector<int> nums = {2, 7, 11, 15};
    std::vector<int> nums2 = {3, 2, 4};
    std::vector<int> nums3 = {3, 3};
    std::vector<int> nums4 = {0, -1, 2, -3, 1};
    std::vector<int> nums5 = {1, -2, 1, 0, 5};
    std::pair<int, int> result;

    result = two_sum(nums, 9);

    print(result);

    result = two_sum(nums2, 6);

    print(result);

    result = two_sum(nums3, 6);

    print(result);

    result = two_sum(nums4, -2);

    print(result);

    result = two_sum(nums5, 0);

    print(result);
}