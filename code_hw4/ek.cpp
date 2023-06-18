//edmond karp's algorithm, finding maximum flow
//time complexity: O(NM^2)
#include<bits/stdc++.h>
#define IO cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false)
#define INF 0x3f3f3f3f
using namespace std;
int n, s, t, c; //node source sink edge
int G[110][110];
bool vis[110];
int parent[110];
int max_flow = 0;
bool bfs(int s, int t)
{
    memset(vis, 0, sizeof vis);

    queue<int> q;
    q.push(s);
    vis[s] = true;
    parent[s] = -1;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i = 1; i <= n; i++)
        {
            if(!vis[i] && G[u][i])
            {
                q.push(i);
                parent[i] = u;
                vis[i] = true;
            }
        }
    }

    return vis[t];
}
int main()
{
    IO;
    freopen("testcase.in", "r" , stdin);
    freopen("output_ek.txt", "a", stdout);
    cin>>n>>s>>t>>c;
    for(int i = 0; i < c; i++)
    {
        int u, v, w;
        cin>>u>>v>>w;
        G[u][v] = w;
    }
    double START,END; START = clock();
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
    END = clock();
    cout << (END - START) / CLOCKS_PER_SEC << endl;
    cout<<START<<' ';
    cout<<END<<'\n';
    return 0;
}