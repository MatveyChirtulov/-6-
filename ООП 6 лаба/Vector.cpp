#include "Vector.h"

Vector::Vector(int s, int k)
{
    size = s;
    data = new int[size];
    for (int i = 0; i < size; i++)
        data[i] = k;
    beg.elem = &data[0];
    end.elem = &data[size];
}

Vector::Vector(const Vector& a)
{
    size = a.size;
    data = new int[size];
    for (int i = 0; i < size; i++)
        data[i] = a.data[i];
    beg = a.beg;
    end = a.end;
}

Vector::~Vector()
{
    delete[]data;
    data = 0;
}

Vector& Vector::operator=(const Vector& a)
{
    if (this == &a)return *this;
    size = a.size;
    if (data != 0) delete[]data;
    data = new int[size];
    for (int i = 0; i < size; i++)
        data[i] = a.data[i];
    beg = a.beg;
    end = a.end;
    return *this;
}

int& Vector::operator[](int index)
{
    if (index < size) return data[index];
    else cout << "\nError! Index>size";
}
Vector Vector::operator*(const int k)
{
    for (int i = 0; i < this->size; ++i)
        this->data[i] *= k;
    return *this;
}

int Vector::operator()()
{
    return this->size;
}
ostream& operator<<(std::ostream& out, const Vector& a)
{
    for (int i = 0; i < a.size; ++i)
        out << a.data[i] << " ";
    return out;
}

istream& operator>>(istream& in, Vector& a)
{
    for (int i = 0; i < a.size; ++i)
        in >> a.data[i];
    return in;
}
