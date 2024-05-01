// tails.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <cassert>
using namespace std;



template <class T>
struct nodo
{
    T valor;
    nodo<T>* next;
    nodo<T>* prev;
    nodo(T v, nodo<T>* n = NULL, nodo<T>* m = NULL) {
        valor = v;
        next = n;
        prev = m;
    }
    
};

template <class T>
class CFLIST
{
public:
    nodo<T>* head = NULL;
    nodo<T>* p = NULL;
    void push_front(T valor);
    void push_back(T valor);
    void pop_front(T &pos);
    void pop_back(T &pos);
    T& operator[](T id);
    void print();
};

template <class T>
void CFLIST<T>::push_back(T valor)
{
    if (!head)
    {
        head = new nodo <T>(valor, head,head); p = head;
    }
    else
    {
        p->next = new nodo<T>(valor, p->next,p);
        p = p->next;
    }
}

template <class T>
void CFLIST<T>::push_front(T valor)
{
    if (!head)
    {
        head = new nodo <T>(valor, head, head); p = head;
    }
    else
    {
        head = new nodo <T>(valor, head, NULL); head->next->prev = head;
    }
}

template <class T>
void CFLIST<T>::pop_back(T &valor)
{
    if (!head)
    {
        cout << "LA LISTA ENLAZADA ESTA VACIA" << endl;
    }
    if (p == head)
    {
        nodo<T>* tmp = p;
        valor = tmp->valor;
        p = NULL;
        head = NULL;
        delete tmp;
    }
    else
    {
        nodo<T>* tmp = p;
        valor = tmp->valor;
        p = p->prev;
        delete tmp;
        p->next = NULL;
    }
}

template <class T>
void CFLIST<T>::pop_front(T& valor)
{
    if (!head)
    {
        cout << "LA LISTA ENLAZADA ESTA VACIA" << endl;
    }
    if (p == head)
    {
        nodo<T>* tmp = head;
        valor = tmp->valor;
        p = NULL;
        head = NULL;
        delete tmp;
    }
    else
    {
        nodo<T>* tmp = head;
        valor = tmp->valor;
        head = head->next;
        delete tmp;
        head->prev = NULL;
    }
}

template <class T>
void CFLIST<T>::print()
{
    if (!head)
    {
        cout << "LA LISTA ENLAZADA ESTA VACIA" << endl;
    }
    else
    {
        cout << "head->";
        for (nodo<T>* p = head; p; p = p->next)
        {
            cout << p->valor << "->";
        }
        cout << endl;
    }
}

template <class T>
T& CFLIST<T>::operator[](T id) {
    assert(id >= 0);
    nodo<T>* s = head;
    while (s != nullptr && id > 0) {
        s = s->next;
        id--;
    }
    assert(s != nullptr);
    return s->valor;
}




int main()
{
    CFLIST <int> n1;

    n1.push_front(23); n1.push_front(20); n1.push_front(13); n1.push_front(11); n1.push_front(10); n1.push_front(7); n1.push_front(6); n1.push_front(3);
    n1.push_back(15); n1.push_back(12); n1.push_back(8); n1.push_back(4); n1.push_back(1);
    n1.print();
    /*
    int valor_extraido;
    n1.pop_back(valor_extraido);
    cout << "Valor extraido ->" << valor_extraido << endl;
    n1.pop_back(valor_extraido);
    cout << "Valor extraido ->" << valor_extraido << endl;
    n1.pop_back(valor_extraido);
    cout << "Valor extraido ->" << valor_extraido << endl;
    n1.pop_back(valor_extraido);
    cout << "Valor extraido ->" << valor_extraido << endl;
    n1.print();
    n1.pop_front(valor_extraido);
    cout << "Valor extraido ->" << valor_extraido << endl;
    n1.pop_front(valor_extraido);
    cout << "Valor extraido ->" << valor_extraido << endl;
    n1.pop_front(valor_extraido);
    cout << "Valor extraido ->" << valor_extraido << endl;
    n1.pop_front(valor_extraido);
    cout << "Valor extraido ->" << valor_extraido << endl;
    n1.pop_front(valor_extraido);
    cout << "Valor extraido ->" << valor_extraido << endl;
    n1.pop_front(valor_extraido);
    cout << "Valor extraido ->" << valor_extraido << endl;
    n1.pop_front(valor_extraido);
    cout << "Valor extraido ->" << valor_extraido << endl;
    n1.print();
    n1.pop_front(valor_extraido);
    cout << "Valor extraido ->" << valor_extraido << endl;
    n1.pop_front(valor_extraido);
    cout << "Valor extraido ->" << valor_extraido << endl;
    n1.print();
    */
    cout << "Valor en el indice 3: " << n1[3] << endl;
    n1.print();
    n1[2] = 1;
    n1.print();

}


// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
