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
            return 2*i;
        }

        int    right   ( int i )
        {
            return 2*i+1;
        }

    public:
                            MinQueue            (void);
                            MinQueue            (const MinQueue<T> &A, int n);
        MinQueue<T>         operator=           (const MinQueue<T> &A, int n);
                            ~MinQueue           (void);
        void                insert              (const T& x);
        T&                  min                 (void);
        T&                  extract_min         (void);
        void                decrease_key        (int i, T k);
        void                min_heapify         (int i);
        void                build_heap          (void);
        void                sort                (void);
        string              to_string           (void) const;
        void                set                 (int i, const T& val);
        void                allocate            (int n);

friend std::ostream& operator<<(std::ostream& os, const MinQueue<T>& A) {
        os << "[ ";
        for (int i = 0; i < A.heap; i++) 
        {
            os << A.ptrHeap[i];
            if (i < A.heap - 1) os << ", ";
        }
        os << " ]";
        return os;
    }
};

#include "minqueue.cpp"
#endif

