class Solution:
    # compute the next sum square
    def check(self, x: int):
        s = 0
        while x != 0:
            s += (x%10)**2
            x //= 10
        return s
		
    def isHappy(self, n: int) -> bool:
	    # regiester first element
        note = {n: 1}
		# repeat till a new check(n) occur second time in out "note" or if number became 1
        while n != 1:
            n = self.check(n)
            if n in note:
                return False
            note[n] = 1 # register every new computed sum
        return True
