#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, C;
vector<int> house;

bool canInstall(int dist) {
    int count = 1;            
    int lastPos = house[0];     

    for (int i = 1; i < N; i++) {
        if (house[i] - lastPos >= dist) {
            count++;            
            lastPos = house[i]; 
        }
    }

    return count >= C;          
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> C;
    house.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> house[i];
    }

    sort(house.begin(), house.end());

    int left = 1;                        
    int right = house.back() - house[0]; 
    int answer = 0;

    while (left <= right) {
        int mid = (left + right) / 2;    

        if (canInstall(mid)) {         
            answer = mid;
            left = mid + 1;
        } else {        
            right = mid - 1;
        }
    }

    cout << answer << '\n';
    return 0;
}
