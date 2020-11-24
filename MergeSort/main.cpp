#include <iostream>
#include <time.h>

using namespace std;

const int n = 1000;
int a[n];

void sortMerge(int l, int r) {
    if (r == l) return;

    if (r == l + 1) {
        if (a[r] < a[l])
            swap(a[r], a[l]);
            return;
    }

    // разделяем массив на части
    int m = (r + l) / 2;
    sortMerge(l, m);
    sortMerge(m + 1, r);

    int buf[n];
    int xl = l;
    int xr = m + 1;
    int cur = 0;

    while (r - l + 1 != cur) {
        if (xl > m)
            buf[cur++] = a[xr++];
        else if (xr > r)
            buf[cur++] = a[xl++];
        else if (a[xl] > a[xr])
            buf[cur++] = a[xr++];
        else buf[cur++] = a[xl++];
    }

    for (int i = 0; i < cur; i++)
        a[i + l] = buf[i];
}


int main() {

    for(int i = 0; i < n; i++) {
        a[i] = rand()%100;
  //      cout << a[i] << "\t";
    }

    time_t beg = time(NULL), fin;
    sortMerge(0, n - 1);
    fin = time(NULL);
/*
    cout << endl;
    for (int i = 0; i < n; i++)
        cout << a[i] << "\t";
*/    cout << endl << "time = " << fin-beg << endl;

    return 0;
}
