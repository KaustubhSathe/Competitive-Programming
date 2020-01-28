#include<bits/stdc++.h>
using namespace std;
// https: //leetcode.com/problems/unique-paths-iii/

/*
    So in this problem we are given a 2D grid which contains a starting point(marked as 1) and ending point(marked as 2),
    and empty squares(marked as 0) and obstacles(marked as -1), and we have to find the number of walks from start to end 
    that walk over every non-obstacle square exactly once. 1 <= grid.length * grid[0].length <= 20.

    Since the constraints are small we can solve this problem using backtracking approach.
    Keep a count of number of empty sqaures that we have walked over and compare it with the total number of empty squares in 
    the grid,if they are equal and we are at the end position then update the count of walks.
*/

class Solution
{
public:
    bool isValid(int x,int y,int n,int m){
        return x>=0 && x<n &&y>=0&&y<m;
    }
    void backtrack(int x, int y, vector<vector<int>> &grid,vector<vector<bool>>& visited,int cnt,int zeros,int n,int m,int& ans){
        if(cnt == zeros && grid[x][y] == 2){ 
            ans++;
            return;
        }
        visited[x][y] = true;
        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};
        for(int k = 0;k<4;k++){
            if (isValid(x + dx[k], y + dy[k], n, m)&& !visited[x + dx[k]][y + dy[k]] && grid[x + dx[k]][y + dy[k]] != -1){
                backtrack(x + dx[k], y + dy[k], grid,visited,cnt + (grid[x + dx[k]][y + dy[k]]==0),zeros,n,m,ans);
            }
        }
        visited[x][y] = false;
    }
    int uniquePathsIII(vector<vector<int>> &grid){
        int zeros, n, m;
        zeros = 0;
        int ans = 0;
        n = grid.size();
        if(n == 0)return 0;
        m = grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                zeros += (grid[i][j] == 0);
            }   
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 1){
                    backtrack(i,j,grid,visited,0,zeros,n,m,ans);
                }
            }   
        }

        return ans;

    }
};