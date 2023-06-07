//ford folkerson's algorithm, finding maximum flow
//time complexity: O(f*m) //flow, edge
//augmenting path 找使flow增加最大之path
//
#include<bits/stdc++.h>
#define IO cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false)
#define INF 0x3f3f3f3f
#define pii pair<int,int>
#define F first
#define S second
using namespace std;
int n, s, t, c; //node source sink edge
int G[110][110];
bool vis[110];
int parent[110];
int dis[110];
int max_flow = 0;
bool bfs(int s, int t)
{
    memset(vis, 0, sizeof vis);
    memset(parent, -1, sizeof parent);
    memset(dis, 0, sizeof dis);

    priority_queue<pii> pq;
    pq.push({0, s});

    while(!pq.empty())
    {
        pii t = pq.top();
        pq.pop();
        int cn = t.S; //current node
        int w = t.F; //weight;
        if(vis[cn])  continue;
        vis[cn] = true;
        for(int v = 1; v <= n; v++)
        {
            if(dis[v] < G[cn][v] && !vis[v])
            {
                dis[v] = G[cn][v];
                parent[v] = cn;
                pq.push({dis[v], v});
            }
        }
    }
    return vis[t];
}
int main()
{
    IO;
    freopen("testcase.in", "r" , stdin);
    freopen("output_ff.txt", "a", stdout);
    cin>>n>>s>>t>>c;
    for(int i = 0; i < c; i++)
    {
        int u, v, w;
        cin>>u>>v>>w;
        G[u][v] = w;
    }
    while(bfs(s, t))
    {
        int path_flow = INF;

        for(int v = t; v != s; v = parent[v])
        {
            int u = parent[v];
            path_flow = min(path_flow, G[u][v]);
        }

        for(int v = t; v != s; v = parent[v])
        {
            int u = parent[v];
            G[u][v] -= path_flow;
            G[v][u] += path_flow;
        }

        max_flow += path_flow;
        cout<<path_flow<<'\n';
    }
    cout<<max_flow<<'\n';
    cout <<(double)clock() / CLOCKS_PER_SEC<<'\n';
    return 0;
}