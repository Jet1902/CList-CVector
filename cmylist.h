#ifndef CMYLIST_H
#define CMYLIST_H


class CMyList
{
public:
    CMyList();
    CMyList(const CMyList& other);
    ~CMyList();

    CMyList& operator=(const CMyList& other);

    int size() const;

    int at(int i) const;

    int operator[](int i) const;
    int& operator[](int i);

    void push_back(int val);
    int pop_back();
    void push_front(int val);
    int pop_front();

protected:

private:
    struct listNode
    {
//        listNode(int v) : value(v), pNext(nullptr){}
        int value;
        listNode *pNext = nullptr;
    };

    listNode* m_pHead = nullptr;
};

#endif // CMYLIST_H
