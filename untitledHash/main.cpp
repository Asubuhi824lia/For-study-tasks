#include <iostream>
#include <string>
#include <fstream>
#include <map>

using namespace std;

int fHash(string str)
{
    int h = 0;
    for (unsigned int i = 0; i < str.length(); i++)
        h += int(str[i]);
    return h%256;
}

class HashTable
{
private:

    struct Node
    {
        string value;
        bool state;
        Node* next;     // указатель на следующую ячейку с таким же хэшем
        Node(const string value_, Node* ptr = nullptr) : value(value_), state(true), next(ptr) {}
    };
    Node** arr;

public:
    static const int buffer_size = 256;

public:
    HashTable()
    {
        arr = new Node*[buffer_size];
        for(int i = 0; i < buffer_size; i++)
            arr[i] = nullptr;
    }

    ~HashTable()
    {
        for (int i = 0; i < buffer_size; i++)
            if (arr[i])
                delete arr[i];
        delete[] arr;
    }

    bool Find(const string value)
    {
        int h = fHash(value);
        for(Node* node = arr[h]; node != nullptr; node = node->next)
            if(node->value == value && node->state)
                return true;

        return false;
    }

    bool Find(const int hash)
    {
        for(int h = hash; arr[h] != nullptr && h < buffer_size; h++)
            if(arr[h] != nullptr && arr[h]->state)
                return true;

        return false;
    }

    void Remove(const int hash)
    {
        if(arr[hash] == nullptr)
            return;
        else
            arr[hash] = nullptr;
//        else if(arr[hash]->next == nullptr)
//            arr[hash] = nullptr;
//        else
//        {

//            // доходим до крайнего узла
//            while(arr[hash] != nullptr)
//            {
//                Node* node = arr[hash];
//                arr[hash] = node->next;

//            }
//            return;
//        }
    }

    bool Add(string value)
    {
        int h = fHash(value);

        Node* node = arr[h],
            * first_deleted = nullptr;

        while(node != nullptr)
        {
            if (node->value == value && node->state)
                return false;   // такой элемент уже есть
            if (!node->state && first_deleted == nullptr)
            {
                // как только находим подходящий узел, обозначенный удалённым
                first_deleted = node;
                break;
            }
            // если дошли до конца цепочки
            if(node->next == nullptr)
            {
                node->next = new Node(value);
                return true;
            }
            node = node->next;
        }

        // если по такому хэшу ещё не было добавлено элемента
        if (first_deleted == nullptr)
        {
            arr[h] = new Node(value);
        }
        else
        {
            first_deleted->value = value;
            first_deleted->state = true;
        }
        return true;
    }

    int GetHash (const string value)
    {
        for(int h = fHash(value); arr[h] != nullptr && h < buffer_size; h++)
            if(arr[h]->value == value && arr[h]->state)
                return h;

        return -1;
    }

    void PrintHashElems (const int hash)
    {
        for(Node* node = arr[hash]; node != nullptr; node = node->next)
            if(node->state)
                cout << node->value << ", ";
        cout << endl;
    }

};

int main()
{
    HashTable hash_table;

    // Заполняем хэш-таблицу строками из файла
    ifstream file("ucbb1.txt");

    int numTableElems;
    file >> numTableElems;
    if (file.is_open() && !file.eof())
    {
        string word;
        for (int i = 0; i < numTableElems && !file.eof(); i++)
        {
            file >> word;
            hash_table.Add(word);

            cout << i+1 << ". Hash: " << hash_table.GetHash(word) << "\tString: " << word << endl;
        }
        cout << endl;
    };
    file.close();

    cout << "Содержимое хэш-таблицы:" << endl;
    for (int i = 0; i < hash_table.buffer_size; i++)
    {
        if(hash_table.Find(i))
        {
            cout << "Хэш = " << i << "\tзначения: ";
            hash_table.PrintHashElems(i);
        }
    }

    // Проверка на совпадение со строками из другого файла
    string filename = "ucbc20.txt";
    file.open(filename);
    int num;
    file >> num;

    bool overlap = false;
    int count = 0;
    if (file.is_open() && !file.eof())
    {
        string word;
        for (int i = 0; i < num && !file.eof(); i++)
        {
            file >> word;
            if(hash_table.GetHash(word) != -1)
            {
                cout << "Совпадение со строкой '" << word << "', хэш = " << hash_table.GetHash(word) << endl;
                overlap = true;
                count++;
            }
        }

        if(!overlap)
            cout << "Совпадений с файлом '" << filename << "' не обнаружено" << endl;
        else
            cout << "Итого: совпадений с файлом '" << filename << "': " << count << endl;
    }
    file.close();

    // Удаление элементов, у которых значение хэша нечётное
    count = 0;
    cout << endl << "Удалённые строки:" << endl;
    for (int i = 0; i < hash_table.buffer_size; i++)
    {
        if(hash_table.Find(i) && i%2 != 0)
        {
            cout << "Хэш = " << i << "\tзначения: ";
            hash_table.PrintHashElems(i);
            hash_table.Remove(i);
            count++;
        }
    }
    cout << endl << "Итого: обнаружено и удалено " << count << " элементов, имеющих нечётное значение хэша." << endl;

    return 0;
}
