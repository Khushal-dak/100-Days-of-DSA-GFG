/*# Last Digit of a^b

## Problem

Given two integers `a` and `b` in the form of strings. Return the last digit of `a^b`.

### Example

```text
Input: a = "3", b = "10"
Output: 9

Input: a = "6", b = "2"
Output: 6
```

## C++ Solution

```cpp*/
class Solution {
  public:
    int getLastDigit(string& a, string& b) {

        if (b == "0")
            return 1;

        int lastDigit = a.back() - '0';

        vector<vector<int>> cycle = {
            {0},
            {1},
            {2,4,8,6},
            {3,9,7,1},
            {4,6},
            {5},
            {6},
            {7,9,3,1},
            {8,4,2,6},
            {9,1}
        };

        vector<int>& curr = cycle[lastDigit];
        int len = curr.size();

        int rem = 0;

        for(char ch : b)
        {
            rem = (rem * 10 + (ch - '0')) % len;
        }

        if(rem == 0)
            return curr[len - 1];

        return curr[rem - 1];
    }
};
/*```

## Complexity

* Time Complexity: O(|b|)
* Space Complexity: O(1)
*/
