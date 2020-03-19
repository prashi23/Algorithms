class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> st;
        for(int i=0;i<emails.size();i++){
            string temp;
            for(char c : emails[i]){
                if(c=='+'||c=='@')break;
                if(c=='.')continue;
                temp+=c;
            }
            temp+=emails[i].substr(emails[i].find('@'));
            st.insert(temp);
        }
        return st.size();
    }
};
