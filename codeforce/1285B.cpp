#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int test_case;
    long long n;
    cin >> test_case;
    while (test_case--)
    {
        cin >> n;
        long long score_arr[100001];
        long long P[100001]; // prefix sum array
        // initialize Prefix sum array
        P[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> score_arr[i];
            P[i] = P[i - 1] + score_arr[i];
        }

        long long yasser_score = P[n];
        int ans = 1;
        long long min_of_p = 0;
        int min_index = 0;
        long long *Adel_comb = new long long[n + 1];
        for (int i = 1; i <= n; i++)
        {
            if (min_index == 0 && i == n)
            { //조각이 전체인 경우. 이 경우는 문제 조건에 의하여 불가능.
                continue;
            }
            Adel_comb[i] = P[i] - min_of_p; // i에서 끝나는 조각 중 가장 합이 큰 조각의 점수
            if (min_of_p >= P[i])
            { // 더 작은 값 있다면 업데이트
                min_index = i;
                min_of_p = P[i];
            }
            // cout << i << "에서 끝나는 최대 조각의 합: " << Adel_comb[i] << ", yasser : " << yasser_score << endl;
            if (Adel_comb[i] >= yasser_score)
            {
                ans = 0;
                break;
            }
        }
        if (ans == 1)
        {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }

    return 0;
}