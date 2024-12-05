#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e6+100;
const int oo = 2e9;

const int neutral_value = oo; // depende da operação do merge
int n;
int val[4*MAX]; // Árvore segmentada
int arr[MAX];   // Array de entrada

// operação pode ser de soma, min, max ou outras operações associativas
int merge(int v1, int v2){
    return min(v1, v2);
}


// construção da árvore
void build_rec(int id, int tl, int tr){
    if(tl == tr){ // Caso base: folha
        val[id] = arr[tl];
    } else {
        int mid = (tl+tr)/2; // Divide o intervalo ao meio
        build_rec(2*id, tl, mid);       // Constrói o filho esquerdo
        build_rec(2*id+1, mid+1, tr);  // Constrói o filho direito
        val[id] = merge(val[2*id], val[2*id+1]); // Combina os filhos
        // o valor de 1 é o merge da subárvore esquerda com a direita 
    }
}
void build(){
    build_rec(1, 0, n-1); // Inicializa a árvore a partir da raiz
}

void update_rec(int id, int tl, int tr, int pos, int x){
    if(tl == tr){ // Caso base: folha
        val[id] = x;
    } else {
        int mid = (tl+tr)/2;
        if(pos <= mid) // Atualizar no filho esquerdo
            update_rec(2*id, tl, mid, pos, x);
        else           // Atualizar no filho direito
            update_rec(2*id+1, mid+1, tr, pos, x);
        val[id] = merge(val[2*id], val[2*id+1]); // Atualiza o nó atual
    }
}
void update(int pos, int x){
    update_rec(1, 0, n-1, pos, x); // Chamada inicial
}


// calcula o valor em um intervalo
int query_rec(int id, int tl, int tr, int l, int r){
    if(tr < l or r < tl) return neutral_value; // Fora do intervalo
    if(l <= tl and tr <= r) return val[id];   // Totalmente dentro
    int mid = (tl+tr)/2; // Divide o intervalo
    int q1 = query_rec(2*id, tl, mid, l, r);       // Consulta esquerda
    int q2 = query_rec(2*id+1, mid+1, tr, l, r);   // Consulta direita
    return merge(q1, q2); // Combina os resultados
}
int query(int l, int r){
    return query_rec(1, 0, n-1, l, r); // Chamada inicial
}

int main(){
	cin >> n;
    int m; cin >> m; // num de queries
	for(int i=0; i<n; i++) cin >> arr[i]; // cria o array
	build(); // constrói a segTree
	
	while(m--){
		int op; cin >> op;
		if(op == 1){
			int p, x; cin >> p >> x;
			update(p, x);
		}
		if(op == 2){
			int l, r; cin >> l >> r;
			cout << query(l, r-1) << '\n';
		}

		
	}
    return 0;
}