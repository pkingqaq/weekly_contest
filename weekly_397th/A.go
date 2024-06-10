func findPermutationDifference(s string, t string) int {
    ans := 0
    arr := [26]int{}
    for i, c := range s {
        arr[c - 'a'] = i
    }

    for i, c := range t {
        ans += int(math.Abs(float64(arr[c - 'a'] - i)))
    }
    return ans
}
