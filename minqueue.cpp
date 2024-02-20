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
    array = 1;
    heap = 0;
    ptrHeap = new T[array];
}

//========================================================
// MinQueue
// copy constructor
//========================================================

template <class T>
MinQueue<T>::MinQueue( const MinQueue<T> &A, int n )
{
    array = n;
    heap = array;
    ptrHeap = new T[heap];

    for(int i = 0; i < n; i++) // i runs till heap-1
    {
        ptrHeap[i] = A[i];
    }

    build_heap();
}

// template <class T>
// MinQueue<T>::MinQueue(const MinQueue<T>& A, int n) {
//     array = n; 
//     if (A.heap < n) {
//         heap = A.heap;
//     } else {
//         heap = n;
//     }
//     ptrHeap = new T[array];

//     for (int i = 0; i < heap; i++) 
//     { 
//         ptrHeap[i] = A.ptrHeap[i]; 
//     }
//     build_heap(); 


//========================================================
// assignment operator
//========================================================

//========================================================
// ~MinQueue
//========================================================

template <class T>
MinQueue<T>::~MinQueue( void )
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
    x = -numeric_limits<T>::infinity(); //x is const cant modify
    ptrHeap[heap-1] =  x;
    decrease_key(heap-1, k);
}

//========================================================
// min
//========================================================

template <class T>
T& MinQueue<T>::min( void )
{
    if (array < 1 || heap < 1)
    {
        cout << "Heap is empty" << endl;
    }
    return ptrHeap[0];
}

//========================================================
// extract_min
//========================================================

template <class T>
T& MinQueue<T>::extract_min()
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
    ptrHeap[i] = k;
    while (i > 1 && ptrHeap[parent(i)] > ptrHeap[i])
    {
        T temp = ptrHeap[parent(i)]; 
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
        T* temp = ptrHeap[i]; //store val in ptr
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
    for (int i = array/2; i >= 1; i--) 
    {
        min_heapify(i);
    }

}

//========================================================
// sort
//========================================================

template <class T>
void MinQueue<T>::sort( const T* A )
{
    build_heap();
    for (int i = array; i >= 2; i--)
    {
        T* temp = ptrHeap[0]; //store val in ptr
        ptrHeap[0] = ptrHeap[i];
        ptrHeap[i] = temp;
        A[array-i-1] = ptrHeap[i]; // A is const, cant modify
        heap--;
        min_heapify(0);
    }
}

//========================================================
// to_string
// Converts Minqueue object to c++ string type.
// Parameters: none
// Return value: string with the elements in set 
// separated by a single space and starting at the head
// Pre-condition: exists a Minqueue object
// Post-condition: return a string of the object's data
//========================================================
template <class T>
string MinQueue<T>::to_string( void )
{
    stringstream result;
    for(int i = 0; i <= heap; i++)
    {
        result << ptrHeap[i] << " ";
    }

    return result.str();
}

//========================================================
// set
// Sets index i in the member array to val
// Parameters: i, val
// Return value: none, but changes object 
// Pre-condition: exists an array
// Post-condition: an array whose value at index i is val
//========================================================
template <class T>
void MinQueue<T>::set( int i, T val )
{
    ptrHeap[i] = val;
}

//========================================================
// allocate
//========================================================
template <class T>
void MinQueue<T>::allocate( int n ) //copy elements to new array?
{
    if (array < n)
    {
        cout << "Array size does not reach minimum." << endl;
        return;
    }
}