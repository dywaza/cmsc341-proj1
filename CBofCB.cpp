#include <iostream>
#include "CBofCB.h"
using namespace std;

CBofCB::CBofCB()
{
    //m_obCapacity == 7
    //m_buffers[7] = {};

    m_buffers[0] = new InnerCB(10);
    m_obSize = 1;
    m_oldest = 0; //start
    m_newest = 0; //end
}

/*
CBOfCB::CBofCB(const CBofCB& other)
{

}
*/

CBofCB::~CBofCB()
{
    /*
    for (int i = 0; i < m_obCapacity ; i++)
    {
        delete m_buffers[i];
    }
    delete [] m_buffers;
    */
}

void CBofCB::enqueue(int data)
{
    //Adds an object to the currently pointed array.
    if (isFull())
    {
        //throw "Congrats, you literally created more arrays than God.";
    }

    if (m_buffers[m_newest]->isFull())
    {
        m_newest++;
        if (m_newest >= m_obCapacity) //NOTE!!!: May be m_obCapacity - 1. Check back
        {
            m_newest = 0;
            m_buffers[m_newest] = new InnerCB(2*(m_buffers[m_obCapacity-1]->capacity()));
        }
        else{
            m_buffers[m_newest] = new InnerCB(2*(m_buffers[m_newest-1]->capacity()));
        }
        m_obSize++;
    }

    else {
        //m_newest++;
    }

    m_buffers[m_newest]->enqueue(data);

}

int CBofCB::dequeue()
{
    int returnable = -1;
    if (isEmpty())
    {
        throw "Error: Something goofed. (ERR_CODE 13370)";
    }
    else {
        //m_oldest++;
        /*
        if (m_buffers[m_oldest]->isEmpty())
        {
            m_oldest++;
            if (m_oldest >= m_obCapacity) //NOTE!!!: Check here, too.
            {
                m_oldest = 0;
                delete m_buffers[m_obCapacity];
            }
            else {
                delete m_buffers[m_oldest-1];
            }
            m_obSize--;
        }
        else {
            //m_oldest++;
        }
        */
        if (m_buffers[m_oldest]->size() == 1)
        {
            returnable = m_buffers[m_oldest]->dequeue();
            m_oldest++;
            if (m_oldest >= m_obCapacity) //NOTE!!!: Check here, too.
            {
                m_oldest = 0;
                delete m_buffers[m_obCapacity];
            }
            else {
                delete m_buffers[m_oldest-1];
            }
            m_obSize--;
            return returnable;
        }
    }

    returnable = m_buffers[m_oldest]->dequeue();
    return returnable;
}

bool CBofCB::isFull()
{
    if (m_obSize >= m_obCapacity)
    {
        return true;
    }
    else {
        return false;
    }
}

bool CBofCB::isEmpty()
{
    if (m_obSize == 0)
    {
        return true;
    }
    else {
        return false;
    }
}

int CBofCB::size()
{
    //idea: subtract max. amount from c whenever it overflows
    int totesSize = 0;
    if (m_oldest <= m_newest)
    {
        for (int c = m_oldest; c <= m_newest; c++) //ha, c++. how meta.
        {
            totesSize = totesSize + m_buffers[c]->size();
        }
    }
    if (m_oldest > m_newest)
    {
        int c = m_oldest;
        do
        {
            totesSize = totesSize + m_buffers[c]->size();
            c++;
            if (c >= m_obCapacity)
            {
                c = 0;
            }
        }while (c != m_newest+1);
    }
    return totesSize;
}

void CBofCB::dump()
{
        if (m_oldest <= m_newest)
    {
        for (int c = m_oldest; c <= m_newest; c++)
        {
            cout << "array " << c << ":" << endl;
            m_buffers[c]->dump();
            cout << endl;
        }
    }
    if (m_oldest > m_newest)
    {
        int c = m_oldest;
        while (c != m_newest)
        {
            cout << "array " << c << ":" << endl;
            m_buffers[c]->dump();
            cout << endl;
            c++;
            if (c >= m_obCapacity)
            {
                c = 0;
            }
        }
    }
}

