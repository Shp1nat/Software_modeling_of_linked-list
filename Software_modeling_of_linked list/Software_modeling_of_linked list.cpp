#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct Data
{
    char surname[20];
    char name[15];
    char lastname[25];
    int count;
    int day;
    int month;
    int year;
    int duration;
};

struct Node
{
    Data val;
    Node* next;
    Node(Data _val) : val(_val), next(nullptr) {}
};

struct list
{
    class ErrorFinding {};
    Node* first;
    Node* last;
    list() : first(nullptr), last(nullptr) {} // конструктор
    ~list()  //деструктор
    {
        Node* current = first;
        while (current)
        {
            Node* buf = current;
            current = current->next;
            delete buf;
        }
    }
    bool isEmpty() //проверка на пустоту
    {
        return first == nullptr;
    }

    void push_back(Data _val)  //добавление в конец
    {
        Node* p = new Node(_val);
        if (isEmpty()) {
            first = p;
            last = p;
            return;
        }
        last->next = p;
        last = p;
    }

    void push_front(Data _val) //добавление в начало
    {
        Node* p = new Node(_val);
        if (isEmpty()) {
            first = p;
            last = p;
            return;
        }
        p->next = first;
        first = p;
    }

    void delete_first() //удалить первый элемент
    {
        if (isEmpty()) return;
        Node* p = first;
        first = p->next;
        delete p;
    }

    void delete_last() //удалить последний элемент
    {
        if (isEmpty()) return;
        if (first == last)
        {
            delete_first();
            return;
        }
        Node* p = first;
        while (p->next != last)
            p = p->next;
        p->next = nullptr;
        delete last;
        last = p;
    }

    void push_insert(Data _val, int _index) //добавление вставкой
    {
        Node* current = first;
        while (_index > 1)
        {
            current = current->next;
            _index--;
        }
        Node* buf = current->next;
        current->next = new Node(_val);
        current = current->next;
        current->next = buf;
    }

    void deleteByIndex(int _index)
    {
        Node* current = first;
        if (_index == 1)
            delete_first();
        {
            while (_index > 2)
            {
                current = current->next;
                _index--;
            }
            Node* buf = current->next;
            current->next = buf->next;
            delete buf;
        }
    }

    Node* findSurname(string _surname) //поиск фамилии
    {
        if (isEmpty())
            NULL;
        Node* p = first;
        while (p)
        {
            if (string(p->val.surname).find(_surname) != string::npos)
                return p;
            else
                p = p->next;
        }
        throw ErrorFinding();
    }

    Node* findName(string _name) //поиск имени
    {
        if (isEmpty())
            NULL;
        Node* p = first;
        while (p)
        {
            if (string(p->val.name).find(_name) != string::npos)
                return p;
            else
                p = p->next;
        }
        throw ErrorFinding();
    }

    Node* findLastName(string _lastname) //поиск отчества
    {
        if (isEmpty())
            NULL;
        Node* p = first;
        while (p)
        {
            if (string(p->val.lastname).find(_lastname) != string::npos)
                return p;
            else
                p = p->next;
        }
        throw ErrorFinding();
    }

    Node* findCount(int _count) //поиск количества
    {
        if (isEmpty())
            NULL;
        Node* p = first;
        while (p)
        {
            if (p->val.count == _count)
                return p;
            else
                p = p->next;
        }
        throw ErrorFinding();
    }

    Node* findDay(int _day) //поиск дня
    {
        if (isEmpty())
            NULL;
        Node* p = first;
        while (p)
        {
            if (p->val.day == _day)
                return p;
            else
                p = p->next;
        }
        throw ErrorFinding();
    }

    Node* findMonth(int _month) //поиск месяца
    {
        if (isEmpty())
            NULL;
        Node* p = first;
        while (p)
        {
            if (p->val.month == _month)
                return p;
            else
                p = p->next;
        }
        throw ErrorFinding();
    }

    Node* findYear(int _year) //поиск года
    {
        if (isEmpty())
            NULL;
        Node* p = first;
        while (p)
        {
            if (p->val.year == _year)
                return p;
            else
                p = p->next;
        }
        throw ErrorFinding();
    }

    Node* findDuration(int _duration) //поиск длительности
    {
        if (isEmpty())
            NULL;
        Node* p = first;
        while (p)
        {
            if (p->val.duration == _duration)
                return p;
            else
                p = p->next;
        }
        throw ErrorFinding();
    }
};

void printLIST(list a) //вывод списка на экран
{
    while (a.first)
    {
        cout << a.first->val.surname << "  " << a.first->val.name << "  " << a.first->val.lastname << "  " << a.first->val.count << "  " << a.first->val.day << "." << a.first->val.month << "." << a.first->val.year << "  " << a.first->val.duration << endl;
        a.first = a.first->next;
    }
}

void printDATA(Node* node) //вывод информации узла на экран
{
    cout << node->val.surname << " " << node->val.name << " " << node->val.lastname << " " << node->val.count << " " << node->val.day << "." << node->val.month << "." << node->val.year << " " << node->val.duration << endl;
}

