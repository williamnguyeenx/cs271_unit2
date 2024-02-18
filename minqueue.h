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
        Node *ptrHeap;
        int array;
        int heap;

        parent( int i );
        left( int i );
        right( int i );

    public:
                    MinQueue            ( void );
                    MinQueue            ( T* A, int n );
                    ~MinQueue           ( void );
        void        insert              ( const T x ):
        T           min                 ( void );
        T           extract_min         ( void );
        void        decrease_key        ( int i, T k );
        void        min_heapify         ( int i );
        void        build_heap          ( void );
        void        sort                ( const T* A );
        string      to_string           ( void );

};

#include "minqueue.cpp"
#endif

