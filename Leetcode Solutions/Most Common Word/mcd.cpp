class Solution
{
public:
    /*
    *   Transforms a string of letters to all lowercase
    *   @param s: the string to convert to lowercase
    * 
    *   @return: @s transformed into a lowercase only string
    */
    string strToLower(string s)
    {
        for (int n = 0; n < s.length(); n++)
        {
            if (s[n] >= 65 && s[n] <= 90)
            {
                s[n] = s[n] + 32;
            }
        }

        return s;
    }
    string mostCommonWord(string paragraph, vector<string> &banned)
    {
        int nextWordIndex = paragraph.find_first_not_of("!?',;. ");

        unordered_map<string, int> countBin;

        while (nextWordIndex != -1)
        {
            int nextEndIndex = paragraph.find_first_of("!?',;. ", nextWordIndex);

            if (nextEndIndex == -1)
            {
                //the rest of the string is a word
                countBin[strToLower(paragraph.substr(nextWordIndex))]++;
            }
            else
            {
                countBin[strToLower(paragraph.substr(nextWordIndex, nextEndIndex - nextWordIndex))]++;
            }
            nextWordIndex = paragraph.find_first_not_of("!?',;. ", nextEndIndex);
        }

        int max = 0;
        string maxStr;

        //delete every banned word from our hash table so we don't get a potentially bad max val.
        for (auto bannedWord : banned)
        {
            countBin.erase(bannedWord);
        }

        //find max valued element in our hash table
        for (auto currWord : countBin)
        {
            if (currWord.second > max)
            {
                max = currWord.second;
                maxStr = currWord.first;
            }
        }

        return maxStr;
    }
};
