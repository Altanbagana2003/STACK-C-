

struct vector {
    int len = 0;
    int cap = 0;
    int *data = NULL;

    void push_back(int x) {
        if (cap == 0) {
            data = new int[1];
            cap = 1;
            data[0] = x;
        } else if (len == cap) {
            int *temp = data;
            data = new int[cap * 2];
            for (int i = 0; i < len; i++) {
                data[i] = temp[i];
            }
            data[len] = x;
            len++;
            cap *= 2;
        } else {

        }
    }
}

int x = 12;

#include <sstream>

string to_string(int x) {
    if (x == 0) return "0";
    string s = "";
    while (x > 0) {
        s = (x % 10 + '0') + s;
        x /= 10;
    }
    return s;
}