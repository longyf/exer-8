#include <iostream>
#include <stdexcept>
#include "BinaryTree2.h"
using namespace std;

BinaryTreeNode<int> *nextNode(BinaryTreeNode<int> *ptr) {

	if (ptr==NULL) 
		throw invalid_argument("Pay attention to the input BinaryTreeNode *");

    //是叶节点
    if ((ptr->leftChild==NULL)&&(ptr->rightChild==NULL)) {

		//没有父节点
		if (ptr->father==NULL) {
			return NULL;
		}

		//有父节点
        //父节点的左子节点
        if (ptr==ptr->father->leftChild) {
            return ptr->father;
        }

        //父节点的右子节点
        else {
            while ((ptr!=ptr->father->leftChild)&&(ptr->father->father!=NULL)) {
                ptr=ptr->father;
            }
			//表示没找到
            if ((ptr->father->father==NULL)&&(ptr!=ptr->father->leftChild)) {
                return NULL;
            }
            else {
                return ptr->father;
            }
        }
    }

    //不是叶节点
    else {

        //没有右子节点。
        if (ptr->rightChild==NULL) {
            return ptr->father;
        }
        //有右子节点。
        else {
            //右子节点是叶节点
            if ((ptr->rightChild->leftChild==NULL)&&(ptr->rightChild->rightChild==NULL)) {
                return ptr->rightChild;
            }
            //右子节点不是叶节点
            else {
                ptr=ptr->rightChild;
                while(ptr->leftChild!=NULL) {
                    ptr=ptr->leftChild;
                }
                return ptr;
            }
        }

    }
}

int main() {

	//Test1.
	//Construct the binary tree.
	BinaryTreeNode<int> array[9];
	setElement(0,0,array,9);
	setElement(1,1,array,9);
	setElement(2,2,array,9);
	setElement(3,3,array,9);
	setElement(4,4,array,9);
	setElement(5,5,array,9);
	setElement(6,6,array,9);
	setElement(7,7,array,9);
	setElement(8,8,array,9);

	addNodeR(0,1,array,9);
	addNodeR(1,2,array,9);
    addNodeR(2,3,array,9);
    addNodeR(3,4,array,9);
    addNodeR(4,5,array,9);
    addNodeR(5,6,array,9);
    addNodeR(6,7,array,9);
    addNodeR(7,8,array,9);

	//input node.
for (int i=0; i!=9; ++i) {
	if (i<0||i>8) 
		throw invalid_argument("Pay attention to your input.");

	BinaryTreeNode<int> *ptr=&array[i];

	cout<<"The input is "<<ptr->element<<endl;

	BinaryTreeNode<int> *ptr2=nextNode(ptr);
	if (ptr2!=NULL) 
		cout<<"The output is "<<ptr2->element<<endl;
	else
		cout<<"The input is the last node."<<endl;
	cout<<endl;
}

	//Test 2.
	cout<<"Just one node."<<endl;
    BinaryTreeNode<int> array1[1];
    setElement(0,0,array,1);
	BinaryTreeNode<int> *ptr3=nextNode(array1);
    if (ptr3!=NULL)
        cout<<"The output is "<<ptr3->element<<endl;
    else
        cout<<"The input is the last node."<<endl;
    cout<<endl;

	return 0;
}
