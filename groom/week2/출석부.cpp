#include <bits/stdc++.h>
using namespace std;
#define ALL(X) X.begin(), X.end()

int N, k;

class Person {
public:
    string name;
    double height;
public:
    Person(string name, float height) : name(name), height(height) {}

    bool operator < (const Person& temp) {
        if(name == temp.name) {
            return height < temp.height;
        } else {
            return name < temp.name;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> k;
    vector<Person> pList;
    for(int i = 0; i < N; i++) {
        string name;
        double height;
        cin >> name >> height;
        pList.push_back(Person(name, height));
    }

    sort(ALL(pList));
    cout<<fixed;
    cout.precision(2);
    cout << pList[k-1].name << " " << pList[k-1].height;

    return 0;
}