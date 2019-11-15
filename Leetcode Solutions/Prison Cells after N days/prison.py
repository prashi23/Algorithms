class Solution(object):
    def prisonAfterNDays(self, cells, N):
        """
        :type cells: List[int]
        :type N: int
        :rtype: List[int]
        """
        max_loop_size = pow(2,len(cells))        

        # Find the loop size - can't be higher than 2^len(cells)
        (_, loop_size) = self.loopPrisonAfterNDays(cells, max_loop_size, True)

        # Find the minimum number of iterations to get the same results as N
        n = (N - 1) % loop_size + 1
        (cells, _) = self.loopPrisonAfterNDays(cells, n, False)
        
        return cells
    
    def loopPrisonAfterNDays(self, cells, n, enable_loop_sizing=False):
        # Used when enable_loop_sizing=True #
        init_cells = []
        loop_size = len(cells) #Set to worst-case value
        # ################################# #

        for day in xrange(n):
            output = []
            for i, cell in enumerate(cells):
                if i == 0 or i == len(cells) - 1:
                    output.append(0)
                else:
                    if cells[i-1] == cells[i+1]:
                        output.append(1)
                    else:
                        output.append(0)
            cells = output
            
            #Used when enable_loop_sizing=True
            if enable_loop_sizing == True:
                if cells == init_cells:
                    loop_size = day
                    break

                if day == 0:
                    init_cells = cells

        return (cells, loop_size)
