#include <bits/stdc++.h>
using namespace std;
#define MAX 1001

int N;
long long vec[5000];
long long arr[3];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> vec[i];
    }
    sort(vec, vec + N);

    long long ans = LONG_LONG_MAX;
    for(int i = 0; i < N-2; i++) {
        int third = vec[i];
        int left = i+1;
        int right = N-1;
        while (left < right) {
            long long temp = third + vec[left] + vec[right];
            if(ans > llabs(temp)){
                ans = llabs(temp);
                arr[0] = third;
                arr[1] = vec[left];
                arr[2] = vec[right];
            }
            if (temp < 0) {
                left++;
            } else {
                right--;
            }
        }
    }
    cout << arr[0] << " " << arr[1] << " " << arr[2];

    return 0;
}

