#include <iostream>

using namespace std;

struct Node
{
    int info;

    Node* rlink;
    Node* llink;
    Node* parent;

    // номер повторяющегося элемента
    int overlap;
};

class BinaryTree
{
    Node* root;

public:
    BinaryTree()
    {
        root = nullptr;
    }

    Node* CreateNode(const int value, Node* parent = nullptr, const int count = 0)
    {
        Node* tmp = new Node;
        tmp->info = value;
        tmp->llink = nullptr;
        tmp->rlink = nullptr;
        tmp->parent = parent;
        tmp->overlap = count;
        return tmp;
    }

    void AddNode(const int value)
    {
        if(root == nullptr)
        {
            root = CreateNode(value);
            return;
        }

        // free node search
        Node *tmp;
        tmp = root;
        int count = 0;      // счётчик повторений
        while(tmp)
        {
            if(value > tmp->info)
            {
                if(tmp->rlink)
                {
                    // если правый узел не пустой - переходим к нему и начинаем цикл сначала
                    tmp = tmp->rlink;
                    continue;
                } else {
                    // если правой ветки нет - вставляем узел справа
                    tmp->rlink = CreateNode(value, tmp, count);
                    return;
                }
            }
            else
            {
                // проверка на повторение значения с текущим узлом
                if(tmp->info == value)
                    count++;

                if(tmp->llink)
                {
                    // если левый узел не пустой - переходим к нему и начинаем цикл сначала
                    tmp = tmp->llink;
                    continue;
                } else {
                    // если левой ветки нет - вставляем узел слева
                    tmp->llink = CreateNode(value, tmp, count);
                    return;
                }
            }
        }
    }


    void PrintTree (bool r = true)
    {
        PrintLevel(root, "root", 0, r);
    }

    void PrintLevel(Node* root, string dir, const int level, bool r)
    {
        if(root)
        {
            cout << "Level " << level << ", " << dir <<  ": " << root->info;

            //если нужно вывести кол-во повторений
            if (r)
                cout << "\nповторений: " << root->overlap << endl;

            cout << endl;
            PrintLevel(root->llink, dir + " -> left", level+1, r);
            PrintLevel(root->rlink, dir + " -> right", level+1, r);
        }
    }

    Node* Remove(Node* node)
    {
        Node* tmp;
        // если узел не имеет потомков
        if(!node->llink && !node->rlink)
        {
            tmp = node->parent;
            if(node == node->parent->llink)
                node->parent->llink = nullptr;
            else
                node->parent->rlink = nullptr;
        }

        // если у узла только правый - наследник
        else if(!node->llink && node->rlink)
        {
            tmp = node->parent;
            // подменяем наследником удаляемый узел
            if(node == node->parent->llink)
                node->parent->llink = node->rlink;
            else
                node->parent->rlink = node->rlink;
        }
        // если у узла наследник только слева
        else if(node->llink && !node->rlink)
        {
            tmp = node->parent;
            // повторяется ли значение узла-замены?
            if(node->llink->info == node->info)
                Remove(node->llink);
            // подменяем узел им
            if(node == node->parent->llink)
                node->parent->llink = node->llink;
            else
                node->parent->rlink = node->llink;
        }
        // в ином случае, когда у узла 2 потомка
        else
        {
            tmp = node->parent;
            // сначала находим узел с наибольшим значением в левой ветви
            Node* localMax = GetMaxNode(node->llink);
            // подменяем значение
            node->info = localMax->info;
            // удаляем узел
            Remove(localMax);
        }
        // возарат указателя на предыдущий узел
        return tmp;
    }

    Node* GetMaxNode(Node* node)
    {
        while(node->rlink)
            node = node->rlink;
        return node;
    }

    void RemoveRepeats(Node* node)
    {
        // проход по всем узлам
        if(node)
        {
            if(node->overlap > 0)
                node = Remove(node);

            RemoveRepeats(node->llink);
            RemoveRepeats(node->rlink);
        }
    }

    Node* GetRoot()
    {
        return root;
    }
};

int main()
{
    const int n = 15;
    int num_seq[n];
    for(int i = 0; i < n; i++)
        num_seq[i] = rand()%5;

    BinaryTree BT;

    cout << "Числовая последовательность:" << endl;
    for(int i = 0; i < n; i++)
    {
        cout << i << ". " << num_seq[i] << endl;
        BT.AddNode(num_seq[i]);
    }
    BT.PrintTree();

    // уделить пвторяющиеся элементы
    cout << endl;
    BT.RemoveRepeats(BT.GetRoot());
    BT.PrintTree(false);

    return 0;
}
