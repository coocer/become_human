#include <iostream>
#include "solution001.h"

int main() {
    Solution001 solution;
    std::vector<int> nums = {1, 2, 3, 4};
    std::vector<int> res = solution.productExceptSelf(nums);
    for (int i = 0; i < res.size(); i++) {
        std::cout << res[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}

