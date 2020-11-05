#include <iostream>
#include <vector>
using namespace std;

void insertElement(int* arr, int index, int value, int &n) {
    n++;
    for (int i = n; i >= index; i--) {
        arr[i] = arr[i - 1];
    }
    arr[index] = value;
}

void findElement(int* arr, int index) {
    cout << arr[index] << endl;
}

void deleteElement(int* arr, int index, int &n) {
    n--;
    for (int i = index; i <= n; i++) {
        arr[i] = arr[i + 1];
    }
}

int main () {
    int n;
    cout <<"Array length: ";
    cin >> n;
    int arr[100];
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    cout<<"------Insert Element------" << endl;
    insertElement(&arr[0], 1, 100, n);
    for (int i = 1; i<=n; i++) {
        cout << arr[i] << " ";
    } cout << endl;
    cout << "-------Find Element-------" << endl;
    int find;
    cin >> find;
    findElement(&arr[0], find);
    cout << "-------Delete Element------" << endl;
    int remove;
    cin >> remove;
    deleteElement(&arr[0], remove, n);
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    } cout << endl;
    return 0;
}