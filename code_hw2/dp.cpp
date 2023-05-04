//Algorithm hw2 
//第二種作法 dp
#include<bits/stdc++.h>
#define IO cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false)
#define ll long long 
#define vt vector
#define pb push_back
#define pll pair<ll,ll>
#define F first
#define S second
#define MOD 2552
using namespace std;
const ll maxn = 1e3+10;
ll t,w,h,k,q,a,b,c,d;
ll p[maxn][maxn];
vt<pair<pll,pll>> block;
vt<pair<pll,pll>> getSubA(pair<pll,pll> A,vt<pair<pll,pll>> block_list)
{
    vt<pair<pll,pll>> res;
    for(auto i:block_list)
    {
        if(A.F>=i.S)
            res.pb(i);
    }
    return res;
}
ll dp(pll s,vt<pair<pll,pll>> block_list)
{
    if(block_list.empty())
        return p[s.F][s.S];
    pair<pll,pll> A=block_list[block_list.size()-1];
    // cout<<A.F.F<<' '<<A.F.S<<' '<<A.S.F<<' '<<A.S.S<<'\n';
    block_list.pop_back();
    vt<pair<pll,pll>> subA=getSubA(A,block_list);
    return (dp({s.F,s.S},block_list)+(p[A.F.F][A.F.S]-dp(A.F,subA))*p[s.F-A.S.F][s.S-A.S.S])%MOD;
}
int main()
{
    IO;
    cin>>t;
    while(t--)
    {
        cin>>w>>h>>k;
        p[0][0]=1;
        for(int i=0;i<=w;i++)   p[i][0]=1;
        for(int i=0;i<=h;i++)   p[0][i]=1;
        for(int i=1;i<=w;i++)
            for(int j=1;j<=h;j++)
                p[i][j]=(p[i-1][j]+p[i][j-1])%MOD;
        while(k--)
        {
            block.clear();
            cin>>q;
            while(q--)
            {
                cin>>a>>b>>c>>d;
                block.pb({{a,b},{c,d}});
            }
            block.pb({{w,h},{w,h}});
            sort(block.begin(),block.end(),[](pair<pll,pll> a,pair<pll,pll> b){
                return ((h-a.S.F)*(h-a.S.F)+(h-a.S.S)*(h-a.S.S))>((h-b.S.F)*(h-b.S.F)+(h-b.S.S)*(h-b.S.S));
            });
            // for(auto i:block)
            // {
                // cout<<i.F.F<<' '<<i.F.S<<' '<<i.S.F<<' '<<i.S.S<<'\n'; 
            // }
            ll res=(p[w][h]-dp({w,h},block))%MOD;
            cout<<p[w][h]<<' '<<dp({w,h},block)<<'\n';
        }
    }
    return 0;
}