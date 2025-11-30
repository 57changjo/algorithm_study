#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <climits>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int H, W;
vector<int> height(501);
int water;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // inputData
    //(void)freopen("b14719.txt", "r", stdin);
    cin >> H >> W;
    for (int i = 1; i <= W; ++i) {
        cin >> height[i];
    }
    
    for (int h = H; h > 0; h--) {
        vector<int> list;
        for (int i = 1; i <= W; ++i) {
            if (height[i] >= h) list.push_back(i);
        }
        
        int cnt = list.size();
        if (cnt < 2) continue;
        else {
            water += list[cnt - 1] - list[0] - (cnt - 1);
        }

        //cout << "cnt: " << cnt << ", h : " << h << ", water : " << water << endl;
    }

    cout << water;

    return 0;
}
