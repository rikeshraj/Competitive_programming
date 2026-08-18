/*
Q1. Number of Islands
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
*/
class Solution {
public:
    void dfs(vector<vector<char>>& grid, int r, int c) {
        int rows = grid.size();
        int cols = grid[0].size();
        if (r < 0 || r >= rows ||
            c < 0 || c >= cols ||
            grid[r][c] != '1') {
            return;
        }
        grid[r][c] = '0';
        dfs(grid, r + 1, c);
        dfs(grid, r - 1, c);
        dfs(grid, r, c + 1);
        dfs(grid, r, c - 1);
    }
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty())
            return 0;
        int rows = grid.size();
        int cols = grid[0].size();
        int islands = 0;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == '1') {
                    islands++;
                    dfs(grid, r, c);
                }
            }
        }
        return islands;
    }
};

/*
Q2. Rotting Oranges
You are given an m x n grid where each cell can have one of three values:
0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.
Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.
*/
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 2) {
                    q.push({r, c});
                }
                else if (grid[r][c] == 1) {
                    fresh++;
                }
            }
        }
        int minutes = 0;
        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};
        while (!q.empty() && fresh > 0) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto [r, c] = q.front();
                q.pop();
                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];
                    if (nr >= 0 && nr < rows &&
                        nc >= 0 && nc < cols &&
                        grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        fresh--;
                        q.push({nr, nc});
                    }
                }
            }
            minutes++;
        }
        return fresh == 0 ? minutes : -1;
    }
};

/*
Q3. Generate Parentheses
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
*/
class Solution {
public:
    vector<string> result;
    void backtrack(string& s, int open, int close, int n) {
        if (s.size() == 2 * n) {
            result.push_back(s);
            return;
        }
        if (open < n) {
            s.push_back('(');
            backtrack(s, open + 1, close, n);
            s.pop_back();
        }
        if (close < open) {
            s.push_back(')');
            backtrack(s, open, close + 1, n);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string s;
        backtrack(s, 0, 0, n);
        return result;
    }
};
