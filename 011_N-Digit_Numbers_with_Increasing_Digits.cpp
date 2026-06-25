// # N-Digit Numbers with Increasing Digits

// ## Problem

// Given an integer `n`, return all `n`-digit numbers whose digits are in **strictly increasing order** from left to right.

// ### Example

// ```text
// Input: n = 1
// Output: [0,1,2,3,4,5,6,7,8,9]

// Input: n = 2
// Output: [12,13,14,15,...,89]
// ```

// ## Approach

// * Use **Backtracking (DFS)** to generate numbers.
// * Start from the smallest possible digit.
// * At each step, choose the next greater digit to maintain strictly increasing order.
// * If the required length is reached, store the number.

// ## C++ Solution

// ```cpp
class Solution {
    void solve(int start, int n, int len, int num, vector<int> &ans) {
        if (len == n) {
            ans.push_back(num);
            return;
        }

        for (int d = start; d <= 9; d++) {
            solve(d + 1, n, len + 1, num * 10 + d, ans);
        }
    }

public:
    vector<int> increasingNumbers(int n) {
        vector<int> ans;

        if (n == 1) {
            for (int i = 0; i <= 9; i++)
                ans.push_back(i);
            return ans;
        }

        if (n > 9)
            return ans;

        solve(1, n, 0, 0, ans);
        return ans;
    }
};
// ```

// ## Complexity

// * **Time Complexity:** O(C(9, n))
// * **Space Complexity:** O(n)
