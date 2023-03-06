//Algorithm HW1
//Given two sorted array, design an algorithm to compute min|x[i]-y[j]|
//Thought: Initially, run through the first array, and for each iteration we get x[i],
// we use binary search to search the cloest value from x[i] in second array.
//Time complexity: O(n*logm) //x:1~n y:1~m
//A linear way to approach: two pointer with time complexity of O(n+m)
//太菜了 沒直接想到two pointer的方式..
//以後看到有單調性的 就往binary search 跟 two pointer的方向想!
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int x[10]={3,20,21,25,30,55,70,76,79,86};
int y[20]={11,16,18,29,31,32,36,39,40,51,61,62,63,65,69,73,74,75,95,97};
int main()
{   
    int i=0,j=0,res=0x3f3f3f3f;
    while(i<10&&j<20)
    {
        res=min(res,abs(x[i]-y[j]));
        if(x[i]<=y[j])  i++;
        else    j++;
    }
    cout<<res<<'\n';
    return 0;
}

//pseudo code
