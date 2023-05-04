//Algorithm HW2 O(KHW) -> 1e10
//第一種作法 組合學
#include<bits/stdc++.h>
#define IO cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false)
#define ll long long
#define MOD 2552
#define vt vector
#define pb push_back
using namespace std;
const ll maxn = 1e3+10;
ll t,w,h,k,q,a,b,c,d; // w,h 1000 | k 10000
ll dp[maxn][maxn],block[maxn][maxn];
void init()
{
    memset(dp,0,sizeof dp);
    memset(block,0,sizeof block);
}
int main()
{
    IO;
    t=1;
    while(t--)
    {
        cin>>w>>h>>k;
        while(k--)
        {
            init();
            cin>>q;
            while(q--)
            {
                cin>>a>>b>>c>>d; //障礙
                if(a!=c)
                    block[max(a,c)][max(b,d)]+=1; //代表x
                else if(b!=d)
                    block[max(a,c)][max(b,d)]+=2; //代表y
            }
            dp[0][0]=1;
            for(int i=1;i<=w;i++)
            {
                if(block[i][0]) dp[i][0]=0;
                else    dp[i][0]=dp[i-1][0];
            }
            for(int i=1;i<=h;i++)
            {
                if(block[0][i]) dp[0][i]=0;
                else    dp[0][i]=dp[0][i-1];
            }
            for(int i=1;i<=w;i++)
            {
                for(int j=1;j<=h;j++)
                {
                    if(block[i][j]==3)
                        dp[i][j]=0;
                    else if(block[i][j]==1)
                        dp[i][j]=dp[i][j-1]%MOD;
                    else if(block[i][j]==2)
                        dp[i][j]=dp[i-1][j]%MOD;
                    else
                        dp[i][j]=(dp[i-1][j]+dp[i][j-1])%MOD;
                }
            }
            cout<<dp[w][h]<<'\n';
        }
    }
    return 0;
}