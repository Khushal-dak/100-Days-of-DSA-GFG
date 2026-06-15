//# Two Sum - Pair with Given Sum

//## Problem
//Given an array `arr[]` and an integer `target`, determine whether there exists a pair of distinct elements whose sum is equal to `target`.

//## Approach
//- Sort the array.
//- Use two pointers (`l` and `r`).
//- If `arr[l] + arr[r] == target`, return `true`.
//- If sum is smaller, move `l++`.
//- Otherwise move `r--`.
//- If no pair is found, return `false`.

//## Code

//```cpp
class Solution {
public:
    bool twoSum(vector<int>& arr, int target) {

        sort(arr.begin(), arr.end());

        int l = 0;
        int r = arr.size() - 1;

        while (l < r) {

            int sum = arr[l] + arr[r];

            if (sum == target)
                return true;
            else if (sum < target)
                l++;
            else
                r--;
        }

        return false;
    }
};
```

//## Complexity
//- Time Complexity: `O(n log n)`
//- Space Complexity: `O(1)`