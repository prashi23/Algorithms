class Solution:
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        banset = set(banned)
        paragraph = paragraph.replace(",", " ")
        for c in "!?',;.'":
            paragraph = paragraph.replace(c, " ")
        count = collections.Counter(word for word in paragraph.lower().split())
        
        ans, best = '', 0
        for word in count:
            if count[word] > best and word not in banset:
                ans, best = word, count[word]
        return ans
