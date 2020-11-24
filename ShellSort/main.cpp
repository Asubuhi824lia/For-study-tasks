#include <iostream>
#include <time.h>

#include <chrono>

using namespace std;

void ShellSort(int A[], int n) //сортировка Шелла
{
    time_t begin, finish;
    begin = time(NULL);
    int d=n/2;
    while (d > 0)
    {
        for (int i=0; i<n-d; i++)
        {
            int j=i;
            while (j>=0 && A[j]>A[j+d])
            {
                swap(A[j], A[j+d]);
                j--;
            }
        }
        d = d/2;
    }
    finish = time(NULL);

    for (int i=0; i<n; i++)
        cout << A[i] << "\t"; //вывод массива
    cout << endl << "time: " << finish-begin;
}


int main()
{
    const int N = 9000;
    int num[N];
    srand(time(0));
    for(int i = 0; i < N; i++) {
        num[i] = rand()%N;
        cout << num[i] << "\t";
    }

    cout << endl << endl;
    ShellSort(num, N);
    cout << endl;
    return 0;
}
