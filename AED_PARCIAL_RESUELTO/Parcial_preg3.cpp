#include <iostream>

class XVector
{
public:
    int size = 0;
    int size_map, size_vec;
    int** INI_vec_pt = NULL;
    int** FIN_vec_pt = NULL;
    int** s = NULL;
    int* INI = NULL;
    int* FIN = NULL;
    int* p = NULL;
    XVector(int size_map, int size_vec);
    ~XVector();


    void push_back(int value)
    {
        if (p != FIN)
        {
            *p = value;
            p++;

        }
        else
        {
            s++;
            if (s == FIN_vec_pt)
            {
                size_map = size_map * 2;
                int** tmp = INI_vec_pt;
                INI_vec_pt = new int* [size_map];
                s = INI_vec_pt;
                for (int** i = INI_vec_pt; tmp != FIN_vec_pt; tmp++, i++,s++)
                {
                    *i = *tmp;
                }
                FIN_vec_pt = INI_vec_pt + size_map;
            }
            *s = new int[size_vec];
            p = *s;
            *p = value;
            p++;
            FIN = *s + size_vec;
        }
        size++;
    }
    void push_front(int value)
    {
        int* i = FIN;
        int** J = s;
        int** I = s;
        for (; i != p - 1; i--);
        int* j = i + 1;
        if (j == FIN)
        {
            s++;
            if (s == FIN_vec_pt)
            {
                size_map = size_map * 2;
                int** tmp = INI_vec_pt;
                INI_vec_pt = new int* [size_map];
                s = INI_vec_pt;
                for (int** i = INI_vec_pt; tmp != FIN_vec_pt; tmp++, i++, s++)
                {
                    *i = *tmp;
                }
                FIN_vec_pt = INI_vec_pt + size_map;
            }
            *s = new int[size_vec];
            p = *(s);
            FIN = *s + size_vec;
            j = *s;
            J = s;
        }
        *j = *i;
        i--;
        j--;
        while (i != INI - 1)
        {
            if (j == (*J) -1)
            {
                J--;
                j = (*J) + size_vec - 1;
                
            }
            if (i == (*I) -1)
            {
                I--;
                i = (*I) + size_vec - 1;
            }
            std::swap(*i, *j);
            i--; j--;
        }
        p++;
        *INI = value;
        size++;
    }
    int& operator[](int value)
    {
        if (value < size)
        {
            int** t = INI_vec_pt;
            t = t + (value / 3);
            int* j = *t;
            return *(j+(value % 3));
        }
    }
};

XVector::XVector(int sm, int sv)
{
    size_map = sm;
    size_vec = sv;
    INI_vec_pt = new int* [size_map];
    FIN_vec_pt = INI_vec_pt + size_map;
    s = INI_vec_pt;
    *INI_vec_pt = new int[size_vec];
    INI = *INI_vec_pt;
    FIN = INI + size_vec;
    p = INI;
}

XVector::~XVector()
{}

void print(XVector* p)
{ //no modificar esta función
    for (int i = 0; i < p->size; i++)
        std::cout << (*p)[i] << " ";
    std::cout << "\n";
}

int main()
{
    //no modificar esta función main
    XVector v(4, 3);
    v.push_back(3); v.push_back(8); v.push_back(1);
    v.push_back(4); v.push_back(9); v.push_back(6);
    v.push_back(7);
    print(&v);
    v.push_front(5); v.push_front(2);
    print(&v);
    v.push_front(11); v.push_front(17);
    v.push_back(22);
    print(&v);
    v.push_front(33); v.push_back(77);
    print(&v);
}
