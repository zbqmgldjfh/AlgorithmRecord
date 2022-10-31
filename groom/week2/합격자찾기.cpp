#include <bits/stdc++.h>
using namespace std;

int t;

double calculateAvg(vector<int>& vec) {
    int len = vec.size();
    double sum = 0;
    for(auto e : vec) {
        sum += e;
    }

    return sum / len;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    for(int i = 0; i < t; i++) {
        int n;
        vector<int> temp;
        cin >> n;
        for(int i = 0; i < n; i++) {
            int score;
            cin >> score;
            temp.push_back(score);
        }

        double avg = calculateAvg(temp);
        int cnt = 0;
        for(auto e : temp) {
            if(e >= avg) {
                cnt++;
            }
        }
        cout << cnt << "/" << temp.size() << "\n";
    }

    return 0;
}