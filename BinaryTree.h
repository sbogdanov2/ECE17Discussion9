//
// Created by sbogdanov on 11/27/2023.
//

#ifndef DISCUSSION9_BINARYTREE_H
#define DISCUSSION9_BINARYTREE_H
#include <iostream>
using namespace std;

class BinaryTree {
private:
    struct Node {
        int val;
        Node *left;
        Node *right;
        Node(int aVal, Node *aleft = nullptr, Node *aright = nullptr);
    };
    Node *root;
private:
    void insert(Node* &aNodePtr, Node* &aNewNodePtr);
    void deleteNode(int aVal, Node* &aNodePtr);
    void makeDeletion(Node* &aNodePtr);
public:
    BinaryTree();
    void insertNode(int aVal);
    bool searchNode(int aVal);
    void remove(int aVal);

    void displayInOrder(Node* aNodePtr){
        if (aNodePtr) {
            displayInOrder(aNodePtr->left);
            std::cout << aNodePtr->val << " ";
            displayInOrder(aNodePtr->right);
        }
    }

    void printTree(){
        displayInOrder(root);
        std::cout << std::endl;
    };
};


#endif //DISCUSSION9_BINARYTREE_H
