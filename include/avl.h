#ifndef AVL_H
#define AVL_H

#include <iostream>
#include <string>
using namespace std;

struct PatientRecord {
    int id;
    string name;
    int priority; // smaller value = higher priority

    PatientRecord(int i = 0, string n = "", int p = 0)
        : id(i), name(n), priority(p) {}
};

class AVLNode {
public:
    PatientRecord data;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(PatientRecord p);
};

class AVLTree {
private:
    AVLNode* root;

    int height(AVLNode* node);
    int getBalance(AVLNode* node);
    AVLNode* rightRotate(AVLNode* y);
    AVLNode* leftRotate(AVLNode* x);
    AVLNode* insert(AVLNode* node, PatientRecord record);
    AVLNode* minValueNode(AVLNode* node);
    AVLNode* remove(AVLNode* node, int id);
    void inorder(AVLNode* node);
    void destroy(AVLNode* node);
    AVLNode* search(AVLNode* node, int id);

public:
    AVLTree();
    ~AVLTree();

    void insert(PatientRecord record);
    void remove(int id);
    void inorder();
    PatientRecord* search(int id);
};

#endif
