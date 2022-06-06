#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define MAX 101
#define INF 987654321

int N;
int MAP[MAX][MAX];

void floyd() {
    for(int k = 0; k < N; k++) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(MAP[i][k] && MAP[k][j]) {
                    MAP[i][j] = 1;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);

    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> MAP[i][j];
        }
    }
    floyd();
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << MAP[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}

