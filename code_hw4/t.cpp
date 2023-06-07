int parent[] -> -1; //初始化
bool vis[] -> 0; //初始化

queue<int> q;
q.push(s);

while(!q.empty()){
    int u = q.pop();

    if(vis[u])  continue;
    vis[u] = true;

    for(int v = 所有u指向的邊){
        if(!vis[v] and u->v邊權大於0){
            parent[v] = u;
            q.push(v);
        }
    }
}