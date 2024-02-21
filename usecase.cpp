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

    for (int i = 0; i <= len-1; i++)
    {
        if (len-i-1 < window)
        {
            window = len-i-1;
        }
        int count = window;
        for (int j = 0; j <= window-1; j++){
            mq.insert(arr[j]);
            result << mq.min() << ' ';
        }
        while (count > 0)
        {
            mq.extract_min();
            count--;
        }
    }
    result.str();
}


