#include <bits/stdc++.h>
using namespace std;
#define MAX 2001

int N, M;
int arr[MAX];
int DP[MAX][MAX];
vector<pair<int, int>> vec;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);

    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    cin >> M;
    for(int i = 0; i < M; i++){
        int from, to;
        cin >> from >> to;
        vec.push_back({from, to});
    }

    for(int i = 1; i <= N; i++) {
        DP[i][i] = 1; // 길이가 1인 경우
    }

    for(int i = 1; i < N; i++) {
        if(arr[i] == arr[i+1]){
            DP[i][i+1] = 1; // 길이가 2인 경우
        }
    }

    for(int i = 2; i < N; i++) { // 차이 나는 칸의 수
        for(int j = 1; j <= N-i; j++) {
            if(arr[j] == arr[j+i] && DP[j+1][j+i-1]) {
                DP[j][j+i] = 1;
            }
        }
    }

    for(int i = 0; i < M; i++) {
        cout << DP[vec[i].first][vec[i].second] << "\n";
    }

    return 0;
}

