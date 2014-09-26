/* 
 * File:   main.cpp
 * Author: zeus
 *
 * Created on September 25, 2014, 6:40 PM
 */

#include <iostream>

using namespace std;
long count = 0;
int towerEmpty(int t[], int size) {
    for (int i = 0; i < size; i++) {
        if (t[i] != 0) return 0;
    }
    return 1;
}

int moveTop(int tower1[], int tower2[], int size) {
    count++;
    if (tower2[size - 1] != 0) return -1;
    int i,j;
    for (i = size - 1; i >= 0; i--) {
        if (tower1[i] > 0) {
            for (j = size -1; j >= 0 ; j--) {
                if (tower2[j] > 0) {
                    tower2[j+1] = tower1[i];
                    tower1[i] = 0;
                    return 1;
                }
            }
            tower2[0] = tower1[i];
            tower1[i] = 0;
            return 1;
        }
    }
    return -1;
}

void moveStack(int from[], int to[], int middle[], int size, int height) {
    if (height == 2) {
        moveTop(from, middle, size);
        moveTop(from, to, size);
        moveTop(middle, to, size);
    } else {
        moveStack(from, middle, to, size, height-1);
        moveTop(from, to, size);
        moveStack(middle, to, from, size, height-1);
    }
}

int main(int argc, char** argv) {
    //srand(time(NULL));
    const int SIZE = 32;
    
    int t1[SIZE] = {}, t2[SIZE] = {}, t3[SIZE] = {};
    
    int i;
    
    for (i = SIZE - 1; i >= 0; i--) {
        t1[i] = SIZE - i;
    }
    
    
    for (i = SIZE - 1; i >= 0; i--) {
        cout << i << " > " << t1[i] << "|" << t2[i] << "|" << t3[i] << endl;
    }
    
    moveStack(t1, t3, t2, SIZE, SIZE);
    
    cout << "===" << endl;
    
    for (i = SIZE - 1; i >= 0; i--) {
        cout << i << " > " << t1[i] << "|" << t2[i] << "|" << t3[i] << endl;
    }
    
    cout << count/60/60/24/365 << " years (" << count << " iterations) " << " done" << endl;
    return 0;
}

