func maxScore(grid [][]int) int {
    ans := math.MinInt
    m := len(grid)
    n := len(grid[0])
    f := make([][]int, m + 1)
    for i := range f {
        f[i] = make([]int, n + 1)
        for j := range f[i] {
            f[i][j] = math.MaxInt
        }
    }

    for i, row := range grid {
        for j, val := range row {
            mn := min(f[i + 1][j], f[i][j + 1])
            ans = max(ans, val - mn)
            f[i + 1][j + 1] = min(mn, val);
        }
    }
    return ans
}

func max(a,b int) int {
    if a > b {
        return a
    } else {
        return b
    }
}

func min(a,b int) int {
    if a > b {
        return b
    } else {
        return a
    }
}
