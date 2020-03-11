class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hmap = dict()
        for i in range(len(nums)):
            if nums[i] not in hmap:
                hmap[nums[i]] = i
        for i in range(len(nums)):
            key = target - nums[i]
            if (key) in hmap:
                if hmap[key] != i:
                    return [i, hmap[key]]
