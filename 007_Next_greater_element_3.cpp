//Question 7
//LC probelm 556. Next greater element 3

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

long long next_greater_element(long long N) {
    if(N <= 0) return 0;

    std::string digits = std::to_string(N);  //Convert the number to string
    int size = digits.size();
    int i = size - 2;

    //Find the first decreasing element from the right
    while(i >= 0 && digits[i] >= digits[i + 1]) {
        i--;
    }

    //If no such element found, return -1
    if(i < 0) return -1;

    int j = size - 1;

    //Find the next larger element from the right
    while(digits[j] <= digits[i]) {
        j--;
    }

    //Swap elements at i and j
    std::swap(digits[i], digits[j]);

    //Reverse the sequence after i to get the smallest possible number after N
    std::reverse(digits.begin() + i + 1, digits.end());

    //Convert back to integer
    long long result = std::stoll(digits);

    return (result > LONG_LONG_MAX) ? -1 : result;
}

int main() {
    std::cout << next_greater_element(12) << '\n';
    std::cout << next_greater_element(21) << '\n';
    std::cout << next_greater_element(46) << '\n';
    std::cout << next_greater_element(534976) << '\n';
    std::cout << next_greater_element(230241) << '\n';
}