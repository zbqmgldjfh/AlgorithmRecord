#include <bits/stdc++.h>

using namespace std;
#define MAX 51

int N, M;
int res;
int parent[MAX];
vector<int> adj[MAX];
vector<int> know_person;

int findParent(int num) {
    if(parent[num] == num) {
        return num;
    }
    return parent[num] = findParent(parent[num]);
}

void joinGroup(int a, int b){
    int pA = findParent(a);
    int pB = findParent(b);

    if(pA != pB) {
        parent[pA] = pB;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);

    cin >> N >> M;

    for(int i = 1; i <= N; i++){
        parent[i] = i;
    }

    int knowPerson = 0;
    cin >> knowPerson;

    int num;
    for (int i = 0; i < knowPerson; i++) {
        cin >> num;
        know_person.push_back(num);
    }
    for (int i = 1; i <= M; i++) {
        cin >> num;
        int personNumber;
        for (int j = 0; j < num; j++) {
            cin >> personNumber;
            adj[i].push_back(personNumber);
        }
    }

    for (int i = 1; i <= M; i++){
        int N1 = adj[i][0];
        for (int j = 1; j < adj[i].size(); j++){
            int N2 = adj[i][j];
            joinGroup(N1, N2);
        }
    }

    for(int i = 1; i <= M; i++) {
        bool flag = false;
        for(int j = 0; j < adj[i].size(); j++) {
            int N1 = adj[i][j];
            for(int k = 0; k < know_person.size(); k++){
                int N2 = know_person[k];
                if(findParent(N1) == findParent(N2)) {
                    flag = true;
                    break;
                }
            }
            if(flag == true) break;
        }
        if(flag == false) {
            res++;
        }
    }

    cout << res;

    return 0;
}

