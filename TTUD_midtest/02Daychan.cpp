/*Cho dãy số nguyên a = a1, a2,...,an. Một dãy con của a được định nghĩa là 
dãy a(i), a(i+1),... a(j). Một dãy con được gọi là dãy con chẵn nếu tổng phần tử của nó là số chẵn.
Lập trình đếm số lượng Q các dãy chẵn của a
Input:
dòng 1: chứa số nguyên dương (1 <= n <= 1000000)
dòng 2: chứa a1, a2,..., an (0 <= a(i) <= 1000)
Output: ghi giá trị Q modulo 10^9 +7
*/
#include <bits/stdc++.h>

using namespace std;

int n, a, ans = 0;
int d0 = 0, d1 = 0, s = 0;

int main()
{
    cin>>n;
    for (int i=0; i<n; i++){
            cin>>a;
            s += a;
            s %= 2;
            if (s>0){
                ans += d1;
                d1 += 1;
                ans %= 1000000007;
            } else {
                d0 += 1;
                ans += d0;
                ans %= 1000000007;
            }
    }

    cout<<ans;

    return 0;
}
