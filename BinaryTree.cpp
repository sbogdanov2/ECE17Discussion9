//
// Created by sbogdanov on 11/27/2023.
//

#include "BinaryTree.h"
#include <iostream>

void BinaryTree::insert(BinaryTree::Node *&aNodePtr, BinaryTree::Node *&aNewNodePtr) {
    if (aNodePtr == nullptr) {
        aNodePtr = aNewNodePtr;
    }
    else if (aNewNodePtr -> val < aNodePtr->val) {
        insert(aNodePtr->left, aNewNodePtr);
    }
    else{
        insert(aNodePtr->right, aNewNodePtr);
    }

}

void BinaryTree::deleteNode(int aVal, BinaryTree::Node *&aNodePtr) {
    if (aVal < aNodePtr->val) {
        deleteNode(aVal, aNodePtr->left);

    }
    else if (aVal > aNodePtr->val){
        deleteNode(aVal, aNodePtr->right);
    }
    else { //If the value is found
        makeDeletion(aNodePtr);
    }
}

void BinaryTree::makeDeletion(BinaryTree::Node *&aNodePtr) {
    Node *temp = nullptr;
    if (aNodePtr == nullptr) {
        std::cout << "Cannot remove empty node" << std::endl;
    }
    else if (aNodePtr->right == nullptr) {
        temp = aNodePtr;
        aNodePtr = aNodePtr->left;
        delete temp;
    }
    else if (aNodePtr->left == nullptr) {
        temp = aNodePtr;
        aNodePtr = aNodePtr->right;
        delete temp;
    }
    else {
        temp = aNodePtr->right;
        while (temp->left) {
            temp = temp->left;
        }
        temp->left = aNodePtr->left;
        temp = aNodePtr;
        aNodePtr = temp->right;
        delete temp;
    }
}

BinaryTree::BinaryTree() {
    root = nullptr;
}

void BinaryTree::insertNode(int aVal) {
    Node *newNode = new Node(aVal);
    insert(root, newNode);
}

bool BinaryTree::searchNode(int aVal) {
    Node *currentNode = root;

    while (currentNode) {
        if (currentNode->val == aVal) {
            return true;
        }
        else if (aVal < currentNode->val) {
            currentNode = currentNode->left;
        }
        else {
            currentNode = currentNode->right;
        }
    }
    return false;

}

void BinaryTree::remove(int aVal) {
    deleteNode(aVal, root);

}

BinaryTree::Node::Node(int aval, BinaryTree::Node *aleft, BinaryTree::Node *aright) {
    val = aval;
    left = aleft;
    right = aright;
}
