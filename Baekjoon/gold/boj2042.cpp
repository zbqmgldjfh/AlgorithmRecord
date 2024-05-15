#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using namespace std;

int N, M, K;
long long arr[1000001];
long long* tree;

void init(int node, int start, int end) {
    if (start == end) {
        tree[node] = arr[start];
    } else {
        init(node * 2, start, (start + end) / 2);
        init(node * 2 + 1, ((start + end) / 2) + 1, end);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
}

void update(int node, int start, int end, int target_idx, long long value) {
    if (target_idx < start || end < target_idx) {
        return;
    }

    if (start == end) {
        arr[target_idx] = value;
        tree[node] = value; // 구간합 갱신
        return;
    }

    update(node * 2, start, (start + end) / 2, target_idx, value);
    update(node * 2 + 1, (start + end) / 2 + 1, end, target_idx, value);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

long long query(int node, int start, int end, int left, int right) {
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) {
        return tree[node];
    }
    long long lsum = query(node * 2, start, (start + end) / 2, left, right);
    long long rsum = query(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
    return lsum + rsum;
}

int main(int argc, char **argv) {
    fastio;

    //freopen("input.txt", "r", stdin);
    cin >> N >> M >> K;

    int height = ceil(log2(N));
    tree = new long long[1 << (height + 1)];

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    init(1, 0, N - 1);

    int cmd;
    for (int i = 0; i < M + K; i++) {
        cin >> cmd;

        if (cmd == 1) { // 값 변경하기
            int index;
            long long val;
            cin >> index >> val;
            update(1, 0, N - 1, index - 1, val);
        } else if (cmd == 2) { // 합 구하기
            int left, right;
            cin >> left >> right;
            cout << query(1, 0, N - 1, left - 1, right - 1) << '\n';
        }
    }

    return 0;
}
