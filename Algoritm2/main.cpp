#include <iostream>
#include <time.h>

using namespace std;

const int N = 1000;

int arr[N];

int main () {
    srand (time(0));
    for(int i = 0; i < N; i++) {
        arr[i] = rand()%100;
        cout << arr[i] << "\t";
    }

    time_t begin, finish;
    begin = time(NULL);
    for(int i = 0; i < N; i++)
        for(int j = i + 1; j < N; j++)
            if(arr[j] < arr[i])
                swap(arr[j], arr[i]);
    finish = time(NULL);


    cout << endl;
    for(int i = 0; i < N; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;

    if (N%2 == 1) {
        cout << arr[N/2];
    } else {
        cout << arr[(N-1)/2];
    }

    cout << "\nruntime = " << finish-begin << endl;
}
