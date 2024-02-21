//========================================================
// William Nguyen, Cheryl Nguyen, Phan Anh Le
// minqueue.h
// February 2024
// This file contains the sliding window's implementation
//========================================================

#include "minqueue.h"
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
using namespace std;

//========================================================
// sliding_window
// Find minimum element in the window sliding through the array
// Parameter: T arr[] - targeted array to have window slides through
//            int len - length of the array
//            int window - size of the sliding window
// Return value: a string contains the minimum values of 
// each windows in the array
// Pre-condition: Exists array of size len
// Post-condition: Return a string contains the minimum 
// values of each windows in the array
//========================================================
template <class T>
string sliding_window(T arr[], int len, int window)
{
    MinQueue<T> mq;                                         // MinQueue object to hold the values in each window in the array
    stringstream result;                                    // A string to hold the minimum values for each windows in the array

    if (len == 0){                                          // If array is empty then return empty string
        return result.str();
    }
    
    for (int i = 0; i <= len-window; i++)                   // For loop to slide the window by 1
    {
        for (int j = i; j <= i+window-1; j++)               // For loop to get the elements in the window
        {
            mq.insert(arr[j]);                              // Insert the elements within the window into MinQueue
        }

        if (i != len-window)                                // If statement to avoid whitespace at the end of string
        {
            result << mq.min() << ' ';                      // Get the window's minimum value
        }
        else
        {
            result << mq.min();
        }

        int count = window-1; 
        while (count >= 0)                                  // Empty the MinQueue object holding the window's elements for the window to 'slide'
        {
            mq.extract_min();
            count--;
        }
    }
    return result.str();
}


