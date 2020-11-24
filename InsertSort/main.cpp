#include <iostream>
#include <time.h>

using namespace std;

void insertsort (int*, int n);

int main()
{
    const int N = 100000;
    int num[N];
    for(int i = 0; i < N; i++) {
        num[i] = rand()%100;
        cout << num[i] << "\t";
    }
    cout << endl;
    time_t begin, finish;
    begin = time(NULL);
    insertsort(num, N);
    finish = time(NULL);
    cout << endl << "time=" << finish-begin << endl;

    return 0;
}

void insertsort (int *mas, int n) {
    cout << "Sorted: " << endl;
    // проходим по элементам, начиная со 2-го
    for(int i = 1; i < n; i++) {
        int key = i;
        int temp = mas[key];
        // проверяем левую часть элементов
        for(int j = i-1; j >= 0; j--) {
            // сдвигаем бОльшие элементы, ищем подходящий индекс
            if (temp < mas[j]) {
                mas[j+1] = mas[j];
                key = j;
            }
            else break;
        }
        mas[key] = temp;
    }
    for(int i = 0; i < n; i++) {
        cout << mas[i] << "\t";
    }
}
