// # Choose and Swap

// ## Problem

// Given a string `s` of lowercase English letters, you can swap all occurrences of any two distinct characters at most once. Return the lexicographically smallest string after this operation.

// ### Example

// ```text
// Input: s = "ccad"
// Output: "aacd"

// Input: s = "abba"
// Output: "abba"
// ```

// ## Approach

// * Store the first occurrence of every character.
// * Traverse the string from left to right.
// * For each character, check if a smaller character exists later in the string.
// * If found, perform a global swap of both characters.
// * Only one swap operation is allowed.

// ## C++ Solution

// ```cpp
class Solution {
  public:
    string chooseSwap(string &s) {
        vector<int> firstOccur(26, -1);
        
        for (int i = 0; i < s.length(); i++) {
            if (firstOccur[s[i] - 'a'] == -1) {
                firstOccur[s[i] - 'a'] = i;
            }
        }

        for (int i = 0; i < s.length(); i++) {
            bool flag = false;
            char charToSwap;

            for (int j = 0; j < s[i] - 'a'; j++) {
                if (firstOccur[j] != -1 && firstOccur[j] > i) {
                    flag = true;
                    charToSwap = (char)(j + 'a');
                    break;
                }
            }

            if (flag) {
                char originalChar = s[i];

                for (int k = 0; k < s.length(); k++) {
                    if (s[k] == originalChar)
                        s[k] = charToSwap;
                    else if (s[k] == charToSwap)
                        s[k] = originalChar;
                }
                break;
            }
        }

        return s;
    }
};
// ```

// ## Complexity

// * Time Complexity: O(n)
// * Space Complexity: O(1)
