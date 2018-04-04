#ifndef binary_tree_2_h
#define binary_tree_2_h
#include <iostream>
#include <stdexcept>
#include "BinaryTreeNode.h"
using namespace std;

template <class T>
//join father and left child
void addNodeL(int i, int j, BinaryTreeNode<T> root[], int length) {
	if (root==NULL||length<=0) 
		throw invalid_argument("Pay attention to the array.");
	if ((i<0||i>=length)||(j<0||j>=length))
		throw invalid_argument("Pay attention to indices.");

    root[i].leftChild=&root[j];
    root[j].father=&root[i];
}

template <class T>
//join father and right child
void addNodeR(int i, int j, BinaryTreeNode<T> root[], int length) {
    if (root==NULL||length<=0)
        throw invalid_argument("Pay attention to the array.");
    if ((i<0||i>=length)||(j<0||j>=length))
        throw invalid_argument("Pay attention to indices.");

    root[i].rightChild=&root[j];
    root[j].father=&root[i];
}

template <class T>
//set the elements of the tree
void setElement(int i, T theElement, BinaryTreeNode<T> root[], int length) {

    if (root==NULL||length<=0)
        throw invalid_argument("Pay attention to the array.");
    if ((i<0||i>=length))
        throw invalid_argument("Pay attention to indices.");

    root[i].element=theElement;
}

#endif
