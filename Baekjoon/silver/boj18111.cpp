#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define MAX 501

int N, M, B;
int MAP[MAX][MAX];
int low = 300, high = -1;
int resultHeight=-1, resultTime=INT_MAX;

void solve(int height) {
    int box = B;
    int time = 0;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(MAP[i][j] > height) {
                box += (MAP[i][j] - height);
                time += 2 * (MAP[i][j] - height);
            }
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(MAP[i][j] < height) {
                box -= (height - MAP[i][j]);
                time += (height - MAP[i][j]);
            }
        }
    }

    if(box >= 0) {
        if(time <= resultTime) {
            resultTime = time;
            resultHeight = height;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);

    cin >> N >> M >> B;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> MAP[i][j];
            low = min(low, MAP[i][j]);
            high = max(high, MAP[i][j]);
        }
    }

    for(int h = low; h <= high; h++) {
        solve(h);
    }

    cout << resultTime << " " << resultHeight;

    return 0;
}

