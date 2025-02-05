//Question 14
//LC problem 42. Trapping rain water

#include <iostream>
#include <vector>

int trap(std::vector<int>& height) {
    if(height.empty()) return 0;

    int left = 0, right = height.size() - 1;
    int left_max = height[left], right_max = height[right];
    int result = 0;

    while(left < right) {
        //Iterate from left
        if(left_max < right_max) {
            left++;

            left_max = std::max(left_max, height[left]);
            result += left_max - height[left];
        }
        //Iterate from right
        else {
            right--;

            right_max = std::max(right_max, height[right]);
            result += right_max - height[right];
        }
    }

    return result;
}

int main() {
    std::vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    std::vector<int> height2 = {4, 2, 0, 3, 2, 5};

    std::cout << trap(height) << '\n';
    std::cout << trap(height2) << '\n';
}