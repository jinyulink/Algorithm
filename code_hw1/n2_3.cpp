#include <iostream>
#include <cstring>
#include<ctime>
using namespace std;


clock_t s,e;
//强调一下我这里的数组都比原来多开了5个是防止溢出

//s1和s2用来读入要做乘法的数
char s1[5005], s2[5005];
//n1和n2是用来倒着存输入的大整数的，ans是用来存储乘法运算后的结果的，ans的长度是由n1+n2决定的
int n1[5005], n2[5005], ans[10010];

//大整数乘法
int main(){
    freopen("number.txt", "r" , stdin);
    // freopen("n2.txt", "a", stdout);
    cin >> s1 >> s2;
    s=clock();
//    用下标为0的位值来存字符串的长度
    n1[0] = strlen(s1);
    n2[0] = strlen(s2);
//    用i去控制循环，用j去控制数组倒着存下输入的字符串
    for(int i = 0, j = n1[0]; i < n1[0]; i++, j--){
//s1是字符数组，要它变成数字，需要减去一个字符0，完成隐式转换，s2同
            n1[j] = s1[i] - '0';
    }
    for(int i = 0, j = n2[0]; i < n2[0]; i++, j--){
        n2[j] = s2[i] - '0';
    }

    ans[0] = n1[0] + n2[0] - 1;//图片中的x+y-1，得到最小的位数
//  这里和加法有些不同，两层循环是模拟竖式的性质决定的
    for(int i = 1; i <= n1[0]; i++){
        for(int j = 1; j <= n2[0]; j++){
            ans[i + j - 1] += n1[i] * n2[j];
        }
    }
    for(int i = 1; i <= ans[0]; i++){
        if(ans[i] > 9){
            ans[i + 1] += ans[i] / 10;
            ans[i] %= 10;
            if(ans[0] == i){
                ++ans[0];
            }
        }
    }
    e=clock();
//  将答案再倒回来输出结果
    for(int i = ans[0]; i > 0; i--){
        cout << ans[i];
    }
    cout <<endl;
    cout <<(double)(e-s) / CLOCKS_PER_SEC *1000000000<< "\n";
    return 0;
}