import "math"
func minOperations(k int) int {
    return int(math.Ceil(2 * math.Sqrt(float64(k)) - 2))
}
