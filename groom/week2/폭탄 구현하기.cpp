#include <bits/stdc++.h>
using namespace std;

int n, k;
int arr[21][21];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for(int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;

        arr[x][y] += 1;
        for(int j = 0; j < 4; j++) {
            int nx = x + dx[j];
            int ny = y + dy[j];
            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            arr[nx][ny] += 1;
        }
    }

    int sum = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            sum += arr[i][j];
        }
    }

    cout << sum;
    return 0;
}