#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e6;
const int oo = 1e9;

string ini, fin;
map<pair<int, int>, bool> mark;
map<pair<int, int>, int> dist;
map<pair<int, int>, vector<string>> mov;

void acha_mov(pair<int, int>& move, string& direction) {
    if (move == make_pair(1, 0)) {
        direction = "R";
    } else if (move == std::make_pair(-1, 0)) {
        direction = "L";
    } else if (move == std::make_pair(0, -1)) {
        direction = "D";
    } else if (move == std::make_pair(0, 1)) {
        direction = "U";
    } else if (move == std::make_pair(1, -1)) {
        direction = "RD";
    } else if (move == std::make_pair(1, 1)) {
        direction = "RU";
    } else if (move == std::make_pair(-1, -1)) {
        direction = "LD";
    } else if (move == std::make_pair(-1, 1)) {
        direction = "LU";
    }
}

void bfs(pair<int,int> ini1){ 
    pair<int, int> dir[8] = {
        {1, 0},  
        {-1, 0},    
        {0, 1},     
        {0, -1},    
        {1, 1},    
        {1, -1},   
        {-1, 1},   
        {-1, -1}    
    };
    
    queue<pair<int,int>> q;
    mark[ini1] = true;
    dist[ini1] = 0;
    q.push(ini1);

    while (!q.empty()) {
        pair<int, int> cur = q.front(); 
        q.pop(); 

        for (auto elem : dir) {
            int nx = cur.first + elem.first;
            int ny = cur.second + elem.second;

            if (nx > 0 && ny > 0 && nx < 9 && ny < 9) {
                pair<int, int> newpos = {nx, ny};
                if (!mark[newpos]) {
                    string direction;
                    acha_mov(elem, direction);
                    mov[newpos] = mov[cur];
                    mov[newpos].push_back(direction);
                    dist[newpos] = dist[cur] + 1;
                    mark[newpos] = true;
                    q.push(newpos);
                }
            }
        }
    }
}

int main(){
    cin >> ini >> fin;
    int pos1 = 0, pos2 = 0;
    for (int i = 1; i<9; i++) {
        if (ini[0] == 96+i){
            pos1 += i*10;
        }

        if (fin[0] == 96+i){
            pos2 += i*10;
        }
    }

    int x = stoi(string(1, ini[1]));
    pair<int,int> ini1 = {pos1/10, x};
    x = stoi(string(1, fin[1]));;
    pair<int,int> fin1 = {pos2/10, x};

    int limiteSuperior = 9;
    for (int i = 1; i < limiteSuperior; ++i) {
        for (int j = 1; j < limiteSuperior; ++j) {
            mark[make_pair(i, j)] = false;
        }
    }

    bfs(ini1);

    cout << dist[fin1] << endl;
	for (int i; i<mov[fin1].size(); i++){
		cout << mov[fin1][i] << endl;
	}
    return 0;
}
