#include <bits/stdc++.h>

using namespace std;

vector<string> split(string input, string delimiter) {
    vector<string> ret;
    long long pos = 0;
    string token = "";

    while ((pos = input.find(delimiter)) != string::npos) {
        token = input.substr(0, pos);
        ret.push_back(token);
        input.erase(0, pos + delimiter.length());
    }

    ret.push_back(input);
    return ret;
}

string convert_num(int n, int k) {
    string res = "";

    while(n > 0) {
        res += (n % k) + '0';
        n /= k;
    }

    reverse(res.begin(), res.end());
    return res;
}

bool isPrime(long long n) {
    if(n < 2) {
        return false;
    }
    for(long long i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;

    // 211020101011
    string num = convert_num(n, k);

    unsigned long len = num.length();
    vector<string> res = split(num, "0");
    for(auto e : res) {
        if(!e.empty() && isPrime(stoll(e))){
            answer++;
        }
    }

    return answer;
}