#include <QCoreApplication>

#include "cmyvector.h"
#include "cmylist.h"

#include <QDebug>

void print(const CMyVector& v)
{
    for(int i = 0; i < v.size(); ++i)
        qDebug() << v[i];
}

void sort(CMyVector& v)
{

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

//    CMyVector v1;

//    int array[10];

//    for(int i = 0; i < 10; ++i)
//    {
//        v1.push_front(i);
//        array[i] = i*i;
//    }

//    CMyVector v2 = v1;

//    print(v2);

//    CMyVector v3;
//    v3.resize(10);
//    memcpy(v3.data(), array, sizeof(int) * 10);

//    print(v3);

    CMyList l1;

    for(int i = 0; i < 10; ++i)
        l1.push_back(i);

    qDebug() << l1[50];
    for(int i = 0; i < 10; ++i)
        qDebug() << l1.pop_back();

    return a.exec();
}


void ptr()
{
    int c = 21;

    int *a = &c; // a - указатель
    double* f;
    double ff;
    *a = 10;     // разыменование, значение по адресу a
    &c;     // адрес с

    int& b = c; // b - ссылка

    qDebug() << a << *a << c << &c;
}
