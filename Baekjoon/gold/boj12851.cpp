#include <bits/stdc++.h>

using namespace std;
#define MAX 100001

int N, K;
int res;
int cnt;
bool visited[MAX];

void BFS(int num) {
    queue<pair<int, int>> q;

    visited[num] = true;
    q.push({num, 0});
    
    while(!q.empty()) {
        int nowPosition = q.front().first;
        int nowSec = q.front().second;
        q.pop();
        visited[nowPosition] = true;

        if(cnt && nowPosition == K && nowSec == res) cnt++;

        if(!cnt && nowPosition == K) { // 처음 동생한테 도착한경우
            res = nowSec;
            cnt++;
        }

        if(nowPosition + 1 < MAX && !visited[nowPosition+1]) {
            q.push({nowPosition+1, nowSec+1});
        }

        if(nowPosition - 1 >= 0 && !visited[nowPosition-1]) {
            q.push({nowPosition-1, nowSec+1});
        }

        if(nowPosition * 2 < MAX && !visited[nowPosition*2]) {
            q.push({nowPosition*2, nowSec+1});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);

    cin >> N >> K;
    BFS(N);

    cout << res << "\n" << cnt;

    return 0;
}

