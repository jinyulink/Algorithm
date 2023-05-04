#include<bits/stdc++.h>
using namespace std;
void edit(string& s)
{
    s[0]='1';
    cout<<s.length()<<'\n';
}
int main()
{
    string s;
    cin>>s;
    edit(s);
    cout<<s;
    return 0;
}