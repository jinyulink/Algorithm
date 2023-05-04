//演算法 程式作業 1
//110403518 林晉宇
//傳統 n2
#include<bits/stdc++.h>
#define IO cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false)
const int maxn = 1e5+10;
using namespace std;
string n,m;
int num_dig;
int product[maxn];
int main()
{
    IO;
    // freopen("number.txt", "r" , stdin);
    // freopen("n2.txt", "a", stdout);
    cin>>n>>m;
    auto start = chrono::high_resolution_clock::now();
    for(int i=0;i<200;i++)
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
    for(int i=num_dig;i>=0;i--) cout<<product[i];
    cout<<'\n';
    auto finish = chrono::high_resolution_clock::now();
    cout << (chrono::duration_cast<chrono::nanoseconds>(finish-start).count())/200<< " ns\n";
    return 0;
}