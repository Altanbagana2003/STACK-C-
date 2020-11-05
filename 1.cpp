#include <iostream>
using namespace std;

int hieh(int a, int b) {
    if (b == 0) {
        return a;
    }
    int y = hieh(b, a % b);
    return y;
}

int main () {
    int a, b;
    cin >> a >> b;
    int x = hieh(a, b);
    cout << x << endl;
    return 0;
}