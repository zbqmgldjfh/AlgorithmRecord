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

int main() {
    fastio;
    int n;
    cin >> n;

    int oneCnt = 0;
    int twoCnt = 0;
    int threeCnt = 0;
    int fourCnt = 0;

    int num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        switch (num) {
            case 1:
                oneCnt++;
                break;
            case 2:
                twoCnt++;
                break;
            case 3:
                threeCnt++;
                break;
            case 4:
                fourCnt++;
                break;
            default:
                break;
        }
    }

    int res = fourCnt;
    if (oneCnt < threeCnt) {
        if(oneCnt != 0) {
            res += oneCnt;
            threeCnt -= oneCnt;
            oneCnt = 0;
        } else {
            res += threeCnt;
            threeCnt = 0;
        }

        res += (twoCnt / 2) + (twoCnt % 2);
        res += threeCnt;
    } else if (oneCnt > threeCnt) {
        res += threeCnt;
        oneCnt -= threeCnt;
        threeCnt = 0;

        if(oneCnt % 4 == 0 && twoCnt % 2 == 0) {
            res += (oneCnt / 4);
            res += (twoCnt / 2);
        } else {
            res += (oneCnt / 4);
            res += (twoCnt / 2);
            int temp = (2 * (twoCnt % 2) + oneCnt % 4);

            if(temp % 4 == 0) {
                res += (temp / 4);
            } else {
                res += (temp / 4) + 1;
            }
        }
    } else {
        res += threeCnt;
        res += (twoCnt / 2) + (twoCnt % 2);
    }

    cout << res;

    return 0;
}