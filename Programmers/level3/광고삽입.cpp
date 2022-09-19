#include <bits/stdc++.h>

using namespace std;
using ll = long long;

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

int convert(string str) {
    stringstream ss(str);
    int HH, MM, SS;
    char temp;
    ss >> HH >> temp >> MM >> temp >> SS;
    return SS + (60 * MM) + (3600 * HH);
}

string de_convert(int n){
    string ret="";

    int s = n%60; n/=60;
    int m = n%60; n/=60;
    int h = n;

    char buf[10];
    sprintf(buf, "%02d:%02d:%02d", h, m, s);

    return buf;
}

vector<pair<int, int>> vec;

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    int total_play_sec = convert(play_time);
    int total_adb_sec = convert(adv_time);

    if(total_play_sec == total_adb_sec) {
        return "00:00:00";
    }

    int total_sec[360000] = {0, }; // 10시간
    for(string log : logs) {
        int start_sec = convert(log.substr(0, 8));
        int end_sec = convert(log.substr(9, 8));

        for (int i = start_sec; i < end_sec; i++) {
            total_sec[i]++;
        }
    }

    ll curr_sum = 0;
    for(int i = 0; i < total_adb_sec; i++) {
        curr_sum += total_sec[i];
    }

    ll max_sum = curr_sum;
    int max_idx = 0;
    for(int i = total_adb_sec; i < total_play_sec; i++) {
        curr_sum = curr_sum + total_sec[i] - total_sec[i - total_adb_sec];
        if(curr_sum > max_sum) {
            max_sum = curr_sum;
            max_idx = i - total_adb_sec + 1;
        }
    }

    return de_convert(max_idx);
}

