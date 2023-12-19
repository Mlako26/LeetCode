func searchInsert(nums []int, target int) int {
	var i, j int = 0, len(nums) - 1
	for i < j {
		k := (i + j) / 2
		if nums[k] == target {
			return k
		}
		if nums[k] < target {
			i = k + 1
		} else {
			j = k - 1
		}
	}
	if nums[i] < target {
		return i + 1
	}
	return i
}
