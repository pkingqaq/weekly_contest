func maximumEnergy(energy []int, k int) int {
    ans := math.MinInt
    n := len(energy)
    for i := n - k; i < n; i++ {
        cur := 0
        for j := i; j >= 0; j -= k {
            cur += energy[j]
            ans = int(math.Max(float64(ans), float64(cur)))
        }
    }
    return ans
}
