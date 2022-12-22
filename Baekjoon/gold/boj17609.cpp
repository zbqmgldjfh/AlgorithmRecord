#include <bits/stdc++.h>

using namespace std;

int T;

int isPalindrome(int left, int right, int check, string str) {
    while (left < right) {
        if (str[left] != str[right]) {
            if(check == 0) {
                if(isPalindrome(left + 1, right, 1, str) == 0 || isPalindrome(left, right - 1, 1, str) == 0) {
                    return 1;
                }
                return 2;
            } else return 2;
        } else {
            left++;
            right--;
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);

    cin >> T;
    for (int i = 0; i < T; i++) {
        string str;
        cin >> str;

        int res = isPalindrome(0, str.length() - 1, 0, str);
        cout << res << "\n";
    }

    return 0;
}

