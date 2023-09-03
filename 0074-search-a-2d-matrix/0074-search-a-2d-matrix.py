class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        low, high = 0, len(matrix)-1
        while low < high - 1:
            mid = (high + low) // 2
            if matrix[mid][0] <= target:
                low = mid
            else:
                high = mid
        row = low
        if matrix[high][0] <= target:
            row = high
        low, high = 0, len(matrix[0])-1
        while low <= high:
            mid = (high + low) // 2
            if matrix[row][mid] == target:
                return True
            if matrix[row][mid] < target:
                low = mid + 1
            else:
                high = mid - 1
        return False
            