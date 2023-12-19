func strStr(haystack string, needle string) int {
	var l int = 0

	for l < len(haystack)-len(needle)+1 {
		if haystack[l] == needle[0] {
			offset := 0
			for offset < len(needle) && haystack[l+offset] == needle[offset] {
				offset++
			}
			if offset == len(needle) {
				return l
			}
		}
		l++
	}

	return -1
}