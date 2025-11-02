#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    int A = 300;
    int B = 60;
    int C = 10;

 
    if (T % 10 != 0) {
        cout << -1;
        return 0;
    }

    int a = T / A;   
    T %= A;

    int b = T / B;   
    T %= B;

    int c = T / C;   
    T %= C;

    cout << a << " " << b << " " << c;
    return 0;
}
