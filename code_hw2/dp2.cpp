//Algorithm hw2
//作法二 dp
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
ll p[maxn][maxn],dp[maxn];
vt<pair<pll,pll>> block;
vt<vt<int>> sub;
ll path(ll i)
{
    ll q_path=0;
    for(int j:sub[i])
    {
        // if(!dp[j])
        //     dp[j]=path(j);
        q_path+=dp[j]*p[block[i].F.F-block[j].S.F][block[i].F.S-block[j].S.S];
    }
    return p[block[i].F.F][block[i].F.S]-q_path;
}
int main()
{
    freopen("testcase.in", "r" , stdin);
    freopen("output1.txt", "w", stdout);
    // IO;
    t=1;
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
            cin>>q;
            memset(dp,0,sizeof dp);
            sub.clear();    sub.resize(q+1);
            block.clear();
            for(int i=0;i<q;i++)
            {
                cin>>a>>b>>c>>d;
                block.pb({{a,b},{c,d}});
            }
            block.pb({{w,h},{w,h}});
            sort(block.begin(),block.end(),[](pair<pll,pll> a,pair<pll,pll> b){
                return ((h-a.S.F)*(h-a.S.F)+(h-a.S.S)*(h-a.S.S))>((h-b.S.F)*(h-b.S.F)+(h-b.S.S)*(h-b.S.S));
            });
            for(int i=0;i<=q;i++)
            {
                vt<int> tmp;
                for(int j=0;j<i;j++)
                {
                    if(block[j].S.F<=block[i].F.F&&block[j].S.S<=block[i].F.S)
                        tmp.pb(j);
                }
                sub[i]=tmp;
            }
            dp[0]=p[block[0].F.F][block[0].F.S];
            // cout<<dp[0]<<' '<<path(0)<<' ';
            // cout<<path(q)%MOD<<'\n';
            for(int i=0;i<=q;i++){
                dp[i]=path(i);
                dp[i]%=2552;
                dp[i]+=2552;
                // cout<<dp[i]%2552<<' ';
            }
            cout<<dp[q]<<'\n';
        }
    }
    cout <<(double)clock() / CLOCKS_PER_SEC<<'\n';
    return 0;
}