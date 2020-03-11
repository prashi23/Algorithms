class Solution:
    # @param {integer[][]} matrix
    # @param {integer} target
    # @return {boolean}
    def searchMatrix(self, matrix, target):
        self.matrix = matrix
        for l in self.matrix:
            if target in l:
                return True
        return False
