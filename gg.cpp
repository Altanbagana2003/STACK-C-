#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <list>
using namespace std;


template<class T>

struct Vector {
    int len;
    int cap;
    T *data;

    Vector () {
        int len = 0;
        cap = 0;
        data = NULL;
    }

    void push_back(T e) {
        if (cap == 0) {
            data = new T[1];
            cap = 1;
            len = 1;
            data[0] = e;
        } else {
            if (len < cap) {
                data[len] = e;
                len++;
            } else {
                int *temp = data;
                data = new T[cap * 2];
                for (int i = 0; i < len; i++) {
                    data[i] = temp[i];
                }
                data[len] = e;
                len++;
                cap = cap * 2;
                delete [] temp;
            }
        }
    }
    void pop_back(){
        len--;
    }
    int size() {
        return len;
    }
    T *begin() {
        return &data[0];
    }
    T *end() {
        return &data[len];
    }
    void resize(int n) {
        cap = n;
        len = n;
        if (data != NULL) {
            delete [] data;
        }
        data = new int[cap];
    }
    void erase(int *x) {
        erase(x, x + 1);
    }

    void erase(T *it1, T *it2) {
        while (it2 != data + len) {
            *it1 = *it2;
            it1++; it2++;
        }
        len = len - (it2 - it1);
    }
    void insert(T *it, int elem) {
        if(len == cap) {
            if (cap == 0) cap++;
            else cap *= 2;
            int *tmp = data;
            data = new T[cap];
            for (int i = 0; i < len; i++) {
                data[i] = tmp[i];
            }
            delete [] tmp;
        }

        for(T *i = &data[len]; i > it; i--) {
            *i = *(i - 1);
        }
        if (it == &data[len]) {
            data[*it + len] = elem;
        } else {
            data[*it - 1] = elem;
        }
        len++;
    }
    T& operator[](int i) {
        return data[i];
    }
};

int main () {
    Vector<int> vec;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        vec.push_back(t);
    }
    int k;
    k = vec.size();
    cout << "Size: " << k << endl;
    for(int i = 0; i < n; i++) {
        cout << vec[i] << endl;
    }
    cout << "---------------" << endl;
    vec.pop_back();
    k = vec.size();
    cout << "Size: " << k << endl;
    for(int i = 0; i < vec.size(); i++) {
        cout << vec[i] << endl;
    }
    cout << "-------------" << endl;
    vec.push_back(100);
    k = vec.size();
    cout << "Size: " << k << endl;
    for(int i = 0; i < vec.size(); i++) {
        cout << vec[i] << endl;
    }
    cout << "--------------------" << endl;
    sort (vec.begin(), vec.end());
    for(int i = 0; i < vec.size(); i++) {
        cout << vec[i] << endl;
    }
    cout << "-------------------" << endl;
    Vector <int> q;
    q.resize(vec.size());
    k = q.size();
    cout << "Size of q: " << k << endl;
    cout << "----------------" << endl;
    vec.erase(vec.begin()+2, vec.begin()+4);
    for(int i = 0; i < vec.size(); i++) {
        cout << vec[i] << endl;
    }
    cout << "---------------------" << endl;
    int val;
    cin >> val;
    vec.insert(vec.begin(), val);
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    } cout << endl;
    return 0;
}