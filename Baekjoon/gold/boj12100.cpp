#include <bits/stdc++.h>

using namespace std;
#define MAX 1000001

int N;
int MAP[21][21];
int res;

void show() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << MAP[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void move(int arr[][21]) {
    for(int i = 0; i < N; i++) {
        deque<int> dq;
        bool isAlreadyMerge = false;
        for(int j = 0; j < N; j++) {
            if(arr[i][j] != 0) {
                if(!dq.empty() && dq.back() == arr[i][j] && isAlreadyMerge == false){
                    dq.pop_back();
                    dq.push_back(arr[i][j] * 2);
                    isAlreadyMerge = true;
                }else{
                    dq.push_back(arr[i][j]);
                    isAlreadyMerge = false;
                }
                arr[i][j] = 0;
            }
        }

        int index = 0;
        while(!dq.empty()){
            arr[i][index++] = dq.front();
            dq.pop_front();
        }
    }
}

void rotation(int arr[][21]) {
    int temp[21][21];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            temp[j][N - 1 - i] = arr[i][j];
    memcpy(arr, temp, sizeof(temp));
}

void DFS(int cnt) {
    if(cnt == 5) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if(res < MAP[i][j]) res = MAP[i][j];
            }
        }
        return;
    }

    int temp[21][21];
    cout << "[" << cnt << "]\n";
    show();
    for(int i = 0; i < 4; i++) {
        memcpy(temp, MAP, sizeof(MAP)); // origin -> copy
        move(MAP);
        DFS(cnt + 1);
        memcpy(MAP, temp, sizeof(MAP)); // copy -> origin
        rotation(MAP);
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

    DFS(0);
    cout << res;

    return 0;
}

