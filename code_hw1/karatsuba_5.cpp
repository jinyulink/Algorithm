#include<bits/stdc++.h>
using namespace std;
//所有数字都是从低到高 比如string "123" 表示数字321
string add(string a, string b)
{
    int m = a.size(), n = b.size();
    if(m == 0) return b;
    if(n == 0) return a;
    int i = 0, j = 0, c = 0;
    string res;
    while(i < m && j < n)
    {
        int num = a[i] - '0' + b[j] - '0' + c;
        c = num/10;
        res += (char)(num%10 + '0');
        i++;
        j++;
    }
    while(i < m)
    {
        int num = a[i] - '0' + c;
        c = num/10;
        res += (char)(num%10 + '0');
        i++;
    }
    while(j < n)
    {
        int num = b[j] - '0' + c;
        c = num/10;
        res += (char)(num%10 + '0');
        j++;
    }
    if(c > 0)
        res += '1';
    return res;
}
//不考虑出现负数可能出现的情况
string sub(string a, string b)
{
    int m = a.size(), n = b.size();
    if(m == 0 || n == 0) return "0";
    int i = 0, j = 0, c = 0;
    string res;
    while(i < m && j < n)
    {
        int num = (a[i] - '0') - (b[j] - '0') - c;
        if(num < 0)
        {
            c = 1;
            num += 10;
        }
        else c = 0;
        res += (char)(num%10 + '0');
        i++;
        j++;
    }
    while(i < m)
    {
        int num = a[i] - '0' - c;
        if(num < 0)
        {
            c = 1;
            num += 10;
        }
        else c = 0;
        res += (char)(num%10 + '0');
        i++;
    }
    while(j < n)
    {
        int num = - b[j] + '0' - c;
        if(num < 0)
        {
            c = 1;
            num += 10;
        }
        else c = 0;
        res += (char)(num%10 + '0');
        j++;
    }
    //cout << "res = " << res << endl;
    int k = res.size() -1;
    while(k >= 0  && res[k] == '0')
        k--;
    return res.substr(0,k+1);
}
string mul(string a, string b)
{
    int m = a.size(), n = b.size();
    string res;
    if(m == 0 && n == 0) return "0";
    else if(m == 1 && n == 1)
    {
        int num = (a[0]-'0')*(b[0]-'0');
        res = to_string(num);
        reverse(res.begin(),res.end());
        return res;
    }
    int len = max(m,n);
    while(m < len)
    {
        a.push_back('0');
        m++;
    }
    while(n < len)
    {
        b.push_back('0');
        n++;
    }
    int mid = len/2;
    if(len%2 == 1)
        mid += 1;
    string A = a.substr(mid), B = a.substr(0,mid);
    string C = b.substr(mid), D = b.substr(0,mid);
    string AC = mul(A,C);
    // cout << A << " * " << C << " = " << AC << endl;
    string BD = mul(B,D);
    // cout << B << " * " << D << " = " << BD << endl;
    string M0 = add(A,B);//A+B
    // cout << A << " + " << B << " = " << M0 << endl;
    string M1 = add(C,D);//C+D
    // cout << C << " + " << D << " = " << M1 << endl;
    string M2 = mul(M0,M1);
    // cout << M0 << " * " << M1 << " = " << M2 << endl;
    string M3 = sub(M2,AC);
    // cout << M2 << " - " << AC << " = " << M3 << endl;
    M3 = sub(M3,BD);
    // cout << "M3" << " - " << BD << " = " << M3 << endl;
    if(BD.size() > mid)
    {
        M3 = add(M3,BD.substr(mid));
        BD = BD.substr(0,mid);
    }
    if(M3.size() > mid)
    {
        AC = add(AC,M3.substr(mid));
        M3 = M3.substr(0,mid);
    }
    res = BD+M3+AC;
    return res;
}
int main()
{
    freopen("number.txt", "r" , stdin);
    freopen("karatsuba.txt", "a", stdout);
    string num1, num2, res, num1t, num2t;
    cin >> num1 >> num2;
    num1t=num1; num2t=num2;
    auto start = chrono::high_resolution_clock::now();
    for(int ii=0;ii<200;ii++)
    {
        num1=num1t; num2=num2t;
        if(num1.size() == 0 || num2.size() == 0)
        {
            cout << 0 << endl;
            return 0;
        }
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        res = mul(num1,num2);
        reverse(res.begin(),res.end());
        int i = 0;
        while(i < res.size() && res[i] == '0')
            i++;
        res = res.substr(i);
    }
    // cout<<res<<'\n';
    auto finish = chrono::high_resolution_clock::now();
    cout << (chrono::duration_cast<chrono::nanoseconds>(finish-start).count())/200<< "\n";
    return 0;
}