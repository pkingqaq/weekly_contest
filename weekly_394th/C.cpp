class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        // 预处理把第 j 列都变成数字 k 的操作数
        int g[m][10];
        memset(g, 0, sizeof(g));
        for (int j = 0; j < m; j++) for (int k = 0; k < 10; k++)
            for (int i = 0; i < n; i++) if (grid[i][j] != k) g[j][k]++;

        const int INF = 1e9;
        int f[m][10];
        for (int j = 0; j < m; j++) for (int k = 0; k < 10; k++) f[j][k] = INF;
        for (int k = 0; k < 10; k++) f[0][k] = g[0][k];
        // DP 方程
        for (int j = 1; j < m; j++) for (int k = 0; k < 10; k++)
            for (int kk = 0; kk < 10; kk++) if (k != kk) f[j][k] = min(f[j][k], f[j - 1][kk] + g[j][k]);

        int ans = INF;
        for (int k = 0; k < 10; k++) ans = min(ans, f[m - 1][k]);
        return ans;
    }
};
