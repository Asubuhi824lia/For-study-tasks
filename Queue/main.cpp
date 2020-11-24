#include <iostream>
#include <queue>

using namespace std;

// метод для сортировки
void qsort (int[], int b, int e);

int main () {
    int N = 50;
    queue <int> arr;
    cout << "Последовательность:" << endl;
    for(int i = 0; i < N; i++) {
        if(i%10 == 0) {cout << endl;}
        arr.push(rand()%100);
        cout << arr.back() << "\t";
    }
    cout << endl << endl;


    for(int i = 0; i < N; i++) {
        int temp = arr.front();
        arr.pop();
        int step = 0;

        while(step < N-1) {
            if(temp < arr.front()) {
                arr.push(temp);
                temp = arr.front();
                step = 0;
            }
            else {
                arr.push(arr.front());
                step++;
            }
            arr.pop();
        }

        arr.push(temp);                    // ставим наибольший элемент в конец
    }


    /*
    // сортируем через посредника-массив
    int num[N];
    for(int i = 0; i < N; i++) {
        num[i] = arr.front();
        arr.pop();
    }
    qsort(num, 0, N-1);
        // проверка
    cout << endl << "Отсортировано:" << endl;
    for(int i = 0; i < N; i++) {
        cout << num[i] << "\t";
    }

    // заполняем очередь в прямом порядке
    cout << endl << "В очереди(с начала):" << endl;
    for(int i = 0; i < N; i++) {
        arr.push(num[i]);
        cout << arr.back() << "\t";
    }
    */

    // получаем коэффициенты
    double X = 0, A;
    for(int i = 0; i < N; i++) {         // берём первый элемент с начала, вставляем в конец
        int temp = arr.front();

        if(i%10 == 0) {cout << endl;}
        cout << arr.front() << "\t";

        arr.pop();
        if (i >= N - 3) {                // ссумируем последние 3 как наибольшие
            X += temp;
        }
        arr.push(temp);
    }
    X /= 3;
    cout << "\n\nЗадайте коэффициент: ";
    cin >> A;
    // Выполнить задание.
    cout << endl << "Удалённые элементы:" << endl;
    for(int i = 0; i < N; i++) {
        if(arr.front() < A*X ) {
            if(i%10 == 0) {cout << endl;}
            // вывести значение
            cout << arr.front() << "\t";
            // удалить значение
            arr.pop();
        }
        else { break; }
    }
    cout << endl;
}

void qsort (int arr[], int b, int e)
{
    int l = b, r = e;
    int piv = arr[(l + r) / 2]; // Опорный элемент
    while (l <= r)
    {
        while (arr[l] < piv) // Поиск числа больше либо равного piv с начала (слева)
            l++;
        while (arr[r] > piv) // Поиск числа меньше либо равного piv с конца (справа)
            r--;
        if (l <= r)
            swap (arr[l++], arr[r--]);
    }
    if (b < r) // если текущая левая граница меньше r
        qsort (arr, b, r);
    if (e > l) // если текущая правая граница больше l
        qsort (arr, l, e);
}
