// Difficulty: Easy

/*
Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

Example 1:
    Input: nums = [3,2,3]
    Output: 3

Example 2:
    Input: nums = [2,2,1,1,1,2,2]
    Output: 2

Constraints:
    n == nums.length
    1 <= n <= 5 * 104
    -109 <= nums[i] <= 109
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int majorityElement(vector<int>& nums)
    {
        int longest_seq{-1}, val_with_longest_seq{-1};

        // Sort
        std::sort(nums.begin(), nums.end());

        // Count sequences
        int last_val{-1};
        for(const auto elem : nums)
        {
            static int curr_seq{0};
            if(last_val == elem)
            {
                curr_seq++;
            }
            else
            {
                curr_seq = 1;
            }

            if(curr_seq > longest_seq)
            {
                longest_seq = curr_seq;
                val_with_longest_seq = elem;
            }

            last_val = elem;
        }

        return val_with_longest_seq;
    }
};

int main()
{
    vector<int> nums{2,2,1,1,1,2,2};

    Solution s{};
    s.majorityElement(nums);

    return 0;
}
