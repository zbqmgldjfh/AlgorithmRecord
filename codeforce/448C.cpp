#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using namespace std;

int arr[5001];

int go(int start, int end) {
    int vertical = end - start + 1;

    int min_height = 2147000000;
    for (int i = start; i <= end; i++) {
        min_height = min(min_height, arr[i]);
    }

    int cnt = min_height;
    for (int i = start; i <= end; i++) {
        arr[i] -= min_height;
    }

    int temp_start = start;
    for (int i = start; i <= end; i++) {
        if (arr[i] == 0) i++;
        else {
            temp_start = i; // 시작 포인트
            while (arr[i] != 0) i++; // 처음으로 0이 나오는곳 까지 탐색
            cnt += go(temp_start, i - 1); // 재귀 호출
        }
        i -= 1; // 이 루프가 끝나면 i++ 이 실행되므로 미리 1을 빼준다
    }

    return cnt < vertical ? cnt : vertical;
}

int main() {
    fastio;

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    cout << go(1, n);

    return 0;
}
