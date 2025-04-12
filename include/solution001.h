#pragma once

#include <iostream>
#include <vector>
class Solution001 {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> prefix(n, 1), suffix(n, 1), res(n);
        for (int i = 1;  i < n; i++) {
            prefix[i] = nums[i-1] * prefix[i-1];
            suffix[n-i-1] = nums[n-i] * suffix[n-i];
        }
        for (int i = 0; i < n; i++) {
            // std::cout<<prefix[i]<<' ' << suffix[i] << std::endl;
            res[i] = prefix[i] * suffix[i];
        }

        return res;
    }
};