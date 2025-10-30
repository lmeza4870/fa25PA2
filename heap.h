//
// Created by Manju Muralidharan on 10/19/25.
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

struct MinHeap {
    int data[64];
    int size;

    MinHeap() { size = 0; }

    //helper method
    int parent(int i) { return (i - 1) / 2; }   //I looked this up and it helped a lot
    int left(int i)  { return 2*i + 1; }        //left child helper
    int right(int i) { return 2*i + 2; }        //right child helper

    void push(int idx, int weightArr[]) {
        if (size >= 64) {
            cout << "Heap overflow" << endl;
            return;
        }

        data[size] = idx;   //insert new element
        upheap(size, weightArr);    //call upheap to reorder
        size++;
    }

    int pop(int weightArr[]) {
        if (size == 0) {
            return 0;
        }

        int minIdx = data[0];        //root element
        data[0] = data[size - 1];   //move last position to root
        size--;

        if (size > 0) {
            downheap(0, weightArr);     //call on downheap to reorder
        }
        return minIdx;
    }

    void upheap(int pos, int weightArr[]) {
        int i = pos;
        while (i > 0) {
            int p = parent(i);
            if (weightArr[data[i]] < weightArr[data[p]]) {
                int temp = data[i];     //swap the child and parent
                data[i] = data[p];
                data[p] = temp;
                i = p;
            } else {
                break;  //heap order is good
            }
        }
    }

    void downheap(int i, int weightArr[]) {     //compare and move down by weight
        while (left(i) < size) {    //while at least one child exists
            int lc = left(i);
            int rc = right(i);

            int smallestChild = lc;     //assume left child is smaller
            if (rc < size) {
                if (weightArr[data[rc]] < weightArr[data[lc]]) {    //find the smallest child
                    smallestChild = rc;
                }
            }

            if (weightArr[data[i]] <= weightArr[data[smallestChild]]) {     //if parent already smaller
                break;
            }

            //swap places
            int tmp = data[i];
            data[i] = data[smallestChild];
            data[smallestChild] = tmp;
            i = smallestChild;
        }
    }
};

#endif