#include "cmyvector.h"
#include <QDebug>
// Конструктор класса
CMyVector::CMyVector()
{
    allocate();
}
//Конструктор копирования, вызывается при инициализации экземпляра класса, принимает на вход ссылку на старый экземпляр
CMyVector::CMyVector(const CMyVector &v)
{
    //Выделение памяти под новый буфер с размером старого
    m_pBuffer = new int [v.m_iSize];
    //Копирование всех данных из старого буфера в новый
    memcpy(m_pBuffer, v.m_pBuffer, sizeof(int) * v.m_iNumElements);
    //Присваивание параметру размера нового буфера значения старого
    m_iSize = v.m_iSize;
    //Присваивание параметру количества элементов нового буфера значения старого
    m_iNumElements = v.m_iNumElements;
}
//Деструктор класса
CMyVector::~CMyVector()
{
    free();
}
//Конструктор через присваивание, был перегружен оператор "=", используется при присваивании экземпляру класса значения, принимает на вход ссылку на старый экземпляр
CMyVector &CMyVector::operator=(const CMyVector &v)
{
    //Выделение памяти под новый буфер с размером старого
    m_pBuffer = new int [v.m_iSize];
    //Копирование всех данных из старого буфера в новый
    memcpy(m_pBuffer, v.m_pBuffer, v.m_iNumElements);
    //Присваивание параметру размера нового буфера значения старого
    m_iSize = v.m_iSize;
    //Присваивание параметру количества элементов нового буфера значения старого
    m_iNumElements = v.m_iNumElements;
    //Возвращение созданного буфера, сделано для последовательного присвоения
    return *this;
}

void CMyVector::resize(unsigned int size)
{
    m_iSize = size;
    allocate();
    m_iNumElements = size;
}

void CMyVector::reserve(unsigned int size)
{
    m_iSize = size;
    allocate();
    m_iNumElements = 0;
}

//Функция доступа к элементу массива по индексу
int CMyVector::at(int i) const
{
    return m_pBuffer[i];
}
//Перегрузка оператора для доступа к значению элемента по индексу
int CMyVector::operator[](int i) const
{
    return m_pBuffer[i];
}
//Перегрузка оператора для доступа к элементу по индексу
int& CMyVector::operator[](int i)
{
    return m_pBuffer[i];
}

int *CMyVector::data()
{
    return m_pBuffer;
}

const int *CMyVector::data() const
{
    return m_pBuffer;
}

//Вставка в конец массива
void CMyVector::push_back(int val)
{
    //Если для новых элементов нет места - выделяется дополнительная
    if(m_iSize == m_iNumElements)
        allocate();
    //Присваивание переданного значения элементу в конце
    m_pBuffer[m_iNumElements] = val;
    //Элементов теперь на один больше
    ++m_iNumElements;
}

int CMyVector::pop_back()
{
    return 0;
}

//Вставка в начало массива
void CMyVector::push_front(int val)
{
    //Если для новых элементов нет места - выделяется дополнительная
    if(m_iSize == m_iNumElements)
        allocate();
    //Сдвиг всего массива на один элемент вправо
    memcpy(m_pBuffer + 1, m_pBuffer, sizeof(int) * m_iNumElements);
    //Присваивание переданного значения элементу в конце
    m_pBuffer[0] = val;
    //Элементов теперь на один больше
    ++m_iNumElements;
}

int CMyVector::pop_front()
{

}

void CMyVector::allocate()
{
    //Новый размер равен старому размеру плюс шаг возрастания массива
    int newSize = m_iSize + m_iGrowStep;
    //Объявляется временный указатель, для него выделяется память равная новому размеру
    int *pNewBuffer = new int [newSize];
    //Если массив содержит элементы - копируются все элементы с этого указателя на временный
    if(m_pBuffer && m_iSize && m_iNumElements)
        memcpy(pNewBuffer, m_pBuffer, sizeof(int) * m_iSize);
    //Старая память освобождается
    free();
    //Действующему указателю присваивается значение временного
    m_pBuffer = pNewBuffer;
    //Параметр размера равен новому размеру
    m_iSize = newSize;
}

void CMyVector::free()
{
    //Если массив еще существует - вызываются деструкторы для каждого элемента массива, указатель становится нулевым
    if(m_pBuffer)
    {
        delete [] m_pBuffer;
        m_pBuffer = nullptr;
    }
}
