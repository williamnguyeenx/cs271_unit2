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
    array = 1;                                              // Initial capacity, adjust as needed
    heap = 0;                                               // Initially, the heap is empty
    ptrHeap = new T[array];                                 // Allocate memory for the heap with initial capacity
}

//========================================================
// MinQueue
// copy constructor
// Create a MinQueue and copy elements from an existing MinQueue
// Parameter: const MinQueue<T> &A - Object's elements to be copied
//            int n - size of array to be set for the 
//                    newly create MinQueue object
// Return value: None
// Pre-condition: Exists a MinQueue object
// Post-condition: Created a copy of the existing MinQueue object
//========================================================

template <class T>
MinQueue<T>::MinQueue( T* A, int n )
{
    if (n < 0)                                              // Ensure n is not negative
    {
        cout << "Array size cannot be negative" << endl;
    }

    array = n;                                              // Set the capacity to n
    heap = n;                                               // The heap size is also n since we're copying all elements
    ptrHeap = new T[array];                                 // Allocate memory for the heap

    for(int i = 0; i < n; i++) 
    {
        ptrHeap[i] = A[i];                                  // Copy each element from A to ptrHeap
    }

    build_heap();                                           // Transform the array into a min heap
}


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
// assignment operator
// Create a new heap from the current heap by copying current
// values and deleting the current heap
// Parameter: reference call to MinQueue A - object to be copied
// Return value: a MinQueue object
// Pre-condition: Exist a MinQueue object
// Post-condition: Created a copy of the existing MinQueue object
//========================================================

template <class T>
MinQueue<T> MinQueue<T>::operator= ( const MinQueue<T> &A )
{
    if (this != &A)                                                 // Prevent self-assignment
        delete [] ptrHeap;                                          // Deallocate original heap

    array = A.array;                                                // Set the capacity to A's capacity
    heap = A.heap;                                                  // Set the heap size to A's heap size
    ptrHeap = new T[array];                                         // Allocate memory for the new heap

    for(int i = 0; i < heap; i++) 
    {
        ptrHeap[i] = A[i];                                          // Copy each element from A to ptrHeap
    }

    build_heap();                                                   // Transform the array into a min heap

    return *this;                                                   // Return address of copied heap
}

//========================================================
// insert
// Insert an element into MinQueue
// Parameter: T x - element to be inserted
// Return value: None
// Pre-condition: MinQueue object have spare capacity 
// for new element(s)
// Post-condition: Updated MinQueue object with the 
// new element inserted
//========================================================

template <class T>
void MinQueue<T>::insert(const T& x)
{
    if (heap == array)                                          // If heap size reaches capacity -> increase size to insert
        allocate(array * 2);                                    // Create a new heap with bigger capacity 

    ptrHeap[heap] = x;                                        // Place x at the end of the heap
    heap++;                                                     // Increase heap size
    int i = heap - 1;                                           // Trace heap from bottom

    decrease_key(i, x);
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
T MinQueue<T>::min(void)
{
    if (heap == 0)
    {
        return T();
    }
    return ptrHeap[0];                                          // Return the first element in heap because it's the smallest
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
T MinQueue<T>::extract_min(void)
{
    if (heap == 0)
    {
        return T();
    }

    T minElement = ptrHeap[0];                                  // Min element is the first element
    ptrHeap[0] = ptrHeap[heap-1];                               // Push first element to the bottom 
    heap--;                                                     // Decrease the size of the heap to remove last element from heap

    if (heap > 0)
        min_heapify(0);                                         // Restore the min-heap property

    return minElement;                                          // Return the minimum element
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
void MinQueue<T>::decrease_key(int i, T k)
{
    if (i < 0 || i >= heap)                                     // Check if i is out of bound
    {
        return;
    }

    if (ptrHeap[i] < k )                                        // Check if new key is bigger than current key
    {
        return;
    }

    ptrHeap[i] = k;                                             // Assign new key to current key

    while (i > 0 && ptrHeap[parent(i)] > ptrHeap[i])            // Find the correct position for new key
    {
        swap(ptrHeap[i], ptrHeap[parent(i)]);                   // Constantly switch val at i so that it's smaller than those behind
        i = parent(i);                                          // Check if new position still satisfies min-heap property
    }
}

//========================================================
// min_heapify
// Maintain min-heap property of MinQueue object
// Parameter: int i - targeted element
// Return value: None
// Pre-condition: Children of element at index i must be min-heap
// Post-condition: MinQueue satisfies the min-heap property
//========================================================

template <class T>
void MinQueue<T>::min_heapify(int i)
{
    int l = left(i);                                            // Get left child index
    int r = right(i);                                           // Get right child index
    int smallest = i;                                           // Variable to store smallest value when comparing

    if (l < heap && ptrHeap[l] < ptrHeap[i])                    // Value at l is the smallest if it's smaller than value at i 
        smallest = l;

    if (r < heap && ptrHeap[r] < ptrHeap[smallest])             // Value at r is the smallest if it's smaller than the current smallest
        smallest = r;
    
    
    if (smallest != i)                                          // If the smallest is not the current node, swap it with the smallest and heapify the subtree
    {
        swap(ptrHeap[i], ptrHeap[smallest]);
        min_heapify(smallest);                                  // Heapify the subtree from smallest 
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
    for (int i = floor(array/2); i >= 0; i--) 
    {
        min_heapify(i);                                     //Run min_heapify
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
void MinQueue<T>::sort(T* A)
{
    build_heap();                                           // Establishes min-heap property
    for (int i = array-1; i >= 0; i--)                      // Iterate from the bottom of the heap
    {
        T temp = ptrHeap[0];                                // Swap root element with the last element in the heap
        ptrHeap[0] = ptrHeap[i];
        ptrHeap[i] = temp;
        A[array-i-1] = ptrHeap[i];                          // Add the current smallest element at the end of array A
        heap--;                                             // Decrease size to no longer access the current last element
        min_heapify(0);                                     // Reestablises the min-heap property in heap
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
string MinQueue<T>::to_string( void ) const
{
    stringstream result;                                    // Stringstream object to hold the data of heap
    for(int i = 0; i <= heap-1; i++)                        // For loop to extract data from heap
    {
        if (i != heap-1)                                    // If statement to avoid whitespace at the end of the string
            result << ptrHeap[i] << " ";                    // Add data from heap to stringstream object
        else
            result << ptrHeap[i];
    }

    return result.str();                                    // Convert stringstream to string type
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

// {
//     if (i >= 0 && i < heap) 
//     {
//         ptrHeap[i] = val;
//         if (i != 0 && ptrHeap[i] < ptrHeap[parent(i)]) 
//         {
//             while (i != 0 && ptrHeap[parent(i)] > ptrHeap[i]) 
//             {
//                 swap(ptrHeap[i], ptrHeap[parent(i)]);
//                 i = parent(i);
//             }
//         }

//         else {
//             min_heapify(i); // Adjust the subtree at i to maintain the min-heap property.
//         }
//     }
// }

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
    if (n <= array)                                         // Check if new size is >= current array size
        return;

    T* newPtrHeap = new T[n];                               // Allocate dynamic memory for a new heap with new size n

    for (int i = 0; i < heap; i++)                          // Copy values from current heap to new heap
        newPtrHeap[i] = ptrHeap[i];

    delete[] ptrHeap;                                       // Deallocate current heap to prevent memory leak
    ptrHeap = newPtrHeap;                                   // Fix the pointer to point to new heap
    array = n;                                              // Set array size to be n
}