class Solution(object):
    def partitionLabels(self, S):
		#Get the interval for the first letter in the string
        intervals = [[S.index(S[0]),S.rindex(S[0])]]
        lastInterval = intervals[-1]

		#Loop through the rest of the unique letters
        for letter in list(dict.fromkeys(S))[1:]:
            #If overlaps, merge the new interval with the last interval
            if lastInterval[1] >=  S.index(letter): 
                lastInterval[1] = max(lastInterval[1],S.rindex(letter))
            #Otherwise (if they do not overlap), append it as a new interval and set that as the new lastInterval
            else:
                intervals.append([S.index(letter),S.rindex(letter)])
                lastInterval = intervals[-1]

		#Get the length for each interval and return that list
        return list(map(lambda t: t[1]-t[0]+1, intervals))
