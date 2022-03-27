#include <bits/stdc++.h>
using namespace std;
#define MAX 1001
#define INF 987654321

int A, B;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);

    cin >> A >> B;

    int cnt = 0;
    while(true) {
        cnt++;
         if(A == B){
            cout << cnt;
            break;
        }else if(A > B){
            cout << -1;
            break;
        }

        if (B % 10 == 1) {
            B--;
            B /= 10;
        } else if (B % 2 == 0) {
            B /= 2;
        }else{
            cout << -1;
            break;
        }
    }

    return 0;
}

