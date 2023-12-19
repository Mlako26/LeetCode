func removeElement(nums []int, val int) int {
	firstInvalid := len(nums)
	lastValid := 0

	for lastValid != firstInvalid {
		if nums[lastValid] == val {
			firstInvalid--
			nums[lastValid] = nums[firstInvalid]
			continue
		}

		lastValid++
	}

	return lastValid
}