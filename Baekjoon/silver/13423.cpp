#include <bits/stdc++.h>
#include <algorithm>
#define fastio ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

int T, N;

int main() {
    fastio;

    cin >> T;
    while(T--) {
        cin >> N;

        vector<int> vec;
        int num;
        for(int i = 0; i < N; i++) {
            cin >> num;
            vec.push_back(num);
        }

        sort(vec.begin(), vec.end());
        set<int> s(vec.begin(), vec.end());

        int cnt = 0;
        int size = vec.size();
        for(int i = 0; i < size - 2; i++) {
            for(int j = i + 1; j < size - 1; j++) {
                int diff = vec[j] - vec[i];
                int target = vec[j] + diff;

                if(s.find(target) != s.end()) {
                    cnt++;
                }
            }
        }

        cout << cnt << "\n";
    }

    return 0;
}
