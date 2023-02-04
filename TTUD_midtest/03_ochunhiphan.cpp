/*Bài 3: ô chữ nhị phân
Cho 1 bảng kích thước NxN trong đó mỗi ô chứa 1 bit 0 hoặc 1. Cho 1 tập D
các từ(mỗi từ là 1 xâu nhị phân độ dài <= 50). Một từ trong bảng là 1 dãy
các bit trong 1 số ô liên tiếp cạnh trong trên 1 hàng nào đó của bảng.
Đếm số từ trong bảng xuất hiện trong tập D.

Input: 
Dòng 1: số nguyên dương N(1 <= N <= 100)
Dòng i + 1(i = 1,..., N): chứa dòng thứ i của bảng( chứa N bits 0 hoặc 1)
Dòng N+2: chứa số nguyên dương M(1 <= M <= 10^5)
Dòng N+2+i(i=1,2,...M): chứa 1 từ (xâu nhị phân) của tập D

Output: 
Ghi ra số lượng từ của bảng xuất hiện trong D
*/
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

string s;
int n, a[105][105], m;

int main()
{
    Node* Root;
    Node* root;
    Node* newNode = new Node();
    newNode->data = -1;
    newNode->left = newNode->right = NULL;
    Root = newNode;
    cin>>n;
    for (int i=0; i<n; i++) for (int j=0; j<n; j++) cin>>a[i][j];
    cin>>m;
    for (int i=0; i<m; i++){
            cin>>s;
            root = Root;
            for (int j=0; j<s.length(); j++){
                if (s[j] == '0'){
                    if (root->left == NULL){
                        Node* newNode = new Node();
                        newNode->data = 0;
                        newNode->left = newNode->right = NULL;
                        root->left = newNode;
                    }
                    root = root->left;
                } else {
                    if (root->right == NULL){
                        Node* newNode = new Node();
                        newNode->data = 0;
                        newNode->left = newNode->right = NULL;
                        root->right = newNode;
                    }
                    root = root->right;
                }
            }
            root->data += 1;
    }

    int ans = 0;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++){
            root = Root;
            for (int k=j; k<n; k++){
                if (a[i][k] == 0){
                    root = root->left;
                } else {
                    root = root->right;
                }
                if (root == NULL) break;
                if (root->data > 0) ans += 1;
            }
        }
    cout<<ans<<"\n";

    return 0;
}
