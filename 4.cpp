#include <iostream>
using namespace std;

void print(int n) {
    if (n == 0) {
        return;
    }
    print(n - 1);   
    cout << n << " ";
}


void reverse_print(int n) {
    if (n == 0) {
        return;
    }
    cout << n << " ";
    reverse_print(n - 1);   
}

int main () {
    int n;
    cin >> n;
    print(n);
    cout << endl;
    reverse_print(n);
    cout << endl;
    return 0;
}