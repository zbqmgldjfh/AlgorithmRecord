#include <bits/stdc++.h>
using namespace std;

int arr[100001][2];
int DP[100001][3]; // i번쨰를 j로 칠할때 비용

void reset(){
    memset(arr, 0, sizeof(arr));
    memset(DP, 0, sizeof(DP));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    while(N--){
        int num;
        cin >> num;

        for(int i = 0; i < num; i++){
            cin >> arr[i][0];
        }
        for(int i = 0; i < num; i++){
            cin >> arr[i][1];
        }

        DP[0][0] = 0;
        DP[0][1] = arr[0][0];
        DP[0][2] = arr[0][1];
        for(int i = 1; i < num; i++){
            DP[i][0] = max(DP[i-1][0], max(DP[i-1][1], DP[i-1][2]));
            DP[i][1] = max(DP[i-1][2], DP[i-1][0]) + arr[i][0];
            DP[i][2] = max(DP[i-1][1], DP[i-1][0]) + arr[i][1];
        }
        int res = -1;

        for(int i = 0; i < 3; i++){
            res = max(res, DP[num-1][i]);
        }

        cout << res << "\n";
        reset();
    }

    return 0;
}