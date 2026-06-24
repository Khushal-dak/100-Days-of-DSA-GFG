// # Rat Maze With Multiple Jumps

// ## Problem

// Given an `n × n` matrix where each cell represents the maximum number of steps a rat can jump right or down, find a valid path from `(0,0)` to `(n-1,n-1)`.

// Return a matrix where cells in the path are marked as `1`. If no path exists, return `{{-1}}`.

// ### Example

// ```text
// Input:
// [[2,1,0,0],
//  [3,0,0,1],
//  [0,1,0,1],
//  [0,0,0,1]]

// Output:
// [[1,0,0,0],
//  [1,0,0,1],
//  [0,0,0,1],
//  [0,0,0,1]]
// ```

// ## Approach

// * Use Backtracking (DFS).
// * From each cell, try all possible jumps from `1` to `mat[i][j]`.
// * Give preference to moving right before moving down.
// * Mark cells in the path and backtrack if the path fails.
// * Return the first valid path found.

// ## C++ Solution

// ```cpp
class Solution {
public:
    bool solve(int i,int j,vector<vector<int>>& mat,
               vector<vector<int>>& ans,
               vector<vector<int>>& vis,int n){

        if(i>=n||j>=n||mat[i][j]==0)
            return false;

        if(i==n-1&&j==n-1){
            ans[i][j]=1;
            return true;
        }

        if(vis[i][j])
            return false;

        vis[i][j]=1;
        ans[i][j]=1;

        int jump=mat[i][j];

        for(int k=1;k<=jump;k++){

            if(solve(i,j+k,mat,ans,vis,n))
                return true;

            if(solve(i+k,j,mat,ans,vis,n))
                return true;
        }

        ans[i][j]=0;
        return false;
    }

    vector<vector<int>> shortestDist(vector<vector<int>>& mat){

        int n=mat.size();

        if(mat[0][0]==0)
            return {{-1}};

        vector<vector<int>> ans(n,vector<int>(n,0));
        vector<vector<int>> vis(n,vector<int>(n,0));

        if(solve(0,0,mat,ans,vis,n))
            return ans;

        return {{-1}};
    }
};
// ```

// ## Complexity

// * Time Complexity: O(n² × maxJump)
// * Space Complexity: O(n²)
