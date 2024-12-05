#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

struct Rectangle {
    Point topLeft, bottomRight;
};

Rectangle intersect(Rectangle a, Rectangle b) {
    Rectangle res;
    res.topLeft.x = max(a.topLeft.x, b.topLeft.x);
    res.topLeft.y = max(a.topLeft.y, b.topLeft.y);
    res.bottomRight.x = min(a.bottomRight.x, b.bottomRight.x);
    res.bottomRight.y = min(a.bottomRight.y, b.bottomRight.y);
    if (res.topLeft.x > res.bottomRight.x || res.topLeft.y > res.bottomRight.y) {
        return {{0, 0}, {0, 0}}; // Representa um retângulo inválido
    }
    return res;
}

bool isValid(Rectangle r) {
    return r.topLeft.x <= r.bottomRight.x && r.topLeft.y <= r.bottomRight.y;
}

int main() {
    int n;
    cin >> n;
    vector<Rectangle> rectangles(n);

    for (int i = 0; i < n; i++) {
        cin >> rectangles[i].topLeft.x >> rectangles[i].topLeft.y
            >> rectangles[i].bottomRight.x >> rectangles[i].bottomRight.y;
    }

    vector<Rectangle> prefix(n + 1), suffix(n + 1);
    prefix[0] = {{INT_MIN, INT_MIN}, {INT_MAX, INT_MAX}};
    suffix[0] = {{INT_MIN, INT_MIN}, {INT_MAX, INT_MAX}};

    for (int i = 1; i <= n; i++) {
        prefix[i] = intersect(prefix[i - 1], rectangles[i - 1]);
    }

    for (int i = 1; i <= n; i++) {
        suffix[i] = intersect(suffix[i - 1], rectangles[n - i]);
    }

    for (int i = 0; i <= n; i++) {
        Rectangle inter = intersect(prefix[i], suffix[n - i]);
        if (isValid(inter)) {
            cout << inter.topLeft.x << " " << inter.topLeft.y << endl;
            return 0;
        }
    }

    // Se não encontrar nenhuma interseção válida
    assert(false);
}
