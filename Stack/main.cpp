#include <iostream>
#include <time.h>

using namespace std;

// метод для сортировки
void qsort (int[], int b, int e);

// СТЕК НА ОСНОВЕ МАССИВА
class Stack {

private:
    unsigned int head;
    int* array;

public:
    Stack(int N)
    {
        head = 0;
        array = new int [N];
    };

    ~Stack()
    {
        delete[] array;
    };

    void push(int elem)
    {
        array[head] = elem;
        head++;
    };

    int top()
    { return array[head-1]; };

    void pop()
    {
        if(head != 0)
        {
            head--;
            array[head] = 0;        // обнулить значение
        }
    };

    int size()
    { return head; };

};

int main () {
    int N = 1000000;
    Stack arr(N);
    cout << "Последовательность:" << endl;
    for(int i = 0; i < N; i++) {
        arr.push(rand()%100);
        cout << arr.top() << "\t";
    }

    // сортируем через посредника-массив
    int num[N];
    for(int i = 0; i < N; i++) {
        num[i] = arr.top();
        arr.pop();
    }
    time_t b, f;
    b = time(NULL);
    qsort(num, 0, N-1);
    f = time(NULL);
        // проверка
    cout << endl << "Отсортировано:" << endl;
    for(int i = 0; i < N; i++) {
        cout << num[i] << "\t";
    }

    // заполняем стек в обратном порядке
    cout << endl << "В стеке(с начала):" << endl;
    for(int i = N-1; i >= 0; i--) {
        arr.push(num[i]);
        cout << arr.top() << "\t";
    }

    // получаем коэффициенты
    double X = (num[N-1]+num[N-2]+num[N-3]) / 3, A;
    cout << "\n\nЗадайте коэффициент: ";
    cin >> A;
    // Выполнить задание.
    cout << endl << "Удалённые элементы:" << endl;
    for(int i = 0; i < N; i++) {
        if(arr.top() < A*X ) {
            // вывести значение
            cout << arr.top() << "\t";
            // удалить значение
            arr.pop();
        }
    }
    cout << endl << "time = " << f-b << endl;

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
