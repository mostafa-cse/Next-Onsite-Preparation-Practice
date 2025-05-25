#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x, y, z;
    Point(int _x, int _y, int _z) {
        x = _x;
        y = _y;
        z = _z;
    }
    Point() {
        x = 0;
        y = 0;
        z = 0;
    }
    double dist(const Point &other) const {
        return sqrt((x - other.x) * (x - other.x) +
                    (y - other.y) * (y - other.y) +
                    (z - other.z) * (z - other.z));
    }
};

int main() {
    vector<Point> points;
    vector<int> result(10, 0);
    int x, y, z;

    while (cin >> x >> y >> z) {
        points.push_back(Point(x, y, z));
    }

    for (int i = 0; i < points.size(); i++) {
        double minDist = DBL_MAX;
        for (int j = 0; j < points.size(); j++) {
            if (i != j) {
                double d = points[i].dist(points[j]);
                minDist = min(minDist, d);
            }
        }

        if (minDist < 1.0) {
            result[0]++;
        } else if (minDist < 2.0) {
            result[1]++;
        } else if (minDist < 3.0) {
            result[2]++;
        } else if (minDist < 4.0) {
            result[3]++;
        } else if (minDist < 5.0) {
            result[4]++;
        } else if (minDist < 6.0) {
            result[5]++;
        } else if (minDist < 7.0) {
            result[6]++;
        } else if (minDist < 8.0) {
            result[7]++;
        } else if (minDist < 9.0) {
            result[8]++;
        } else if (minDist < 10.0) {
            result[9]++;
        }
    }

    for (int i = 0; i < result.size(); i++) {
        printf("%4d", result[i]);
    }
    cout << endl;
    return 0;
}
