#include<bits/stdc++.h>
#define IO cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false)
#define INF 0x3f3f3f3f
#define pii pair<int,int>
#define F first
#define S second
using namespace std;
int k,n; // cache size / n request sequence
void init(int rs[], int record[], int n)
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
            record[i] = INF;
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
    cin>>k>>n;
    int rs[n], record[n];
    init(rs,record,n); //輸入及建立record表

    unordered_map<int,bool> cache;
    int cur_cache_size = 0; // 當前cache有多少元素
    priority_queue<pii> pq;
    for(i = 1 ~ n) // 1-based
    {
        if(cache[request[i]]) // cache hit
            pq.push({record[i], request[i]});
        else if(cur_cache_size < k)
        {
            cur_cache_size++;
            cache[request[i]] = true;
            pq.push({record[i], request[i]});
        }
        else
        {
            int ev = pq.top().second; // 要evict的request值
            cache[request[i]] = true;
            pq.push({record[i], request[i]});
        }
    }


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
    return 0;
}