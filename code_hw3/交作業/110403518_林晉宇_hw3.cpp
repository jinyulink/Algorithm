#include<bits/stdc++.h>
#define IO cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false)
#define INF 0x3f3f3f3f
#define pii pair<int,int>
#define F first
#define S second
using namespace std;
int cnt=0;
int k,n; // cache size / n request sequence
void init(vector<int>& rs, vector<int>& record, int n)
{
    unordered_map<int,int> hash;
    for(int i=1; i<=n; i++)
    {
        cin>>rs[i];
    }
    for(int i=n;i>0;i--)
    {
        if(!hash[rs[i]])    
        {
            record[i] = INF + (cnt++);
        }
        else
        {
            record[i] = hash[rs[i]];
        }
        hash[rs[i]] = i;
    }
}
int main()
{
    IO;
    // freopen("testcase.in", "r" , stdin);
    // freopen("output2.txt", "a", stdout);
    cin>>k>>n;
    vector<int> rs(n+1,0), record(n+1,0);
    init(rs,record,n); //輸入及建立record表

    unordered_map<int,bool> cache;
    int cur_cache_size = 0;
    priority_queue<pii> pq;
    for(int i=1; i<=n; i++)
    {
        if(cache[rs[i]]) // cache hit;
        {
            cout<<"hit\n";
            pq.push({record[i], rs[i]});
        }
        else if(cur_cache_size < k) // cache miss;
        {
            cur_cache_size++;
            cache[rs[i]] = true;
            pq.push({record[i], rs[i]});
            cout<<"miss\n";
        }
        else // cache miss -> evicted;
        {
            pii t = pq.top();
            while(!cache[t.S]) // 如果該值已不存在cache裡面;
            {
                pq.pop();
                t = pq.top();
            }
            int ev = t.S; // 要被丟掉的值
            cache[rs[i]] = 1;
            pq.push({record[i], rs[i]});
            cout<<"miss\nevict "<<ev<<'\n';
        }
    }
    // cout <<(double)clock() / CLOCKS_PER_SEC<<'\n';
    return 0;
}