void printError() //вывод ошибки на экран
{
    cout << "Совпадений не найдено" << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int addCount;
    list l;

    cout << "Сколько элементов добавим? (элементы добавляются в конец списка) : "; //в конец
    cin >> addCount;
    for (int i = 0; i < addCount; i++)
    {
        Data data;
        char ch = '.';
        cout << "ФИО: ";
        cin >> data.surname >> data.name >> data.lastname;
        cout << "Количество переговоров: ";
        cin >> data.count;
        cout << "Дата переговоров через точки: ";
        cin >> data.day >> ch >> data.month >> ch >> data.year;
        cout << "Длительность переговоров: ";
        cin >> data.duration;
        l.push_back(data);
    }
    cout << "Наш текущий список: " << endl;
    printLIST(l);

    cout << "\nСколько элементов добавим? (элементы добавляются в начало списка) : "; //в начало
    cin >> addCount;
    for (int i = 0; i < addCount; i++)
    {
        Data data;
        char ch = '.';
        cout << "ФИО: ";
        cin >> data.surname >> data.name >> data.lastname;
        cout << "Количество переговоров: ";
        cin >> data.count;
        cout << "Дата переговоров через точки: ";
        cin >> data.day >> ch >> data.month >> ch >> data.year;
        cout << "Длительность переговоров: ";
        cin >> data.duration;
        l.push_front(data);
    }
    cout << "\nНаш текущий список: " << endl;
    printLIST(l);

    cout << "\nУдаление первого элемента. Текущий список: " << endl;
    l.delete_first();
    printLIST(l);

    cout << "\nУдаление последнего элемента. Текущий список: " << endl;
    l.delete_last();
    printLIST(l);

    int choice;
    cout << "\nВведите поле структуры, по которому нужно выполнить поиск элемента (1-surname, 2-name, 3-lastname, 4-count, 5-day, 6-month, 7-year, 8-duration) : ";
    cin >> choice;
    string text;
    int IntNumber;
    switch (choice)
    {
    case 1:
        cout << "Введите фамилию: "; cin >> text;
        try
        {
            printDATA(l.findSurname(text));
        }
        catch (list::ErrorFinding)
        {
            printError();
        }
        break;
    case 2:
        cout << "Введите имя: "; cin >> text;
        try
        {
            printDATA(l.findName(text));
        }
        catch (list::ErrorFinding)
        {
            printError();
        }
        break;
    case 3:
        cout << "Введите отчество: "; cin >> text;
        try
        {
            printDATA(l.findLastName(text));
        }
        catch (list::ErrorFinding)
        {
            printError();
        }
        break;
    case 4:
        cout << "Введите количество: "; cin >> IntNumber;
        try
        {
            printDATA(l.findCount(IntNumber));
        }
        catch (list::ErrorFinding)
        {
            printError();
        }
        break;
    case 5:
        cout << "Введите день: "; cin >> IntNumber;
        try
        {
            printDATA(l.findDay(IntNumber));
        }
        catch (list::ErrorFinding)
        {
            printError();
        }
        break;
    case 6:
        cout << "Введите месяц: "; cin >> IntNumber;
        try
        {
            printDATA(l.findMonth(IntNumber));
        }
        catch (list::ErrorFinding)
        {
            printError();
        }
        break;
    case 7:
        cout << "Введите год: "; cin >> IntNumber;
        try
        {
            printDATA(l.findYear(IntNumber));
        }
        catch (list::ErrorFinding)
        {
            printError();
        }
        break;
    case 8:
        cout << "Введите длительность: "; cin >> IntNumber;
        try
        {
            printDATA(l.findDuration(IntNumber));
        }
        catch (list::ErrorFinding)
        {
            printError();
        }
        break;
    }

    int index;
    Data data;
    cout << "Введите номер элемента, после которого добавить новый: ";
    cin >> index;
    char ch = '.';
    cout << "ФИО: ";
    cin >> data.surname >> data.name >> data.lastname;
    cout << "Количество переговоров: ";
    cin >> data.count;
    cout << "Дата переговоров через точки: ";
    cin >> data.day >> ch >> data.month >> ch >> data.year;
    cout << "Длительность переговоров: ";
    cin >> data.duration;
    l.push_insert(data, index);
    cout << "\nТекущий список: " << endl;
    printLIST(l);
    cout << "Введите номер элемента, который удалить: ";
    cin >> index;
    l.deleteByIndex(index);
    cout << "\nТекущий список: " << endl;
    printLIST(l);

    return 0;
}


/*
    Односвязный список.
    Алгоритмы:
        Создание списка
        Добавление элемента в конец списка
        Добавление элемента в начало списка
        Удаление конечного элемента списка
        Удаление начального элемента списка
        Поиск элемента по заданному значению поля структуры
        Добавление элемента после найденного
        Удаление найденного элемента.
    Использовать указатели
*/