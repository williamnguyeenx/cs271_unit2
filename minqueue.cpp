//========================================================
// William Nguyen, Cheryl Nguyen, Phan Anh Le
// MinQueue.cpp
// February 2024
// This file contains the class methods for the
// MinQueue class.
//========================================================

#include "minqueue.h"
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
using namespace std;

//========================================================
// define MinQueue class
//========================================================

//========================================================
// MinQueue
// default constructor
//========================================================
template <class T>
MinQueue<T>::MinQueue( void )
{
    array = 0;
    heap = array;
    ptrHeap = new T[heap];
}

//========================================================
// MinQueue
// copy constructor
//========================================================

template <class T>
MinQueue<T>::MinQueue( T* A, int n )
{
    array = n;
    heap = array;
    ptrHeap = new T[heap];

    for(i = 0; i <= heap; i++)
    {
        ptrHeap[i] = A[i]
    }

    build_min_heap()
}


//========================================================
// ~MinQueue
//========================================================

template <class T>
MinQueue<T>::~Minqueue( void )
{
    delete[] ptrHeap;
}

//========================================================
// insert
//========================================================

template <class T>
void MinQueue<T>::insert(const T x)
{
    if (heap >= array)
    {
        throw invalid_argument("heap overflow");
    }
    heap++;
    T k = x;
    x = -numeric_limits<T>::infinity();
    ptrHeap[heap-1] =  x;
    decrease_key(heap-1, k);
}

//========================================================
// min
//========================================================

template <class T>
T MinQueue<T>::min( void )
{
    if (array < 1 || heap < 1)
    {
        cout << "Heap is empty" << endl;
    }
    return ptrHeap[0]
}

//========================================================
// extract_min
//========================================================

template <class T>
T MinQueue<T>::extract_min()
{
    T min = min();
    ptrHeap[0] = ptrHeap[heap-1];
    heap--;
    min_heapify(1);
    return min;
}

//========================================================
// decrease_key
//========================================================

template <class T>
void MinQueue<T>::decrease_key( int i, T k )
{
    if (ptrHeap[i] < k )
    {
        cout << "Cannot decrease to k for k is bigger than the target element" << endl;
        return;
    }

    while (i > 1 && ptrHeap[parent(i)] > ptrHeap[i])
    {
        T* temp = ptrHeap[parent(i)];
        ptrHeap[parent(i)] = ptrHeap[i];
        ptrHeap[i] = temp;
        i = parent(i);
    }
}

//========================================================
// min_heapify
//========================================================

template <class T>
void MinQueue<T>::min_heapify( int i )
{
    int l = left(i);
    int r = right(i);
    int smallest = i;

    if (l <= heap && ptrHeap[l] < ptrHeap[i])
    {
        smallest = l;
    }
    if (r <= heap && ptrHeap[r] < ptrHeap[smallest])
    {
        smallest = r;
    }
    if (smallest != i)
    {
        T* temp = ptrHeap[i];
        ptrHeap[i] = ptrHeap[smallest];
        ptrHeap[smallest] = temp;
        min_heapify(smallest);
    }
}

//========================================================
// build_min_heap
//========================================================

template <class T>
void MinQueue<T>::build_heap( void )
{
    heap = array;
    for (int i = n/2; i >= 1; i--)
    {
        min_heapify(i);
    }

}

//========================================================
// heapsort
//========================================================

template <class T>
void MinQueue<T>::sort( const T* A )
{
    build_heap();
    for (int i = array; i >= 2; i--)
    {
        T* temp = ptrHeap[0];
        ptrHeap[0] = ptrHeap[i];
        ptrHeap[i] = temp;
        A[array-i-1] = ptrHeap[i];
        heap--;
        min_heapify(0)
    }
}

template <typename T>
string MinQueue<T>::to_string(){

    stringstream ss;
    string s = "";
    
    for(int i = 0; i < size; i++){ // converts the element into a string form
        ss.str("");
        ss << heap[i] << " "; 
        s = s + ss.str();
    }
   
    return s.substr(0,s.size()-1);
}