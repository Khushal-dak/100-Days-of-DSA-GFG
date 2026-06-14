/*
Problem: Third Largest Element
Platform: GeeksforGeeks
Difficulty: Easy

Approach:
1. Find the largest element and its index.
2. Find the second largest element excluding the largest element.
3. Find the third largest element excluding the largest and second largest elements.
4. Return the third largest element.

Time Complexity: O(3N) ≈ O(N)
Space Complexity: O(1)
*/

class Solution {
  public:
    int thirdLargest(vector<int> &arr) {
        
        int size = arr.size();
        int fl = -1, sl = -1, tl = -1;
		int fi = -1, si = -1;
        
        if(size < 3)
            return -1;
        
        for(int i = 0; i < size; i++)
        {
            if(arr[i] > fl)
            {
                fl = arr[i];
                fi = i;
            }
        }
        
        for(int i = 0; i < size; i++)
        {
            if(i == fi)
                continue;
            
            if(arr[i] > sl)
            {
                sl = arr[i];
                si = i;
            }
        }
        
        for(int i = 0; i < size; i++)
        {
            if(i == si || i == fi)
                continue;
            
            if(arr[i] > tl)
                tl = arr[i];
        }
        
        return tl;
    }
};