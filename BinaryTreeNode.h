#ifndef binary_tree_node_h
#define binary_tree_node_h

template <class T>
struct BinaryTreeNode {
	T element;
	BinaryTreeNode<T> *leftChild=NULL;
	BinaryTreeNode<T> *rightChild=NULL;
	BinaryTreeNode<T> *father=NULL;
};
#endif
