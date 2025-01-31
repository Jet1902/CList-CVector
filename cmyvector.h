#ifndef CMYVECTOR_H
#define CMYVECTOR_H

// Класс массива целых чисел
class CMyVector
{
public:
    CMyVector();
    CMyVector(const CMyVector& v);              // Конструктор копирования
    ~CMyVector();

    CMyVector& operator=(const CMyVector& v);   // Оператор присвоения другого массива

    void resize(unsigned int size);             // Изменение размера массива так, чтобы он содержал size элементов
                                                // Значения элементов при этом не инициализируются

    void reserve(unsigned int size);            // Выделить (зарезервировать) память так, чтобы в в массив можно было добавить size элементов
                                                // без перевыделения памяти

    int size() const                            // Возврат размера массива
        { return m_iNumElements; }

    int at(int i) const;

    int operator[](int i) const;
    int& operator[](int i);

    int *data();
    int const *data() const;

    void push_back(int val);
    int pop_back();
    void push_front(int val);
    int pop_front();

protected:
    void allocate();
    void free();

private:
    int *m_pBuffer = nullptr;
    int m_iSize = 0;
    int m_iNumElements = 0;
    const int m_iGrowStep = 4;
};

#endif // CMYVECTOR_H
