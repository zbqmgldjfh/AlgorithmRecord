#include <bits/stdc++.h>
using namespace std;
#define MAX 1001
#define MOD 1000000007

string A, B;

int DP[MAX][MAX];
void print(int i, int j) {
    if(i <= 0 || j <= 0){
        return;
    }
    if(A[i-1] == B[j-1]){
        print(i-1, j-1);
        cout << A[i-1];
    }else{
        DP[i-1][j] > DP[i][j-1] ? print(i-1, j) : print(i, j-1);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);

    string str = "";
    cin >> A >> B;
    int aLen = A.length();
    int bLen = B.length();

    for(int i = 1; i <= aLen; i++) {
        for(int j = 1; j <= bLen; j++) {
            if(A[i-1] == B[j-1]) {
                DP[i][j] = DP[i-1][j-1] + 1;
            }else{
                DP[i][j] = max(DP[i][j-1], DP[i-1][j]);
            }
        }
    }
    cout << DP[aLen][bLen] << "\n";
    print(aLen, bLen);

    return 0;
}

