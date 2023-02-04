/*Gía cổ phiếu của 1 công ty được biểu diễn bởi dãy a1, a2,..., an
trong đó ai là giá cổ phiếu vào ngày i(i= 1,...,n). Tìm chuỗi ngày dài 
nhất trong đó giá cổ phiếu luôn tăng
Input: 
Dòng 1 :số nguyên dương n(1 <= n <= 1000000)
Dòng 2: ghi dãy số nguyên dương a1, a2, ..., an (1 <= ai <= 1000000)
Output: 
Độ dài của chuỗi ngày liên tiếp dài nhất trong đó giá cổ phiếu luôn tăng
*/
#include <bits/stdc++.h>

using namespace std;

int n, a[1000005];

int main()
{
    cin>>n;
    for (int i=0; i<n; i++) cin>>a[i];
    int d = 1, ans = 1;
    for (int i=1; i<n; i++){
        if (a[i] > a[i-1]) d+=1;
        else d = 1;
        ans = max(ans, d);
    }
    cout<<ans;
    return 0;
}
