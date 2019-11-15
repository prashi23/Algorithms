class Solution {
public:
    vector <int > stringtovector(string s) {
        vector<int> v;
        for(auto i : s) {
            v.push_back((int)i - 48);
        }
        return v;
    }
    
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        string s;
        vector <string> v;
        
        s = "";
        for(int i = 0; i < cells.size(); i++) {
            s += (cells[i] == 0 ? '0' : '1');
        }
        
        v.push_back(s);
        
        bool counter = false;
        int x = -1;
        
        for(int i = 1; i <= N; i++) {
            s = "";
            for(int j = 0; j < cells.size(); j++) {
                if(j == 0 || j == cells.size() - 1)s += '0';
                else {
                    s += (v[i-1][j-1] == v[i-1][j+1] ? '1' : '0');
                }
            }
            
            for(int j = 0; j < v.size(); j++) {
                if(v[j] == s) {
                    x = j;
                    counter = true;
                    break;
                }
            }
            if(counter)break;
            else v.push_back(s);
        }
        
        if(x == -1)return stringtovector(v[v.size() - 1]);
        else {
            int cal = v.size() - x;
            N = (N - x)%cal;
            return stringtovector(v[x + N]);
        }
        
    }
};
