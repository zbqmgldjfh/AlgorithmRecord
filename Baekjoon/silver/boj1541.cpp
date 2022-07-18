#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define MAX 55

int res;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);

    string str;
    cin >> str;

    int len = str.length();

    bool isMinus = false;
    int num = 0;
    for (int i = 0; i <= len; i++) {
        if (str[i] == '+' || str[i] == '-' || i == len) {
            if (isMinus){
                res -= num;
            } else {
                res += num;
            }
            num = 0;

            if (str[i] == '-') isMinus = true; // '-'등장 시 체크
        } else {
            num *= 10;
            num += str[i] - '0';
        }
    }

    cout << res;

    return 0;
}

