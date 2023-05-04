//Algorithm programming homework big number multiplication
//n2 traditional method
#include<bits/stdc++.h>
#define IO cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false)
#define ll long long
const ll maxn = 2e5+10;
using namespace std;
string n,m;
int num_dig;
int product[maxn];
clock_t s,e;
int main()
{
    IO;
    freopen("number.txt", "r" , stdin);
    freopen("n2.txt", "a", stdout);
    cin>>n>>m;
    // s=clock();
    auto start = chrono::high_resolution_clock::now();
    for(int i=0;i<10;i++)
    {
        memset(product,0,sizeof product);
        for(int i=n.length()-1;i>=0;i--)
        {
            for(int j=m.length()-1;j>=0;j--)
            {
                int ia=n.length()-1-i,ib=m.length()-1-j;
                product[ia+ib]+=(n[i]-'0')*(m[j]-'0');
                num_dig=max(num_dig,ia+ib);
                if(product[ia+ib]>=10)
                {
                    product[ia+ib+1]+=product[ia+ib]/10;
                    product[ia+ib]%=10;
                    num_dig=max(num_dig,ia+ib+1);
                }
            }
        }
    }
    // e=clock();
    // for(int i=num_dig;i>=0;i--) cout<<product[i];
    // cout<<'\n';
    // cout << '\n' << (double)clock() / CLOCKS_PER_SEC << " S";
    auto finish = chrono::high_resolution_clock::now();
    cout << (chrono::duration_cast<chrono::nanoseconds>(finish-start).count())/10<< "\n";
    return 0;
}