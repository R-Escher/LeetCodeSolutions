// Difficulty: Hard

/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

Example 1:
    Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
    Output: 6
    Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

Example 2:
    Input: height = [4,2,0,3,2,5]
    Output: 9

Constraints:
    n == height.length
    1 <= n <= 2 * 104
    0 <= height[i] <= 105
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int trap(vector<int>& v)
    {
        int rain_water{0};

        vector<int> aux(v.size(), 0);

        int last_wall_idx{0};
        for(int i = 1; i < v.size() - 1; ++i)
        {
            if(v[last_wall_idx] > v[i])
            {
                aux[i] = v[last_wall_idx] - v[i];
            }
            else
            {
                last_wall_idx = i;
            }
        }

        last_wall_idx = v.size() - 1;
        for(int j = v.size() - 2; j >= 0; --j)
        {
            if(v[last_wall_idx] > v[j])
            {
                rain_water += min(v[last_wall_idx] - v[j], aux[j]);
            }
            else
            {
                last_wall_idx = j;
            }
        }

        return rain_water;
    }
};

int main()
{
    vector<int> nums{0,1,0,2,1,0,1,3,2,1,2,1};

    Solution s{};
    s.trap(nums);

    return 0;
}
