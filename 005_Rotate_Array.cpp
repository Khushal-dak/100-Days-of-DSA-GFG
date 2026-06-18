//# Rotate Array
//
//## Problem Statement
//
//Given an array `arr[]` and an integer `d`, rotate the array to the left by `d` positions.
//
//### Example
//
//**Input:**
//
//```cpp
//arr = [1, 2, 3, 4, 5]
//d = 2
//```
//
//**Output:**
//
//```cpp
//[3, 4, 5, 1, 2]
//```
//
//---
//
//## Approach
//
//Using the **Reversal Algorithm**:
//
//1. Reverse the first `d` elements.
//2. Reverse the remaining `n - d` elements.
//3. Reverse the entire array.
//
//This efficiently performs the left rotation in-place without using extra space.
//
//---
//
//## Solution
//
//```cpp
class Solution {
public:
    void rotateArr(vector<int>& arr, int d) {
        int n = arr.size();

        d = d % n;

        reverse(arr.begin(), arr.begin() + d);
        reverse(arr.begin() + d, arr.end());
        reverse(arr.begin(), arr.end());
    }
};
//```
//
//---
//
//## Complexity Analysis
//
//* **Time Complexity:** O(n)
//* **Space Complexity:** O(1)
//
//---
//
//## Key Concepts Used
//
//* STL `reverse()`
//* Array Rotation
//* Reversal Algorithm
//* In-Place Manipulation
