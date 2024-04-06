#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    stack<string> st;
    for(int i=0; i<n; i++)
    {
        string s;
        cin>>s;
        st.push(s);
    }
    //pring reverse and handle duplicate
    set<string>ans;
    while(!st.empty())
    {
        if(ans.find(st.top())==ans.end())
        {
            ans.insert(st.top());
            string s1=st.top();
            if(s1.size() >2)
            {
                cout<<s1.substr(s1.size()-2);
            }
        }
        st.pop();
    }
}