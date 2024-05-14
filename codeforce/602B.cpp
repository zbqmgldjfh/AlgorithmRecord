#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using namespace std;

int n;
int p[110000];

int main() {
    fastio;

    int ans = -1;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int num;
        cin >> num;

        if (p[num - 1] > p[num + 1])
            ans = max(ans, i - max(p[num + 1], p[num - 2]));
        else
            ans = max(ans, i - max(p[num + 2], p[num - 1]));

        p[num] = i;
    }

    cout << ans;

    return 0;
}