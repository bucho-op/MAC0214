#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6+100;
const int neutral_value = 0;

string s;
pair<int, int> tree[4 * MAX];
char arr[MAX];


pair<int, int> calc_res(const string &t) {
    int open = 0, close = 0;
    for (char ch : t) {
        if (ch == '(') {
            open++;
        } else if (ch == ')') {
            if (open > 0) {
                open--;
            } else {
                close++;
            }
        }
    }
    return {open, close};
}


pair<int, int> merge(pair<int, int> left, pair<int, int> right) {
    int matched = min(left.first, right.second);
    return {left.first + right.first - matched, left.second + right.second - matched};
}

void build_rec(int id, int tl, int tr) {
    if (tl == tr) {
        tree[id] = calc_res(string(1, arr[tl]));
    } else {
        int mid = (tl + tr) / 2;
        build_rec(2 * id, tl, mid);
        build_rec(2 * id + 1, mid + 1, tr);
        tree[id] = merge(tree[2 * id], tree[2 * id + 1]);
    }
}

void build(int n) {
    build_rec(1, 1, n);
}


void update_rec(int id, int tl, int tr, int pos, char x) {
    if (tl == tr) {
        tree[id] = calc_res(string(1, x));
    } else {
        int mid = (tl + tr) / 2;
        if (pos <= mid) {
            update_rec(2 * id, tl, mid, pos, x);
        } else {
            update_rec(2 * id + 1, mid + 1, tr, pos, x);
        }
        tree[id] = merge(tree[2 * id], tree[2 * id + 1]);
    }
}


void update(int n, int pos, char x) {
    update_rec(1, 1, n, pos, x);
}


pair<int, int> query_rec(int id, int tl, int tr, int l, int r) {
    if (tr < l || r < tl) return {0, 0}; // completely outside
    if (l <= tl && tr <= r) return tree[id]; // completely inside
    int mid = (tl + tr) / 2;
    pair<int, int> q1 = query_rec(2 * id, tl, mid, l, r);
    pair<int, int> q2 = query_rec(2 * id + 1, mid + 1, tr, l, r);
    return merge(q1, q2);
}


pair<int, int> query(int l, int r) {
    return query_rec(1, 1, s.length(), l, r);
}

int main() {
    cin >> s;
    int n = s.length();
    for (int i = 1; i <= n; i++) arr[i] = s[i - 1];
    build(n);

    int m;
    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;
        pair<int, int> result = query(l, r);
        int valid_length = (r - l + 1) - (result.first + result.second);
        cout << valid_length << '\n';
    }
    return 0;
}
