// # Maximum Number of People Defeated

// ## Problem

// There are infinitely many people standing in a row. The strength of the person at index `i` is `i²`.

// Given a strength `p`, determine the maximum number of people that can be defeated.

// ### Example

// ```text
// Input: p = 14
// Output: 3

// Input: p = 10
// Output: 2
// ```

// ## Approach

// * Start from the first person.
// * Keep adding the strength required to defeat each person (`i²`).
// * Count how many people can be defeated before the total strength exceeds `p`.

// ## C++ Solution

// ```cpp
class Solution {
  public:
    int maxPeopleDefeated(int p) {
        int sum = 0, count = 0;

        for(int i = 1; i <= sqrt(p); i++)
        {
            sum += (i * i);

            if(sum <= p)
                count++;
            else
                break;
        }

        return count;
    }
};
// ```

// ## Complexity

// * Time Complexity: O(√p)
// * Space Complexity: O(1)

// ```
// ```
