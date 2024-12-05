#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 100;

struct Node {
    int total_sum;  // Soma total do intervalo
    int max_prefix; // Soma máxima do prefixo
    int max_suffix; // Soma máxima do sufixo
    int max_subarray; // Soma máxima do subarray
};

Node val[4 * MAX]; // Árvore segmentada
int arr[MAX];      // Array de entrada
int n;             // Tamanho do array

// Merge para combinar os resultados de dois nós
Node merge(Node left, Node right) {
    Node result;
    result.total_sum = left.total_sum + right.total_sum;
    result.max_prefix = max(left.max_prefix, left.total_sum + right.max_prefix);
    result.max_suffix = max(right.max_suffix, right.total_sum + left.max_suffix);
    result.max_subarray = max({left.max_subarray, right.max_subarray, left.max_suffix + right.max_prefix});
    return result;
}

// Construção da árvore segmentada
void build_rec(int id, int tl, int tr) {
    if (tl == tr) { // Caso base: folha
        val[id] = {arr[tl], arr[tl], arr[tl], arr[tl]};
    } else {
        int mid = (tl + tr) / 2;
        build_rec(2 * id, tl, mid);
        build_rec(2 * id + 1, mid + 1, tr);
        val[id] = merge(val[2 * id], val[2 * id + 1]);
    }
}

void build() {
    build_rec(1, 0, n - 1);
}

// Atualização de um elemento
void update_rec(int id, int tl, int tr, int pos, int x) {
    if (tl == tr) { // Caso base: folha
        val[id] = {x, x, x, x};
    } else {
        int mid = (tl + tr) / 2;
        if (pos <= mid) {
            update_rec(2 * id, tl, mid, pos, x);
        } else {
            update_rec(2 * id + 1, mid + 1, tr, pos, x);
        }
        val[id] = merge(val[2 * id], val[2 * id + 1]);
    }
}

void update(int pos, int x) {
    update_rec(1, 0, n - 1, pos, x);
}

// Consulta do intervalo [l, r]
Node query_rec(int id, int tl, int tr, int l, int r) {
    if (tr < l || r < tl) return {0, INT_MIN, INT_MIN, INT_MIN}; // Fora do intervalo
    if (l <= tl && tr <= r) return val[id]; // Totalmente dentro
    int mid = (tl + tr) / 2;
    Node q1 = query_rec(2 * id, tl, mid, l, r);
    Node q2 = query_rec(2 * id + 1, mid + 1, tr, l, r);
    return merge(q1, q2);
}

Node query(int l, int r) {
    return query_rec(1, 0, n - 1, l, r);
}

int main() {
    cin >> n;
    int m;
    cin >> m; // Número de queries
    for (int i = 0; i < n; i++) cin >> arr[i]; // Preenche o array
    build(); // Constrói a Segment Tree

    cout << query(0, n - 1).max_subarray << endl; // Soma máxima inicial

    while (m--) {
        int p, x;
        cin >> p >> x; // Atualização
        update(p, x);
        cout << query(0, n - 1).max_subarray << endl; // Soma máxima após atualização
    }
    return 0;
}
