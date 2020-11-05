#include <iostream>
using namespace std;

int fibanoci(int n) {
    cout << n << endl;
    if (n < 2) return n;
    return fibanoci(n - 1) + fibanoci(n - 2);
}

int main () {
    cout << fibanoci(6) << endl;
    return 0;
}