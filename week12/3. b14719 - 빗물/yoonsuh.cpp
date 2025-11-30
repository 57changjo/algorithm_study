#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W;
    cin >> H >> W;
    vector<int> height(W);
    for (int i = 0; i < W; i++) {
        cin >> height[i];
    }

    int total = 0;
    for (int i = 1; i < W - 1; i++) {
        int left_max = 0;
        for (int j = 0; j < i; j++) {
            left_max = max(left_max, height[j]);
        }

        int right_max = 0;
        for (int j = i + 1; j < W; j++) {
            right_max = max(right_max, height[j]);
        }

        int water_height = min(left_max, right_max) - height[i];
        if (water_height > 0) {
            total += water_height;
        }
    }

    cout << total << "\n";
    return 0;
}
