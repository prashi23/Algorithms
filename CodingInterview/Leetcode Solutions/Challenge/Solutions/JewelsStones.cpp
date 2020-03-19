class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int res = 0;
        unordered_set<char> setJewels(J.begin(), J.end());
        for(char s: S)
            if(setJewels.count(s))
                res++;
        return res;
        
    }
};
