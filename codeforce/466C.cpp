#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define scase sf ("%d",&tc)
#define sn sf ("%d",&n)
#define whilecase while (tc--)
#define eof while (cin >> n)
#define forloop for (pos=1; pos<=tc; pos++)
#define rep (i=0; i<n; i++)
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
#define endl "\n"

using namespace std;

int N;
lld arr[500001];
lld pre[500001];

int main() {
    fastio;

    lld sum = 0;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        sum += arr[i];
        pre[i] = pre[i - 1] + arr[i];
    }

    if (sum % 3 == 0) {
        lld divided = sum / 3;
        lld doubleDivided = divided * 2;

        lld cnt = 0;
        lld tempCnt = 0;
        for (int i = 1; i <= N - 1; i++) {
            if (pre[i] == doubleDivided && i > 1 && i < N) {
                cnt += tempCnt;
            }
            if (pre[i] == divided) tempCnt++;
        }
        cout << cnt;
    } else {
        cout << 0;
    }

    return 0;
}
