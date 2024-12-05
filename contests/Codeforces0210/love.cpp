#include <bits/stdc++.h>
using namespace std;

int countSubstrings(const std::string& str, const std::string& sub) {
    int count = 0;
    size_t pos = str.find(sub); // Initial position
    
    while (pos != std::string::npos) {
        count++;
        // Move to the next position after the found substring
        pos = str.find(sub, pos + 1); // Use `pos + sub.length()` if you don't want overlaps
    }
    return count;
}


int main() {
    int t; 
    cin >> t;
    while (t--) {
        int n, m; 
        cin >> n >> m; 
        int count = 0;
        
        // Read the matrix
        vector<vector<char>> carp(n + 1, vector<char>(m + 1));
        for (int i = 1; i <= n; i++) {
            string s; cin >> s;
            for (int j = 1; j <= m; j++) {
                carp[i][j] = s[j-1];
            }
        }
        
        int f = 1, s = 1;
        while (n-f > 0 && m-s > 0) {
            int l = 2 * ((n-f+1) + (m-s+1) - 2) + 3; 
            int i = f, j = s;

            string st = "";
            for (int c = 0; c < l; c++) {
                int ant1 = i, ant2 = j;
                
                if (i == f && j == s) {
                    j++;
                } else if (i == f && j == m) {
                    i++;
                } else if (i == n && j == m) {
                    j--;
                } else if (i == n && j == s) {
                    i--;
                } else if (j == s) {
                    i--;
                } else if (i == f) {
                    j++;
                } else if (j == m) {
                    i++;
                } else if (i == n) {
                    j--;
                }
            
                st += carp[i][j];
            }
            count += countSubstrings(st, "1543");
            

            f++; s++; n-=1; m-=1;
        }
        cout << count << endl;
    }
    
    return 0;
}
