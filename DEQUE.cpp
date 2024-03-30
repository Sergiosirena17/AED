// Deque implementation in C++

#include <iostream>
using namespace std;

#define MAX 10

struct Deque {
    int size_vector_pointer{ 0 };
    int size_vector{ 0 };
    int** vector = NULL;
    int** vector_fin = NULL;
    int** s = NULL;
    int** t = NULL;
    int* p = NULL;
    int* q = NULL;
    int* INI = NULL;
    int* FIN = NULL;
    bool flag{ false };

    Deque(int size_pointer_vector, int size_vector_)
    {
        size_vector_pointer = size_pointer_vector;
        size_vector = size_vector_;
        vector = new int* [size_vector_pointer];
        vector_fin = vector + size_vector_pointer - 1;
        s = vector + (size_vector_pointer / 2);
        t = s;
        *s = new int[size_vector];
        p = *s + (size_vector / 2);
        q = p;
        INI = *s;
        FIN = p + (size_vector / 2);
    }

    void push_back(int valor)
    {
        if (p == FIN + 1)
        {
            if (t + 1 == vector_fin + 1)
            {
                cout << "EXPANDIENDO VECTOR DE PUNTEROS" << endl;
                int** tmp = vector;
                int size_pointer_before = size_vector_pointer;
                size_vector_pointer = (size_vector_pointer * 2) + 1;
                vector = new int* [size_vector_pointer];
                vector_fin = vector + size_vector_pointer - 1;
                int x = ((size_vector_pointer % size_pointer_before) + size_pointer_before) / 2;

                int** i = vector + x;
                int** j = tmp;

                for (; i != vector_fin - x + 1; i++, j++)
                {
                    if (j == s)
                    {
                        s = i;
                    }
                    if (j == t)
                    {
                        t = i;
                    }
                    *i = *j;
                }
                delete[] tmp;

            }
            t++;
            *t = new int[size_vector];
            p = *t;
            FIN = p + size_vector - 1;
            *p = valor;
            p++;
        }
        else
        {
            *p = valor;
            p++;
            if (!flag)
            {
                q--;
                flag = true;
            }
        }
        flag = true;
    }

    void push_front(int valor)
    {
        if (q == INI - 1)
        {
            if (s-1 == vector-1)
            {
                cout << "EXPANDIENDO VECTOR DE PUNTEROS" << endl;
                int** tmp = vector;
                int size_pointer_before = size_vector_pointer;
                size_vector_pointer = (size_vector_pointer * 2) + 1;
                vector = new int* [size_vector_pointer];
                vector_fin = vector + size_vector_pointer - 1;
                int x = ((size_vector_pointer % size_pointer_before) + size_pointer_before) / 2;

                int** i = vector + x;
                int** j = tmp;

                for (; i != vector_fin - x + 1; i++, j++)
                {
                    if (j == s)
                    {
                        s = i;
                    }
                    if (j == t)
                    {
                        t = i;
                    }
                    *i = *j;
                }
                delete[] tmp;
            }
                s--;
                *s = new int[size_vector];
                q = *s + size_vector - 1;
                INI = *s;
                *q = valor;
                q--;
        }
        else
        {
            *q = valor;
            q--;
            if (!flag)
            {
                p++;
                flag = true;
            }
        }
        flag = true;
    }

    void pop_front(int& valor)
    {
        if (q + 1 == p)
        {
            cout << "EL VECTOR ESTA VACIO" << endl;
        }
        else
        {
            if (q + 2 == INI + size_vector)
            {
                valor = *(q + 1);
                int** tmp = s;
                s++;
                INI = *s;
                q = INI - 1;
                delete[] * tmp;
                *(s - 1) = NULL;
            }
            else
            {
                valor = *(q + 1);
                q++;
            }
        }
    }
    void pop_back(int& valor)
    {
        if (p - 1 == q)
        {
            cout << "EL VECTOR ESTA VACIO" << endl;
        }
        else
        {
            if (p - 2 == FIN - size_vector)
            {
                valor = *(p - 1);
                int** tmp = t;
                t--;
                FIN = *t + size_vector - 1;
                p = FIN + 1;
                delete[] * tmp;
                *(t + 1) = NULL;
            }
            else
            {
                valor = *(p - 1);
                p--;
            }
        }
    }

    void find(int** i, int*& begin, int*& end)
    {
        bool flag_2 = false; 
        bool flag_3 = false;
        for (int* k = *i; k != *i + size_vector; k++)
        {
            if (k == q + 1)
            {
                begin = k; 
                flag_2 = true;
            }
            if (k == p - 1)
            {
                end = k; 
                flag_3 = true;
            }
        }
        if (!flag_2)
        {
            begin = *i;
        }
        if (!flag_3)
        {
            end = *i + size_vector - 1;
        }

    }

    void print()
    {
        for (int** tmp = s; tmp != t + 1; tmp++)
        {
            int* start = NULL; int* end = NULL;
            find(tmp, start, end);
            for (; start != end + 1; start++)
            {
                cout << *start << "->";
            }
            cout << "  =>  ";
        }
        cout << endl;
    }
};

int main() {
    Deque dq(5, 3);
    int valor_extraido;

    for (int i = 0; i < 6; ++i) {
        dq.push_front(i);
    }
    dq.print();
    dq.push_front(3); dq.push_front(2); dq.push_front(1); dq.push_front(4); dq.push_front(7); dq.push_front(0); dq.push_front(3); dq.push_front(2); dq.push_front(1); dq.push_front(4); dq.push_front(7); dq.push_front(0);
    dq.print();
    dq.push_back(7); dq.push_back(8); dq.push_back(9); dq.push_back(1); dq.push_back(0); 
    dq.print();
    dq.pop_back(valor_extraido);
    cout << "Valor extraido: " << valor_extraido << endl;
    dq.pop_back(valor_extraido);
    cout << "Valor extraido: " << valor_extraido << endl;
    dq.pop_back(valor_extraido);
    cout << "Valor extraido: " << valor_extraido << endl;
    dq.pop_back(valor_extraido);
    cout << "Valor extraido: " << valor_extraido << endl;
    dq.print();
    dq.pop_front(valor_extraido);
    cout << "Valor extraido: " << valor_extraido << endl;
    dq.pop_front(valor_extraido);
    cout << "Valor extraido: " << valor_extraido << endl;
    dq.pop_front(valor_extraido);
    cout << "Valor extraido: " << valor_extraido << endl;
    dq.pop_front(valor_extraido);
    cout << "Valor extraido: " << valor_extraido << endl;
    dq.print();
    dq.push_front(3); dq.push_front(2); dq.push_front(1); dq.push_front(4); dq.push_front(7); dq.push_front(7);
    dq.print();
    dq.push_back(7); dq.push_back(8); dq.push_back(9); dq.push_back(1); dq.push_back(0);
    dq.print();
    dq.push_back(7); dq.push_back(8); dq.push_back(9); dq.push_back(1); dq.push_back(0); dq.push_back(0);
    dq.print();
    
}