#include<bits/stdc++.h>
#define IO cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false)
#define INF 0x3f3f3f3f
#define F first
#define S second
using namespace std;
int k,n; // cache size / n個request sequence
int main()
{
    IO;
    cin>>k>>n;
    int rs[n]; int record[n]; //
    unordered_map<int,int> hash; //
    for(int i=1;i<=n;i++)    cin>>rs[i];
    for(int i=n;i>0;i--) //O(n)
    {
        if(!hash[rs[i]])    record[i]=INF;
        else    record[i]=hash[rs[i]];
        hash[rs[i]]=i;
    }
    for(int i=1;i<=n;i++)   cout<<record[i]<<' ';
    
    unordered_map<int,bool> cache;
    int cache_size=0;
    priority_queue<pair<int,int>> pq;
    for(int i=1;i<=n;i++)
    {
        if(cache[rs[i]]) //cache hit
        {
            cout<<"hit\n";
            pq.push({record[i],rs[i]});
        }
        else if(cache_size<k) //cache miss
        {
            cache_size++;
            cache[rs[i]]=1;
            pq.push({record[i],rs[i]});
            cout<<"miss\n";
        }
        else //miss -> evicted
        {
            pair<int,int> t=pq.top();
            while(!cache[t.S])
            {
                pq.pop();
                t=pq.top();
            }
            int ev=t.S;
            cache[rs[i]]=1;
            pq.push({record[i],rs[i]});
            cout<<"miss\n";
            cout<<"evict "<<ev<<'\n';
        }
    }
    return 0;
}   