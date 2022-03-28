#include <bits/stdc++.h>
using namespace std;
#define MAX 1001
#define MOD 1000000007

int N;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);

    cin >> N;
    vector<int> vec(N);
    for(int i = 0; i < N; i++){
        int num;
        cin >> num;
        vec[i] = num;
    }
    sort(vec.begin(), vec.end());

    int left = 0;
    int right = N-1;

    int resA, resB;

    int min = 2147000000;
    while(left < right) {
        int midValue = vec[left] + vec[right];
        if(min > abs(midValue)) {
            min = abs(midValue);
            resA = vec[left];
            resB = vec[right];
        }

        if(midValue < 0) {
            left++;
        }else if(midValue >= 0) {
            right--;
        }
    }

    cout << resA << " " << resB;

    return 0;
}

