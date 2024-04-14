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

#define MAX 50001
using namespace std;

int DP[4001];

int main() {
    fastio;

    int n, a, b, c;
    cin >> n >> a >> b >> c;

    memset(DP, -1, sizeof(DP));
    DP[0] = 0;
    for (int i = 1; i <= n; i++) {
        if (i - a >= 0) {
            if(DP[i - a] != -1) {
                if (DP[i - a] >= DP[i]) {
                    DP[i] = DP[i - a] + 1;
                }
            }
        }

        if (i - b >= 0) {
            if(DP[i - b] != -1) {
                if (DP[i - b] >= DP[i]) {
                    DP[i] = DP[i - b] + 1;
                }
            }
        }

        if (i - c >= 0) {
            if(DP[i - c] != -1) {
                if (DP[i - c] >= DP[i]) {
                    DP[i] = DP[i - c] + 1;
                }
            }
        }
    }

    cout << DP[n];

    return 0;
}
