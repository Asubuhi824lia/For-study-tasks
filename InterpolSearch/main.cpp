#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    // Открыть файл
    ifstream in;
    string fname;
    cout << "Enter filename: ";
    cin >> fname;
    in.open(fname);
    if (!in) return 1;

    // Считать строки из файла
    int n, len_str = 10;
    in >> n;
    char words[len_str][n], ch = '\n';
    for(int i = 0; i < n; i++) {
        in.getline(words[i], len_str-1, ch);
        cout << "String " << i+1 << " = " << words[i] << endl;
    }

    char elem[len_str];
    cout << "Задайте элемент: ";
    cin >> elem;



    return 0;
}
