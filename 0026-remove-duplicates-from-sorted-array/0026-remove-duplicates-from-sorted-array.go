func removeDuplicates(nums []int) int {
    lastValid := 0
	current := 1
	for current < len(nums) {
		if nums[current] != nums[lastValid] {
			lastValid++
			nums[lastValid] = nums[current]
		}
		current++
	}

	return lastValid + 1
}