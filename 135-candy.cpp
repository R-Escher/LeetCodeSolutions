// Difficulty: Hard

/*
There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.
You are giving candies to these children subjected to the following requirements:
    Each child must have at least one candy.
    Children with a higher rating get more candies than their neighbors.
    Return the minimum number of candies you need to have to distribute the candies to the children.

Example 1:
    Input: ratings = [1,0,2]
    Output: 5
    Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.

Example 2:
    Input: ratings = [1,2,2]
    Output: 4
    Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
    The third child gets 1 candy because it satisfies the above two conditions.

Constraints:
    n == ratings.length
    1 <= n <= 2 * 104
    0 <= ratings[i] <= 2 * 104
*/

// This solution has Time Complexity O(n²), but Space Complexity O(n).
// For a Time Complexity O(n) solution one should create an extra vector and store in it the minimum values looking back.
// And then run the vector in reverse looking forward and comparing to the extra vector with max().

#include <iostream>
#include <vector>

class Solution
{
public:
    int candy(vector<int>& ratings)
    {
        int candy_sum{0}, last_sum{0};
        
        for(int i = 0; i < ratings.size(); ++i)
        {
            // Find minimum values looking back
            int min_value_back{1};
            {
                if((i > 0) && (ratings[i] > ratings[i-1]))
                {
                    min_value_back = last_sum + 1;
                }
            }

            // Find minimum values looking forward
            int min_value_forward{1};
            int local_min_idx{i};
            {
                // Find local minimum in array (who is going to receive the smallest value if values are descending)
                for(int j = i + 1; j < ratings.size(); ++j)
                {
                    if(ratings[j] < ratings[j - 1])
                    {
                        local_min_idx = j;
                    }
                    else
                    {
                        break;
                    }
                }

                min_value_forward = abs(local_min_idx - i) + 1;
            }
            
            last_sum = max(min_value_back, min_value_forward);

            candy_sum += last_sum;
        }

        return candy_sum;
    }
};

int main()
{
    vector<int> nums{1,6,10,8,7,3,2};

    Solution s{};
    s.candy(nums);

    return 0;
}
