//========================================================
// William Nguyen, Cheryl Nguyen, Phan Anh Le
// minqueue.h
// February 2024
// This file contains examples to test sliding_window's accuracy.  
//========================================================

#include "usecase.cpp"

using namespace std;

int main(){
    int num[8] = {1,2,3,4,5,6,-1,-2};
    string window_result = sliding_window(num, 8, 4);
    if (window_result != "1 2 3 -1 -2")
    {
        cout << "Incorrect sliding window result. Expected 1 2 3 -1 -2 but got : " << window_result << endl;
    }
    window_result = sliding_window(num, 8, 8);
    if (window_result != "-2")
    {
        cout << "Incorrect sliding window result. Expected -2 but got : " << window_result << endl;
    }
    window_result = sliding_window(num, 1, 1);
    if (window_result != "1")
    {
        cout << "Incorrect sliding window result. Expected 1 but got : " << window_result << endl;
    }

    cout << "Testing completed" << endl;
    return 0;
}