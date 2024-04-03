#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define rep(i, k) for(i = 0; i < k; i++)
#define REP(i, n, k) for(i = n; i < k; i++)
#define eof while (cin >> n)
#define cinstr cin >> str
#define getstr getline (cin,str)
#define vi vector <int>
#define pii pair <int,int>
#define mii map <int,int>
#define pb push_back
#define in insert
#define llu unsigned long long
#define lld long long
#define U unsigned int

using namespace std;
int n;

void show() {

}

int main() {
    fastio;
    cin >> n;

    int minPos = 2147000000, maxPos = -1;
    int x, h;
    vector<pii > vec;
    for (int i = 0; i < n; i++) {
        cin >> x >> h;
        vec.pb({x, h});
    }

    int reachLeft[n];
    int reachRight[n];
    for (int i = 0; i < n; i++) {
        int leftPos = vec[i].first - vec[i].second;
        int rightPos = vec[i].first + vec[i].second;

        for (int j = i; j >= 0; j--) {
            if (leftPos <= vec[j].first) {
                leftPos = min(leftPos, vec[j].first - vec[j].second);
                reachLeft[i] = min(reachLeft[i], j);
            }
        }

        for (int j = i; j < n; j++) {
            if (rightPos >= vec[j].first) {
                rightPos = min(rightPos, vec[j].first + vec[j].second);
                reachRight[i] = min(reachRight[i], j);
            }
        }
    }

    int DP[n];
    for (int i = 0; i < n; i++) {
        DP[i] = 2147000000;
    }
    DP[0] = 1;
    for (int i = 0; i < n; i++) {
        if (reachLeft[i] < 1) {
            DP[i] = min(DP[i], 1);
        } else {
            DP[i] = min(DP[i], DP[reachLeft[i] - 1] + 1);
        }

        for (int j = 0; j < i; j++) {
            if (reachRight[j] >= i) {
                if (j == 0) DP[i] = min(DP[i], 1);
                else {
                    DP[i] = min(DP[i], DP[j - 1] + 1);
                }
            }
        }
    }

    for(int i = 0; i < n; i++) {
        cout << DP[i] << " ";
    }

    cout << DP[n - 1];
    return 0;
}
