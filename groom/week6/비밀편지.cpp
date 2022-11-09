#include <bits/stdc++.h>

using namespace std;

int T;

string makeList(int len, string key) {
    string temp = key;
    while (temp.size() < len) {
        temp += key;
    }
    return temp;
}

char enCode(char ch, int num) {
    if(isupper(ch)) {
        int index = ((ch - 'A') + num) % 26;
        return 'A' + index;
    } else {
        int index = ((ch - 'a') + num) % 26;
        return 'a' + index;
    }
}

char deCode(char ch, int num) {
    if(isupper(ch)) {
        int index = ((ch - 'A') + (26 - num)) % 26;
        return 'A' + index;
    } else {
        int index = ((ch - 'a') + (26 - num)) % 26;
        return 'a' + index;
    }
}

string calculate(char command, string str, string list) {
    int len = str.length();
    string temp = "";

    if (command == 'E') {
        for (int i = 0; i < len; i++) {
            if (!isalpha(str[i])) {
                temp.push_back(str[i]);
            } else {
                int shiftCount = int(list[i]) % 26;
                temp.push_back(enCode(str[i], shiftCount));
            }
        }
    } else {
        for (int i = 0; i < len; i++) {
            if (!isalpha(str[i])) {
                temp.push_back(str[i]);
            } else {
                int shiftCount = int(list[i]) % 26;
                temp.push_back(deCode(str[i], shiftCount));
            }
        }

    }
    return temp;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str, key;

    cin >> T;
    cin.ignore();
    for (int i = 0; i < T; i++) {
        getline(cin, str);
        getline(cin, key);

        char op = key[0];
        key = key.substr(2);
        string list = makeList(str.length(), key);
        cout << calculate(op, str, list) << "\n";
    }

    return 0;
}
