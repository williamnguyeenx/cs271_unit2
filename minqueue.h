//========================================================
// William Nguyen, Cheryl Nguyen, Phan Anh Le
// minqueue.h
// February 2024
// This file contains the Minqueue class declaration.  
//========================================================
#include <iostream>

using namespace std;

#ifndef MINQUEUE_H
#define MINQUEUE_H

template <class T>
class MinQueue{
    private:
        T *ptrHeap; 
        int array;
        int heap;

        int    parent  ( int i )
        {
            return floor(i/2);
        } 

        int    left    ( int i )
        {
            return 2*i+1;
        }

        int    right   ( int i )
        {
            return 2*i+2;
        }

    public:
                            MinQueue            (void);
                            MinQueue            (const MinQueue<T> &A, int n);
        MinQueue<T>         operator=           (const MinQueue<T> &A, int n);
                            ~MinQueue           (void);
        void                insert              (T x)
        T&                  min                 (const MinQueue<T> &A);
        T&                  extract_min         (const MinQueue<T> &A);
        void                decrease_key        (int i, T k);
        void                min_heapify         (int i);
        void                build_heap          (void);
        void                sort                (T* A);
        string              to_string           (void);
        void                set                 (int i, T val);
        void                allocate            (int n);

friend ostream & operator << ( ostream &os, const MinQueue<T> A )
    {
        os << "[ ";
        for ( int i = 0; i < A.heap; i++ )
            os << A.ptrHeap[i] << ", ";
        if ( A.heap != 0 )
            os << A.ptrHeap[A.heap-1] << " ]";
        else
            os << " ]";
        return os;
    }
};

#include "minqueue.cpp"
#endif

