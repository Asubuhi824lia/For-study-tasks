#include <iostream>
#include <time.h>
#include <vector>

using namespace std;

const int N = 1000;

void qsort (int b, int e);
int arr[N];

bool Overlap(vector <int> inds, int j) {
    for(size_t i = 0; i < inds.size(); i++)
        if(inds[i] == j)
            return false;
    return true;
}

int main () {
    srand(time(0));
    for(int i = 0; i < N; i++) {
        arr[i] = rand()%100;
        //cout << arr[i] <<"\t";
    }
    cout << endl << endl;

    /*
    int cur, prev = arr[0], max = arr[0], ind_max;  // рабочие переменные
    vector <int> inds;              // для хранения индексов пройденных элементов
    inds.push_back(0);
    for(int i = 0; i < N; i++) {
        if(arr[i] < prev) {         // поиск наименьшего
            prev = arr[i];
            inds[0] = i;
        }
        if(arr[i] > max) {          // и наибольшего
            max = arr[i];
            ind_max = i;
        }
    }
    for(int i = 0; i < N/2; i++) {  // "сортируем" половину массива
        cur = max;
        inds.push_back(ind_max);
        for(int j = 0; j < N; j++)
            // поиск меньшего и проверка на совпадение по значению и индексу
            if(arr[j] < cur && arr[j] >= prev && Overlap(inds, j)) {
                cur = arr[j];
                inds[i+1] = j;
            }
        prev = cur;
    }
    //cout << endl << cur << endl;
    */

    // проверка
    time_t begin, finish;
    begin = time(NULL);
    qsort(0, N-1);
    finish = time(NULL);
/*
    cout << endl;
    for(int i = 0; i < N; i++) {
        cout << arr[i] << "\t";
    }
*/
    cout << endl << endl << arr[N/2] << endl;
    cout << "time=" << finish - begin << endl;
}

void qsort (int b, int e)
{
    int l = b, r = e;
    int piv = arr[(l + r) / 2]; // Опорный элемент
    while (l <= r)
    {
        while (arr[l] < piv)
        l++;
        while (arr[r] > piv)
        r--;
        if (l <= r)
        swap (arr[l++], arr[r--]);
    }
    if (b < r)
        qsort (b, r);
    if (e > l)
        qsort (l, e);
}
