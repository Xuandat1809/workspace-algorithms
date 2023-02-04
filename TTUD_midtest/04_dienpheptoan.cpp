/*Cho dãy gồm n số nguyên a1, ... , an(2 <= n <= 30) và 1 số nguyên b. Một
lời giải là 1 cách điền các phép toán + hoặc - giữa 2 số nguyên đứng cạnh nhau
trong dãy a1, ...,an sao cho giá trị của biểu thức thu được bằng b
Ví dụ: với n = 6, b = 12 và a1 = 3, a2 = 2, a3 = 7, a4 = 5, a5 = 2, a6 = 3.
Khi đó có 3 lời giải:
3-2+7+5+2-3=12
3+2+7-5+2+3=12
3+2+7+5-2-3=12
Input
Dong 1: chứa số nguyen dương n và số nguyên b ( 1<= n <= 50, -10000 <= b <= 10000)
Dong 2: chứa dãy a1,...,an(-1000 <= ai <= 1000)
Output
Số lời giải tìm đc
*/
#include <bits/stdc++.h>

using namespace std;

int n, b, a[100];

int lui(int i, int s){
    if (i == n){
        if (s == b) return 1;
        return 0;
    }
    int ss = s + a[i];
    int ans = 0;
    ans += lui(i+1, ss);
    ss = s - a[i];
    ans += lui(i+1, ss);
    return ans;
}

int main()
{
    cin>>n>>b;
    for (int i=0; i<n; i++) cin>>a[i];
    cout<<lui(1, a[0]);

    return 0;
}
