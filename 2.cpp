#include <iostream>
using namespace std;

int factorial(int n) {
    if (n==0) {
        return 1;
    }
    int y = factorial(n-1);
    return y*n;
}

int main () {
    int n;
    cin >> n;
    int x = factorial(n);
    cout << x << endl;
    return 0;
}