func lengthOfLastWord(s string) int {
	i := len(s) - 1
	for i >= 0 {
		if s[i] != ' ' {
			break
		}
		i--
	}
	var ans int = 0
	for i >= 0 && s[i] != ' ' {
		ans++
		i--
	}

	return ans
}
