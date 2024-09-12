#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    map<int, int> freq;  // to store frequencies of elements in the current window
    int unique_count = 0;
    long long sum = 0;
    int i = 0;

    for (int j = 0; j < n; j++) {
        // Add a[j] to the window
        if (freq[a[j]] == 0) {
            unique_count++;
        }
        freq[a[j]]++;

        // Shrink the window from the left if unique elements exceed k
        while (unique_count > k) {
            freq[a[i]]--;
            if (freq[a[i]] == 0) {
                unique_count--;
            }
            i++;
        }

        // All subarrays ending at j and starting from any index >= i are valid
        sum += (j - i + 1);
    }

    cout << sum << endl;
    return 0;
}

