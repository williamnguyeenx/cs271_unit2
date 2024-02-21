#include "minqueue.h"
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
using namespace std;

template <class T>
string sliding_window(T arr[], int len, int window)
{
    MinQueue<T> mq;
    stringstream result;

    if (len == 0){
        return result.str();
    }
    
    for (int i = 0; i <= len-window; i++)
    {
        for (int j = i; j <= i+window-1; j++)
        {
            mq.insert(arr[j]);
        }

        if (i != len-window)
        {
            result << mq.min() << ' ';
        }
        else
        {
            result << mq.min();
        }

        int count = window-1;
        while (count >= 0)
        {
            mq.extract_min();
            count--;
        }
    }
    return result.str();
}


