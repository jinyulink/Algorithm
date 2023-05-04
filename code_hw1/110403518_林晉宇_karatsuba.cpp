//演算法 程式作業 1
//110403518 林晉宇
//karatsuba
#include<bits/stdc++.h>
#define IO cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false)
using namespace std;

string a,b,res; //calculate a*b

string appendZero(string &s,int &n)
{
    while(n--)  s = "0" + s;
    return s;
}

string remZero(string &s)
{
    reverse(s.begin(),s.end());
    for(int i=s.length()-1;i>=0;i--)
    {
        if(s[i]=='0')   s.pop_back();
        else    break;
    }
    if(s.empty())   return "0";
    else    
    {
        reverse(s.begin(),s.end());
        return s;
    }
}

string addXY(string &x,string &y)
{
    if(x.length() > y.length())
        y = appendZero(y, x.length() - y.length());
    else
        x = appendZero(x, y.length() - x.length());
    int carry = 0, sum;
    string res = "";
    for(int i=x.length()-1;i>=0;i--)
    {
        sum = (x[i]-'0')+(y[i]-'0')+carry;

        if(sum>9)
        {
            res = to_string(sum%10) + res;
            carry = sum/10;
        }
        else
        {
            res = to_string(sum) + res;
            carry=0;
        }
    }
    if(carry)   res = to_string(carry) + res;
    return res;
}

string mul10(string &s, int &n)
{
    while(n--)  s = s + "0";
    return s;
}

string subXY(string& x, string& y)
{
    if(x.length()>y.length())
        y = appendZero(y, x.length()-y.length());
    else
        x = appendZero(x, y.length()-x.length());
    
    string res = "";
    int bo = 0, a, b;
    for(int i=x.length()-1;i>=0;i--)
    {
        a=x[i]-'0'; b=y[i]-'0';
        if(bo==1)    a--;
        if(a>=b)
        {
            res = to_string(a-b) + res;
            bo = 0;
        }
        else
        {
            a += 10;
            res = to_string(a-b) + res;
            bo=1;
        }
    }
    return remZero(res);
}

string karatsuba(string& x,string& y)
{
    if(x.length()==1 && y.length()==1)
        return to_string((x[0]-'0')*(y[0]-'0'));
    int n1=x.length(),n2=y.length();
    if(x.length()>y.length())
        y=appendZero(y, x.length()-y.length());
    else
        x=appendZero(x, y.length()-x.length());
    if(x.length()%2)
    {
        x = "0" + x;
        y = "0" + y;
    }

    string a,b,c,d,ac,bd,abcd; //abcd = (a+b) * (c+d)
    int n = x.length();

    a = x.substr(0, x.length()/2);
    b = x.substr(x.length()/2);
    c = y.substr(0, y.length()/2);
    d = y.substr(y.length()/2);

    ac = karatsuba(a,c);
    bd = karatsuba(b,d);
    abcd = karatsuba(addXY(a,b),addXY(c,d));

    return addXY(addXY(mul10(ac, n), mul10(subXY(subXY(abcd,ac), bd), n/2)), bd);
}

int main()
{
    IO;
    // freopen("number.txt", "r" , stdin);
    // freopen("karatsuba.txt", "a", stdout);
    cin>>a>>b;
    auto start = chrono::high_resolution_clock::now();
    for(int i=0;i<200;i++)
    {
        if(a=="0"||b=="0")  cout<<"0\n";
        else    res=remZero(karatsuba(a,b));
    }
    cout<<res<<'\n';
    auto finish = chrono::high_resolution_clock::now();
    cout << (chrono::duration_cast<chrono::nanoseconds>(finish-start).count())/200<< " ns\n";
    return 0;
}