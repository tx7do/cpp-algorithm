//
// Created by YLB on 2022/2/11.
//

#ifndef CPP_ALGORITHM_TREAPSEARCH_H
#define CPP_ALGORITHM_TREAPSEARCH_H

#include <bits/stdc++.h>

class Treap {
    struct Node {
        int key, priority;
        Node *left, *right;

        Node *rightRotate() {
            Node *x = this->left, *T2 = x->right;
            x->right = this;
            this->left = T2;
            return x;
        }

        Node *leftRotate() {
            Node *y = this->right, *T2 = y->left;
            y->left = this;
            this->right = T2;
            return y;
        }

        Node *insert(Node *root, int _key) {
            if (!root) {
                return newNode(_key);
            }

            if (_key <= root->key) {
                root->left = insert(root->left, _key);

                if (root->left->priority > root->priority) {
                    root = root->rightRotate();
                }
            } else {
                root->right = insert(root->right, _key);

                if (root->right->priority > root->priority) {
                    root = root->leftRotate();
                }
            }
            return root;
        }

        Node *search(int _key) {
            if (this->key == _key)
                return this;

            if (this->key < _key) {
                if (this->right == nullptr) return nullptr;
                return this->right->search(_key);
            }

            if (this->left == nullptr) return nullptr;
            else return this->left->search(_key);
        }

        void inorder(std::vector<int> &sorted) const {
            if (this->left) this->left->inorder(sorted);
            sorted.push_back(this->key);
            if (this->right) this->right->inorder(sorted);
        }

        static Node *newNode(int key) {
            Node *temp = new Node;
            temp->key = key;
            temp->priority = rand() % 100;
            temp->left = temp->right = nullptr;
            return temp;
        }

    };

    Node *root;

public:
    Treap() {
        root = nullptr;
        srand(time(nullptr));
    }

    ~Treap() {}

    void insert(int key) {
        if (root == nullptr) {
            root = Node::newNode(key);
        } else {
            root = root->insert(root, key);
        }
    }

    bool search(int _key) {
        return root->search(_key) != nullptr;
    }

    void sort(std::vector<int> &sorted) const {
        root->inorder(sorted);
    }
};

bool TreapSearch(const std::vector<int> &vec, const int &target) {
    if (vec.empty())return -1;
    Treap treap;
    for (auto &i: vec) {
        treap.insert(i);
    }
    return treap.search(target);
}

#endif //CPP_ALGORITHM_TREAPSEARCH_H
