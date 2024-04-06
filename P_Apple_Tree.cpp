#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int N=(int)1e6+5;
vector<int> adj[N];
vector<int> leaf;
void dfs(int curr,int par)
{
    bool child=false;  //mane ter kono child nai
    for(auto i: adj[curr])
    {
        if(i==par) continue;
        else child=true;  // i ta jodi par ar soman na hoy tahola ter child aceh and true kore dibo child ta
        dfs(i,curr);
        leaf[curr]+=leaf[i];
    }
    if(child==false)
    {
        leaf[curr]=1;
    }

}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0; i<=n; i++)  
        {
            adj[i].clear();
        }
        leaf.assign(n+2,0);
        for(int i=1;i<=n-1; i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(1,-1);
        int q;
        cin>>q;
        while(q--)
        {
            int x,y;
            cin>>x>>y;
            ll ans=1ll*leaf[x]*1ll*leaf[y];
            cout<<ans<<endl;
        }
    }
}