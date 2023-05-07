#include<bits/stdc++.h>
using namespace std;
int vis[1000],in[1000],low[1000];
vector<int>v[1000];
int timer;

void dfs(int node,int par)
{
    vis[node]=1;
    in[node]=timer;
    low[node]=timer;
    timer++;
    for(int chl:v[node])
    {
        if(chl==par)
            continue;
        if(vis[chl]==1)
        {
            low[node]=min(low[node],in[chl]);
        }
        else
        {
            dfs(chl,node);
            if(low[chl]>in[node])
        {
            cout<<"Bridge between :"<<node<<" ->"<<chl<<endl;
        }
        low[node]=min(low[node],low[chl]);
        }

    }
}


int main()
{
    int n,m,x,y;
    cin>>n>>m;
    while(m--)
    {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1,-1);
}
