#include<iostream>
#include<vector>

using namespace std;

template <typename t>

class Stack{
    vector <t> st;
public:
    Stack(int ini_size=4){
        st.reserve(ini_size);
    }
    void push(int d){
        st.push_back(d);
    }
    t pop(){
        t top = st[st.size()-1];
        st.pop_back();
        return top;
    }
    t top(){
        t top = st[st.size()-1];
        return top;
    }
    int st_size(){
        return st.size();
    }
    void display(){
        for(int i=0;i<st.size();i++)
            cout<<st[i]<<" ";
        cout<<endl;
    }
};

int main(){
    Stack <float> s;
     cout<<"Size- "<<s.st_size()<<endl;
     s.push(1);
     s.push(2);
     s.push(3);
     s.push(4);
     s.push(5);
     s.push(6);
     s.display();
     cout<<"Size- "<<s.st_size()<<endl;
     cout<<s.pop()<<endl;
     cout<<"Size- "<<s.st_size()<<endl;
     s.display();
     cout<<s.top()<<endl;
     s.display();

    return 0;
}
