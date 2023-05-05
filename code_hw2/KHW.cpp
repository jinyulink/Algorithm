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
ll path[maxn][maxn],block[maxn][maxn];
void init()
{
    memset(path,0,sizeof path);
    memset(block,0,sizeof block);
}
int main()
{
    freopen("testcase.in", "r" , stdin);
    freopen("output.txt", "w", stdout);
    // IO;
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
            path[0][0]=1;
            for(int i=1;i<=w;i++)
            {
                if(block[i][0]) path[i][0]=0;
                else    path[i][0]=path[i-1][0];
            }
            for(int i=1;i<=h;i++)
            {
                if(block[0][i]) path[0][i]=0;
                else    path[0][i]=path[0][i-1];
            }
            for(int i=1;i<=w;i++)
            {
                for(int j=1;j<=h;j++)
                {
                    if(block[i][j]==3)
                        path[i][j]=0;
                    else if(block[i][j]==1)
                        path[i][j]=path[i][j-1]%MOD;
                    else if(block[i][j]==2)
                        path[i][j]=path[i-1][j]%MOD;
                    else
                        path[i][j]=(path[i-1][j]+path[i][j-1])%MOD;
                }
            }
            cout<<path[w][h]<<'\n';
        }
    }
    cout <<(double)clock() / CLOCKS_PER_SEC;
    return 0;
}