// https://pkg.go.dev/github.com/emirpasic/gods/v2@v2.0.0-alpha
func mostFrequentIDs(nums, freq []int) []int64 {
	cnt := map[int]int{}
	t := redblacktree.New[int, int]()
	ans := make([]int64, len(nums))
	for i, x := range nums {
		// 减少一次 cnt[x] 的出现次数
		node := t.GetNode(cnt[x])
		if node != nil {
			node.Value--
			if node.Value == 0 {
				t.Remove(node.Key)
			}
		}

		cnt[x] += freq[i]

		// 增加一次 cnt[x] 的出现次数
		node = t.GetNode(cnt[x])
		if node == nil {
			t.Put(cnt[x], 1)
		} else {
			node.Value++
		}
		ans[i] = int64(t.Right().Key)
	}
	return ans
}

