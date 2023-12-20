func nextPermutation(nums []int) {
	i := len(nums) - 2
	for i >= 0 {
		if nums[i] < nums[i+1] {
			break
		}
		i--
	}

	if i == -1 {
		for j := i + 1; j < len(nums); j++ {
			mn := j
			for k := j; k < len(nums); k++ {
				if nums[k] < nums[j] {
					mn = k
				}
			}
			aux := nums[mn]
			nums[mn] = nums[j]
			nums[j] = aux
		}
        return
	}

	best := nums[i+1]
	idx := i + 1
	for j := i + 1; j < len(nums); j++ {
		if nums[j] > nums[i] && nums[j] < best {
			best = nums[j]
			idx = j
		}
	}

	aux := nums[idx]
	nums[idx] = nums[i]
	nums[i] = aux

	for j := i + 1; j < len(nums); j++ {
		mn := j
		for k := j+1; k < len(nums); k++ {
			if nums[k] < nums[mn] {
				mn = k
			}
		}
		aux = nums[mn]
		nums[mn] = nums[j]
		nums[j] = aux
	}
	return
}
