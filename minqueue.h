#include <iostream>

using namespace std;

#ifndef MINQUEUE_H
#define MINQUEUE_H

template <class T>
class Minqueue{
    private:
        parent( int i );
        left( int i );
        right( int i );

    public:
                    Minqueue            ( void );
                    Minqueue            ( T* A, int n );
                    ~Minqueue           ( void );
        void        insert              ( const T x ):
        T           min                 ( void );
        T           extract_min         ( void );
        void        decrease_key        ( int i, T k );
        void        min_heapify         ( int i );
        void        build_min_heap      ( void );
        void        heapsort            ( const T& A );
        string      to_string           ( void );
};

#include "minqueue.cpp"
#endif

