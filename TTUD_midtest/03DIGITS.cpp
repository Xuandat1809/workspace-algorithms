/*Cho một số nguyên dương N. Hãy đếm số cách điền giá trị cho các ký tự H, U, S, T, O, I, C sao cho
tổng số có 4 chữ số HUST và số có 5 chữ số SOICT bằng N: HUST + SOICT = N. Lưu ý, hai ký tự
khác nhau phải nhận giá trị khác nhau.
Dữ liệu vào
Dữ liệu đầu vào có cấu trúc như sau:
• Dòng 1 ghi số bộ dữ liệu test T (1 ≤ T ≤ 50)
• Dòng i + 1 (i = 1, . . . , T) ghi giá trị N của bộ test thứ i
Kết quả
Trên mỗi dòng ghi ra kết quả của bộ dữ liệu test tương ứng.
*/
#include<bits/stdc++.h>
using namespace std;
const int MAX = 20;
int n;
int x[MAX]; // x[0] = H, x[1] = U, x[2] = S, x[3] = T, x[4] = O, x[5] = I, x[6] = C
bool visited[MAX];
int cnt;

void input(){
    cin >> n;
    for(int i=0; i<MAX; i++)
        visited[i] = false;
    cnt = 0;
}

bool check(int a, int i){
    if(a == 0 && i == 0) return false;
    if(a == 2 && i == 0) return false;
    if(visited[i]) return false;

    return true;
}

void solution(){
    int hust = x[0] * 1000 + x[1] * 100 + x[2] * 10 + x[3];
    int soict = x[2] * 10000 + x[4] * 1000 + x[5] * 100 + x[6] * 10 + x[3];

    if(hust + soict == n) cnt++;
}

void TRY(int a){
    for(int i=0; i<10; i++){
        if(check(a,i)){
            visited[i] = true;
            x[a] = i;

            if(a == 6) solution();
            else TRY(a+1);

            visited[i] = false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T;
    cin >> T;

    while(T>0){
        input();
        TRY(0);
        cout << cnt << endl;
        T--;
    }
    return 0;
}
