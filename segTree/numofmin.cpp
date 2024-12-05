#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6+100;
const int oo = 2e9;

pair<int, int> val[4*MAX]; // Segment Tree
int arr[MAX];   // Array de entrada
int n;          // Tamanho do array

// Operação de merge para a Segment Tree
pair<int, int> merge(pair<int, int> v1, pair<int, int> v2) {
    if (v1.first < v2.first) {
        return v1;
    } else if (v2.first < v1.first) {
        return v2;
    } else {
        return {v1.first, v1.second + v2.second};
    }
}

// Construção recursiva da Segment Tree
void build_rec(int id, int tl, int tr) {
    if (tl == tr) {
        val[id] = {arr[tl], 1}; // Cada elemento é único inicialmente
    } else {
        int mid = (tl + tr) / 2;
        build_rec(2*id, tl, mid);
        build_rec(2*id+1, mid+1, tr);
        val[id] = merge(val[2*id], val[2*id+1]);
    }
}

// Função para construir a Segment Tree
void build() {
    build_rec(1, 0, n-1);
}

// Atualização recursiva de um elemento
void update_rec(int id, int tl, int tr, int pos, int x) {
    if (tl == tr) {
        val[id] = {x, 1}; // Atualiza o valor e reseta a contagem
    } else {
        int mid = (tl + tr) / 2;
        if (pos <= mid)
            update_rec(2*id, tl, mid, pos, x);
        else
            update_rec(2*id+1, mid+1, tr, pos, x);
        val[id] = merge(val[2*id], val[2*id+1]);
    }
}

// Função para atualizar um elemento
void update(int pos, int x) {
    update_rec(1, 0, n-1, pos, x);
}

// Consulta recursiva no intervalo [l, r]
pair<int, int> query_rec(int id, int tl, int tr, int l, int r) {
    if (tr < l || r < tl) return {oo, 0}; // Fora do intervalo
    if (l <= tl && tr <= r) return val[id]; // Totalmente dentro
    int mid = (tl + tr) / 2;
    pair<int, int> q1 = query_rec(2*id, tl, mid, l, r);
    pair<int, int> q2 = query_rec(2*id+1, mid+1, tr, l, r);
    return merge(q1, q2);
}

// Função para consultar o mínimo e suas ocorrências em um intervalo
pair<int, int> query(int l, int r) {
    return query_rec(1, 0, n-1, l, r);
}

int main() {
    cin >> n;
    int m;
    cin >> m; // Número de queries
    for (int i = 0; i < n; i++) cin >> arr[i]; // Preenche o array
    build(); // Constrói a Segment Tree

    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {
            int p, x;
            cin >> p >> x; // Atualização
            update(p, x);
        } else if (op == 2) {
            int l, r;
            cin >> l >> r; // Consulta
            pair<int, int> ans = query(l, r-1);
            cout << ans.first << " " << ans.second << '\n';
        }
    }
    return 0;
}
