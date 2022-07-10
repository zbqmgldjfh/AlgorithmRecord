#include <bits/stdc++.h>
#include <iostream>

using namespace std;
#define MAX 101

int N;

class Point{
public:
    double x, y;
public:
    Point(double x, double y): x(x), y(y) {};

    double getDistance(Point other) {
        double dx = (x - other.x) * (x - other.x);
        double dy = (y - other.y) * (y - other.y);
        return sqrt(dx + dy);
    }
};

class Line{
public:
    int a, b;
    double dist;
public:
    Line(int a, int b, double dist) : a(a), b(b), dist(dist) {}

    bool operator < (const Line& temp) const {
        return this->dist < temp.dist;
    }
};

int parent[MAX];

int find(int u) {
    if(parent[u] == u) {
        return u;
    }
    return parent[u] = find(parent[u]);
}

void Join(int a, int b) {
    int ap = find(a);
    int bp = find(b);

    if(ap != bp) {
        parent[ap] = bp;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "rt", stdin);

    vector<Point> pVector;
    vector<Line> lVector;

    for(int i = 0; i < MAX; i++) {
        parent[i] = i;
    }

    double a, b;
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> a >> b;
        pVector.push_back(Point(a, b));
    }

    for(int i = 0; i < pVector.size(); i++) {
        Point& nowP = pVector[i];

        for(int j = i+1; j < pVector.size(); j++) {
            double dist = nowP.getDistance(pVector[j]);
            lVector.push_back(Line(i, j, dist));
        }
    }

    sort(lVector.begin(), lVector.end());

    vector<Line> lines;

    for(int i = 0; i < lVector.size(); i++) {
        Line line = lVector[i];

        if(find(line.a) == find(line.b)) {
            continue;
        }

        Join(line.a, line.b);
        lines.push_back(line);
    }

    double sum = 0;
    for(int i = 0; i < lines.size(); i++) {
        sum += lines[i].dist;
    }
    cout.precision(3);
    cout << sum;

    return 0;
}

