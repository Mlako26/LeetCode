class TimeMap:
    def __init__(self):
        self.dict = {}

    def set(self, key: str, value: str, timestamp: int) -> None:
        if key not in self.dict:
            self.dict[key] = []
        self.dict[key].append([value, timestamp])


    def get(self, key: str, timestamp: int) -> str:
        res = ""
        values = self.dict.get(key, [])
        low, high = 0, len(values)-1
        while low <= high:
            mid = (low + high) // 2
            if values[mid][1] > timestamp:
                high = mid - 1
            else:
                res = values[mid][0]
                low = mid + 1
        return res