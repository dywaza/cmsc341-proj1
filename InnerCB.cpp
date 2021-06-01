#include <iostream>
#include "InnerCB.h"
using namespace std;

InnerCB::InnerCB(int n)
{
    m_buffer = new int [n]; //makes the array!
    m_size = 0; //current number of elements in queue
    m_start = 0; //start of the queue. Pop values from here.
    m_end = -1; //end of the queue. New values go here.
    m_capacity = n; //size of the array/ largest size of the queue
}

InnerCB::InnerCB(const InnerCB& other)
{
    m_buffer = other.m_buffer;
    m_size = other.m_size;
    m_start = other.m_start;
    m_end = other.m_end;
    m_capacity = other.m_capacity;
}

InnerCB::~InnerCB()
{
    //delete [] m_buffer;
}

void InnerCB::enqueue (int data)
{
    //if(isEmpty())
    //    m_start++;
    if (isFull())
    {

    }
        //throw "Error: Something goofed. (ERR_CODE 60025)";

    if (m_end == m_capacity -1)
    {
       m_end = 0;
    }
    else {
    m_end++;
    }

    m_buffer[m_end] = data;
    m_size++;

    //cout << "Adding [" << m_buffer[m_end] << "] to the queue." << endl;
}

int InnerCB::dequeue ()
{
    if (isEmpty())
    {
        throw "ERR: Cannot remove the empty queue!";
    }
        //throw "Error: Something goofed. (ERR_CODE 95483)";

    int returnable = m_buffer[m_start];
   // m_start++;

    if (m_start == m_capacity-1)
    {
        m_start = 0;
    }
    else {
        m_start++;
    }

    m_size--;


    //cout << "Removing [" << returnable << "] from the queue." << endl;
    return returnable;
}

bool InnerCB::isFull ()
{
    if (m_size == m_capacity)
        return true;
    return false;
}

bool InnerCB::isEmpty ()
{
    if (m_size == 0)
        return true;
    return false;
}

int InnerCB::capacity ()
{
    return m_capacity;
}

int InnerCB::size ()
{
    return m_size;
}

//const InnerCB& operator=(const InnerCB& rhs)
//{
    //come back to this
//}

void InnerCB::dump ()
{
    /*
    cout << "Your face is a dump." << endl;
    cout << "OHHHHHH! YOU JUST GOT TOLD" << endl;
    */
    //cout << "\"BEGIN\"" << endl;
    for (int ct = 0; ct < m_capacity; ct++)
    {
        if (ct == m_start)
            cout << " (ST)";
        if (ct == m_end)
            cout << " (EN)";
        cout << "[" << ct << "] " << m_buffer[ct] << " || ";
    }
    cout << endl;
}

