#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
using namespace std;

int main() {
    int test_cases;
    cin >> test_cases;

    while (test_cases--) {
        int num_elements, max_value;
        cin >> num_elements >> max_value;

        vector<int> array(num_elements);
        for (auto &value : array) {
            cin >> value;
        }

        vector<int> pair_sum_count(2 * max_value + 1, 0);
        for (int i = 0; i < num_elements / 2; ++i) {
            ++pair_sum_count[array[i] + array[num_elements - i - 1]];
        }

        vector<int> prefix_sum(2 * max_value + 2, 0);
        for (int i = 0; i < num_elements / 2; ++i) {
            int min_range_1 = 1 + array[i], max_range_1 = max_value + array[i];
            int min_range_2 = 1 + array[num_elements - i - 1], max_range_2 = max_value + array[num_elements - i - 1];
            assert(max(min_range_1, min_range_2) <= min(max_range_1, max_range_2));
            
            ++prefix_sum[min(min_range_1, min_range_2)];
            --prefix_sum[max(max_range_1, max_range_2) + 1];
        }

        for (int i = 1; i <= 2 * max_value + 1; ++i) {
            prefix_sum[i] += prefix_sum[i - 1];
        }

        int minimum_changes = INT_MAX;
        for (int sum_value = 2; sum_value <= 2 * max_value; ++sum_value) {
            int changes = (prefix_sum[sum_value] - pair_sum_count[sum_value]) 
                          + (num_elements / 2 - prefix_sum[sum_value]) * 2;
            minimum_changes = min(minimum_changes, changes);
        }

        cout << minimum_changes << endl;
    }

    return 0;
}
