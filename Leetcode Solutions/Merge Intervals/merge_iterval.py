class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        ret = []
        for l, r in sorted(intervals):
            if ret and ret[-1][1] >= l:
                ret[-1] = (ret[-1][0], max(ret[-1][1], r))
            else:
                ret.append((l,r))
        return ret
