#include <bits/stdc++.h>
using namespace std;
#define MAX 101
#define MOD 1000

int N;
long long B;
typedef vector<vector<int>> matrix;

matrix operator*(matrix &a, matrix &b) {
    matrix temp(N, vector<int>(N));

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < N; k++) {
                temp[i][j] += a[i][k] * b[k][j];
            }
            temp[i][j] %= MOD;
        }
    }
    return temp;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);

    cin >> N >> B;

    matrix res(N, vector<int>(N));
    matrix mat(N, vector<int>(N));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> mat[i][j];
        }
        res[i][i] = 1;
    }

    while(B > 0) {
        if(B % 2 == 1) {
            res = res * mat;
        }
        mat = mat * mat;
        B /= 2;
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}

