#include <bits/stdc++.h>
using namespace std;
#define MAX 1000001

int N;
int vecIndex[MAX];
int arr[MAX];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    vector<int> vec;
    for(int i = 0; i < N; i++) {
        int num = arr[i];

        if(vec.size() == 0 || vec.back() < num) {
            vec.push_back(num);
            vecIndex[i] = vec.size()-1;
        }else{
            int cnt = lower_bound(vec.begin(), vec.end(), num) - vec.begin();
            vec[cnt] = num;
            vecIndex[i] = cnt;
        }
    }

    int len = vec.size();
    cout << len << "\n";

    vector<int> ans;
    int lastIndex = vec.size()-1;
    for (int i = N-1; i >= 0; i--){
        if (vecIndex[i] == lastIndex){
            ans.push_back(arr[i]);
            lastIndex--;
        }
    }

    for (int i = ans.size()-1; i >= 0; i--) {
        cout << ans[i] << " ";
    }

    return 0;
}

