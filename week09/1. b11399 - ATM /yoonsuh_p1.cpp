#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;         

    int P[1001];       
    for (int i = 0; i < N; i++)
        cin >> P[i];

    sort(P, P + N);    

    int sum = 0;      
    int result = 0;    

    for (int i = 0; i < N; i++) {
        sum += P[i];   
        result += sum; 
    }

    cout << result;    
    return 0;
}
