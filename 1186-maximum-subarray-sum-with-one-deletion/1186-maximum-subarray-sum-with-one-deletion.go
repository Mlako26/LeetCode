
func maximumSum(arr []int) int {
	maxEnding := make([]int, len(arr))
	maxEnding[0] = arr[0]
	maxStarting := make([]int, len(arr))
	maxStarting[len(arr)-1] = arr[len(arr)-1]
	mx := arr[0]
	for i := 1; i < len(arr); i++ {
		maxEnding[i] = max(maxEnding[i-1]+arr[i], arr[i])
		maxStarting[len(arr)-1-i] = max(maxStarting[len(arr)-i]+arr[len(arr)-1-i], arr[len(arr)-1-i])
		mx = max(mx, max(maxEnding[i], maxStarting[len(arr)-1-i]))
	}
	for i := 1; i < len(arr)-1; i++ {
		mx = max(mx, maxEnding[i-1]+maxStarting[i+1])
	}

	return mx
}
