// # Maximum Area Between Bars

// ## Problem

// Given an integer array `height[]`, where each element represents the height of a bar, find the maximum rectangular area that can be formed by selecting any two bars.

// The area is calculated as:

// ```text
// min(height[i], height[j]) × (number of bars between them)
// ```

// ### Example

// ```text
// Input: height[] = [2, 5, 4, 3, 7]
// Output: 10

// Input: height[] = [1, 3, 4]
// Output: 1
// ```

// ## Approach

// * Use two pointers at the beginning and end of the array.
// * Calculate the area formed by the selected bars.
// * Move the pointer having the smaller height.
// * Keep track of the maximum area obtained.

// ## C++ Solution

// ```cpp
class Solution {
public:
    int maxArea(vector<int> &height) {

        int i = 0;
        int j = height.size() - 1;
        int ans = 0;

        while (i < j) 
        {
            int bars = j - i - 1;
            ans = max(ans, min(height[i], height[j]) * bars);

            if (height[i] < height[j])
                i++;
            else
                j--;
        }

        return ans;
    }
};
// ```

// ## Complexity

// * Time Complexity: O(n)
// * Space Complexity: O(1)
