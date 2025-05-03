#include <iostream>
using namespace std;
//изменил файл
struct Stack{
    int info;
    Stack* next;
};
//gugyggjygjh
Stack* InStack(Stack* p, int in);
void View(Stack* p);
void Del_All(Stack** p);
Stack* FindMin(Stack* p);
void Sort_p(Stack** p);
void Sort_info(Stack* p);

int main() {
    setlocale(LC_ALL, "RU");
    srand(time(NULL));
    int kod;
    Stack* begin = nullptr;
    Stack* newStack = nullptr;

    while (true) {
        cout << "1) Create stack.\n2) Add.\n3) View.\n4) Del.\n5) Task.\n6) Sort_ptr.\n7) Sort_info.\n0) EXIT.\n";
        cin >> kod;
        switch (kod)
        {
        case 1:
        case 2:
        {
            if (kod == 1 && begin != nullptr) {
                Del_All(&begin);
                cout << "очищено\n";
            }
            int kolvo;
            cout << "Введите количество элементов стека которые хотите добавить случайно\n";
            cin >> kolvo;
            for (int i = 0; i < kolvo; i++) {
                int chislo = rand() % 41 - 20;
                begin = InStack(begin, chislo);

            }
            break;
        }

        case 3: {
            View(begin);
            break;
        }
        case 4: {
            Del_All(&begin);
            cout << "очищено\n";
            break;
        }
        case 5: {
            Stack* min = FindMin(begin);
            cout << "\nMin = " << min->info;
            if (min->next != nullptr) {
                Stack* begin_new = min->next;
                min->next = nullptr;
                cout << "\nНовый массив м-ду вершиной и мин. значением: \n";
                View(begin);
                Del_All(&begin_new);
            }
            break;
        }
        case 6: {
            Sort_p(&begin);
            break;
        }
        case 7: {
            Sort_info(begin);
            break;
        }
        case 0: { return 0; }
        }
    }
}

Stack* InStack(Stack* p, int in) {
    Stack* t = new Stack;
    t->info = in;
    t->next = p;
    return t;
}

void View(Stack* p) {
    Stack* t = p;
    cout << "Стек: \n";
    while (t != nullptr) {
        cout << "   " << t->info << endl;
        t = t->next;
    }
}

void Del_All(Stack** p) {
    Stack* t;
    while (*p != nullptr) {
        t = *p;
        *p = (*p)->next;
        delete t;
    }
}
Stack* FindMin(Stack* p) {
    if (p == nullptr) {
        cout << "Стек пуст!\n";
        return nullptr;
    }

    Stack* min = p;
    Stack* t = p->next;

    while (t != nullptr) {
        if (t->info < min->info) {
            min = t;
        }
        t = t->next;
    }

    return min;
}

void Sort_p(Stack** p) {
    Stack* t = NULL, * t1, * r;
    if ((*p)->next->next == NULL) return;
    do {
        for (t1 = *p; t1->next->next != t; t1 = t1->next)
            if (t1->next->info > t1->next->next->info) {
                r = t1->next->next;
                t1->next->next = r->next;
                r->next = t1->next;
                t1->next = r;
            }
        t = t1->next;
    } while ((*p)->next->next != t);
}

void Sort_info(Stack* p) {
    Stack* t = NULL, * t1;
    int r;
    do {
        for (t1 = p; t1->next != t; t1 = t1->next)
            if (t1->info > t1->next->info) {
                    r = t1->info;
                t1->info = t1->next->info;
                t1->next->info = r;
            }
        t = t1;
    } while (p->next != t);
}
