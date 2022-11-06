#include <bits/stdc++.h>

using namespace std;

int N;
vector<string> nums;

string sum() {
    string str = "";
    for(int i = 0; i < N; i++) {
        if(i == 0) {
            str += nums[i];
            continue;
        }

        string before = nums.at(i-1);
        string now = nums.at(i);
        int beforeLen = before.size();
        if(before[beforeLen-1] == now[0]) {
            str += now[1];
        } else {
            str += now;
        }
    }
    return str;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    string num;
    for(int i = 0; i < N; i++) {
        cin >> num;
        nums.push_back(num);
    }

    string res = "10000000000000000";
    sort(nums.begin(), nums.end());
    do {

        string temp = sum();
        if(res.length() > temp.length()) {
            res = temp;
        } else if(res.length() == temp.length()) {
            long long a = stoll(res);
            long long b = stoll(temp);
            if(a > b) {
                res = temp;
            }
        }

    } while(next_permutation(nums.begin(), nums.end()));

    cout << res;

    return 0;
}
