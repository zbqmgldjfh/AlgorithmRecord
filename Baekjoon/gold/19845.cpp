#include <bits/stdc++.h>

using namespace std;

int N, Q;
int arr[250001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> Q;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int x, y;
    for (int i = 0; i < Q; i++) {
        cin >> x >> y;

        int rowCnt = arr[y - 1] - x + 1;
        if (rowCnt < 0) rowCnt = 0;

        int left = 0, right = N;
        while (left < right) {
            int mid = (left + right) / 2;

            if (arr[mid] < x) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        int colCnt = right - y;
        if (colCnt < 0) colCnt = 0;

        cout << rowCnt + colCnt << "\n";
    }

    return 0;
}
