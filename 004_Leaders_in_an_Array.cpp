//# Leaders in an Array
//
//## Problem
//Given an array `arr[]`, find all leaders in the array.
//
//**Leader:** An element that is greater than or equal to all elements on its right. The rightmost element is always a leader.
//
//### Example
//```text
//Input:  [16, 17, 4, 3, 5, 2]
//Output: [17, 5, 2]
//```
//
//## C++ Solution
//
//```cpp
class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        int n = arr.size();
        int max = arr[n-1];
        vector<int> temp;
        temp.push_back(max);
        
        for(int i=n-2;i>=0;i--)
        {
            if(arr[i]>=max)
            {
                max=arr[i];
                temp.push_back(max);
            }
        }
        
        reverse(temp.begin(),temp.end());
        return temp;
    }
};
//```
//
//## Complexity
//- **Time Complexity:** O(n)
//- **Space Complexity:** O(n)