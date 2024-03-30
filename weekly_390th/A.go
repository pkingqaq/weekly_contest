func maximumLengthSubstring(s string) int {
    ans := 0
    cnt := [26]int{}
    l := 0
    r := 0
    n := len(s)
    for r < n {
        cnt[rune(s[r]) - 'a']++
        for cnt[rune(s[r]) - 'a'] > 2 {
            cnt[rune(s[l]) - 'a']--
            l++
        }
        ans = max(ans, r - l + 1);
        r++
    }
    return ans
}
