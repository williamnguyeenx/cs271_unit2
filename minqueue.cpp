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
// Create an empty MinQueue
// Parameter: None
// Return value: None
// Pre-condition: None
// Post-condition: MinQueue object created
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
// Create a MinQueue and copy elements from an existing MinQueue
// Parameter: const MinQueue<T> &A - Object's elements to be copied
//            int n - size of array to be set for the newly create MinQueue object
// Return value: None
// Pre-condition: Exists a MinQueue object
// Post-condition: Created a copy of the existing MinQueue object
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
// Destructor
// Parameter: None
// Return value: None
// Pre-condition: Exist a MinQueue object
// Post-condition: MinQueue object deallocated
//========================================================

template <class T>
MinQueue<T>::~MinQueue( void )
{
    delete[] ptrHeap;
}

//========================================================
// insert
// Insert an element into MinQueue
// Parameter: T x - element to be inserted
// Return value: None
// Pre-condition: MinQueue object have spare capacity for new element(s)
// Post-condition: Updated MinQueue object with the new element
//========================================================

template <class T>
void MinQueue<T>::insert(const T& x)
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
// Get the smallest element of MinQueue
// Parameter: None
// Return value: smallest element in heap
// Pre-condition: Exist a MinQueue object
// Post-condition: Return the smallest element in the MinQueue
//========================================================

template <class T>
T& MinQueue<T>::min(void)
{
    if (array < 1 || heap < 1)
    {
        cout << "Heap is empty" << endl;
    }
    return ptrHeap[0];
}

//========================================================
// extract_min
// Get and remove the smallest element of MinQueue
// Parameter: None
// Return value: smallest element in heap
// Pre-condition: Exist a MinQueue object
// Post-condition: Return the smallest element in the MinQueue 
// and extract it from heap
//========================================================

template <class T>
T& MinQueue<T>::extract_min(void)
{
    T min = min();
    ptrHeap[0] = ptrHeap[heap-1];
    heap--;
    min_heapify(1);
    return min;
}

//========================================================
// decrease_key
// Decrease the targeted element's key to a new key
// Parameter: int i - position of the element in MinQueue
//            T k - new key value
// Return value: None
// Pre-condition: Exists non-empty MinQueue object that is
// at least to index i
// Post-condition: MinQueue object with updated targeted element
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
// Satisfy and maintain min-heap property in MinQueue object
// Parameter: int i - targeted element
// Return value: None
// Pre-condition: Children of element at index i must be min-heap
// Post-condition: MinQueue satisfy the min-heap property
//========================================================

template <class T>
void MinQueue<T>::min_heapify(int i)
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
        T temp = ptrHeap[i]; 
        ptrHeap[i] = ptrHeap[smallest];
        ptrHeap[smallest] = temp;
        min_heapify(smallest);
    }
}

//========================================================
// build_heap
// Produce a min-heap for MinQueue object
// Parameter: None
// Return value: None
// Pre-condition: Exist non-empty MinQueue object
// Post-condition: Created a min-heap MinQueue object
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
// Sorts the heap in ascending order
// Parameter: reference call to heap 
// Return value: None
// Pre-condition: Exist non-empty MinQueue object
// Post-condition: Created a min-heap MinQueue object
//========================================================

template <class T>
void MinQueue<T>::sort(const MinQueue<T> &A)
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

// template <class T>
// void MinQueue<T>::sort(T* A)  //not constant 
// { 
//     build_heap(); 
//     for (int i = heap - 1; i >= 1; i--) {
//         T temp = ptrHeap[0];
//         ptrHeap[0] = ptrHeap[i];
//         ptrHeap[i] = temp;
//         A[heap - 1 - i] = temp;  //correct indexing
//         heap--; 
//         min_heapify(0); 
//     }
// }

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
string MinQueue<T>::to_string( void ) const
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
void MinQueue<T>::set( int i, const T& val )
{
    ptrHeap[i] = val;
}

//========================================================
// allocate
// Creates a new array with capacity of at least n
// Parameter: int n - new capacity
// Return value: None
// Pre-condition: Exist non-empty MinQueue object
// Post-condition: Created a MinQueue object
// of size at least n
//========================================================
template <class T>
void MinQueue<T>::allocate( int n ) 
{
    if (n <= array)
        return;

    T* newPtrHeap = new T[n];

    for (int i = 0; i < heap; i++)
        newPtrHeap[i] = ptrHeap[i];

    delete[] ptrHeap;
    ptrHeap = newPtrHeap;
    array = n;
}