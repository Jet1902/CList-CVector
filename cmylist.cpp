#include "cmylist.h"
#include <QtGlobal>

CMyList::CMyList()
{
}

CMyList::CMyList(const CMyList &other)
{

}

CMyList::~CMyList()
{
    listNode *curNode = m_pHead;
    while(curNode)
    {
        listNode *next = curNode->pNext;
        delete curNode;
        curNode = next;
    }
}

CMyList &CMyList::operator=(const CMyList &other)
{

}

int CMyList::size() const
{
    int size = 0;

    listNode *curNode = m_pHead;
    while(curNode)
    {
        ++size;
        curNode = curNode->pNext;
    }
    return size;
}

int CMyList::at(int i) const
{
    listNode *curNode = m_pHead;
    for(int j = 0; j < i; ++j)
    {
        curNode = curNode->pNext;
    }
    return curNode->value;
}

int CMyList::operator[](int i) const
{
    listNode *curNode = m_pHead;
    for(int j = 0; j < i; ++j)
    {
        curNode = curNode->pNext;
    }
    return curNode->value;
}

int &CMyList::operator[](int i)
{
    listNode *curNode = m_pHead;
    for(int j = 0; j < i; ++j)
    {
        curNode = curNode->pNext;
    }
    return curNode->value;
}

void CMyList::push_back(int val)
{
    if(m_pHead == nullptr)
    {
        m_pHead = new listNode();
        m_pHead->value = val;

    }
    else
    {
        listNode *curNode = m_pHead;
        while(curNode->pNext)
            curNode = curNode->pNext;
        curNode->pNext = new listNode();
        curNode->pNext->value = val;
    }
}

int CMyList::pop_back()
{
    Q_ASSERT_X(m_pHead, "pop_back()", "Empty list");
    int retVal;
    if(!m_pHead->pNext)
    {
        retVal = m_pHead->value;
        delete m_pHead;
        m_pHead = nullptr;
    }
    else
    {
        listNode *curNode = m_pHead;
        listNode *prevNode = nullptr;
        while(curNode->pNext)
        {
            prevNode = curNode;
            curNode = curNode->pNext;
        }
        retVal = curNode->value;
        delete curNode;
        prevNode->pNext = nullptr;
    }

    return retVal;
}

void CMyList::push_front(int val)
{
    listNode *curNode = new listNode();
    curNode->pNext = m_pHead;
    curNode->value = val;
    m_pHead = curNode;
}

int CMyList::pop_front()
{
    Q_ASSERT_X(m_pHead, "pop_front()", "Empty list");
    int val = m_pHead->value;
    listNode *toDel = m_pHead;
    m_pHead = m_pHead->pNext;
    delete toDel;
    return val;
}
