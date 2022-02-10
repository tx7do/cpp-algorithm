//
// Created by YLB on 2022/2/6.
//

#ifndef _LIONPROJ_CARTESIAN_TREE_H
#define _LIONPROJ_CARTESIAN_TREE_H

#include <iostream>
#include <vector>
#include <queue>
#include <memory>

typedef std::vector<int> IntVector;

static int s_findRightMostCount = 0;
static int s_findLowestNodeCount = 0;

struct Node {
    int value;
    Node *left, *right;
    Node *parent;

    bool operator()(Node *node) {
        return this->value > node->value;
    }

    Node() : value(0), parent(nullptr), left(nullptr), right(nullptr) {}

    Node *findRightMost() {
        auto curr = this;
        while (curr != nullptr) {
            ++s_findRightMostCount;
            if (curr->right == nullptr) return curr;
            curr = curr->right;
        }
        return nullptr;
    }

    Node *findLowestNode(int x) {
        ++s_findLowestNodeCount;
        if (this->value < x) {
            return this;
        } else if (this->parent != nullptr) {
            return this->parent->findLowestNode(x);
        } else {
            return nullptr;
        }
    }

    Node *insertByLowestNode(Node *&last, int val) {
        Node *newNode = new Node;
        newNode->value = val;

        Node *lowestNode = last->findLowestNode(val);

        if (lowestNode == nullptr) {
            newNode->left = this;
            this->parent = newNode;
            last = newNode;
            return newNode;
        } else {
            newNode->left = lowestNode->right;
            lowestNode->right = newNode;
            newNode->parent = lowestNode;
            last = newNode;
            return nullptr;
        }
    }

    Node *insertByRightMost(int val) {
        Node *rightmost = this->findRightMost();
        Node *rightmost_child = nullptr;
        while (rightmost != nullptr && rightmost->value > val) {
            rightmost_child = rightmost;
            rightmost = rightmost->parent;
        }

        std::unique_ptr<Node> new_root_ptr = std::make_unique<Node>();
        new_root_ptr->value = val;

        Node *new_root = new_root_ptr.release();
        if (rightmost == nullptr) {
            if (rightmost_child != nullptr) {
                new_root->left = rightmost_child;
                rightmost_child->parent = new_root;
            }
            return new_root;
        }

        if (rightmost->right == rightmost_child) {
            rightmost->right = new_root;
        } else {
            rightmost->left = new_root;
        }
        new_root->parent = rightmost;
        if (rightmost_child != nullptr) {
            new_root->left = rightmost_child;
            rightmost_child->parent = new_root;
        }
        return this;
    }
};

struct compare {
    bool operator()(Node *left, Node *right) {
        return left->value > right->value;
    }
};

class CartesianTree {
private:
    Node *root, *last;

public:
    explicit CartesianTree() : root(nullptr), last(nullptr) {
    }

    explicit CartesianTree(const IntVector &arr) : root(nullptr), last(nullptr) {
        insertByLowestNodes(arr.begin(), arr.end());
    }

    CartesianTree(const IntVector::const_iterator &begin, const IntVector::const_iterator &end) : root(nullptr),
                                                                                                  last(nullptr) {
        insertByLowestNodes(begin, end);
    }

public:
    Node *getRoot() {
        return this->root;
    }

    Node *insertByRightMosts(const IntVector::const_iterator &begin, const IntVector::const_iterator &end) {
        this->root = nullptr;
        this->last = nullptr;
        for (auto it = begin; it != end; ++it) {
            insertByRightMost(*it);
        }
        return this->root;
    }

    Node *insertByLowestNodes(const IntVector::const_iterator &begin, const IntVector::const_iterator &end) {
        this->root = nullptr;
        this->last = nullptr;
        for (auto it = begin; it != end; ++it) {
            insertByLowestNode(*it);
        }
        return this->root;
    }

    Node *insertByRightMost(int val) {
        Node *new_node = nullptr;
        if (this->root == nullptr) {
            new_node = new Node();
            new_node->value = val;
        } else {
            new_node = this->root->insertByRightMost(val);
        }
        this->root = new_node;
        this->last = new_node;
        return new_node;
    }

    Node *insertByLowestNode(int val) {
#if 1
        Node *new_node = nullptr;
        if (this->root == nullptr) {
            new_node = new Node();
            new_node->value = val;
            this->root = new_node;
            this->last = new_node;
        } else {
            new_node = this->root->insertByLowestNode(this->last, val);
            if (new_node != nullptr) {
                this->root = new_node;
            }
        }
        return new_node;
#else
        Node *new_node = new Node;
        new_node->value = val;
        if(root == nullptr){
            last = new_node;
            root = new_node;
            return new_node;
        }
        Node *z = last->findLowestNode(val);
        if(z == nullptr){
            new_node->left = root;
            root->parent = new_node;
            root = new_node;
            printf("new root: %d\n",this->root->value);
        }
        else{
            new_node->left = z->right;
            z->right = new_node;
            new_node->parent = z;
        }
        last = new_node;
//         printf("%d\n",this->last->value);
        return new_node;
#endif
    }


    void InorderTraversal(IntVector &order_ar) {
        InorderTraversal(order_ar, getRoot());
    }

    void InorderTraversal(IntVector &order_ar, Node *node) {
        // To print inorder traversal of the tree
        if (node == nullptr) {
            return;
        }
        order_ar.push_back(node->value);
        InorderTraversal(order_ar, node->left);

        InorderTraversal(order_ar, node->right);
    }

    void sort(IntVector &sorted_ar) {
        sorted_ar.assign(0, 0);

        std::priority_queue<Node *, std::vector<Node *>, compare> p_queue;
        p_queue.push(root);
        std::cout << "Root Node: " << root->value << std::endl;

        Node *top_node = nullptr;
        while (!p_queue.empty()) {
            top_node = p_queue.top();
            p_queue.pop();
            if (top_node == nullptr) continue;

            sorted_ar.push_back(top_node->value);

            if (top_node->left) {
                p_queue.push(top_node->left);
                std::cout << "Left Node: " << top_node->left->value << std::endl;
            }
            if (top_node->right) {
                p_queue.push(top_node->right);
                std::cout << "Right Node: " << top_node->right->value << std::endl;
            }

            std::cout << "Queue count: " << p_queue.size() << std::endl;
        }
    }
};

template<typename Iter, typename Compare = std::less<>>
void CartesianTreeSort(Iter first, Iter last, Compare cmp = Compare()) {
    CartesianTree tree(first, last);

    IntVector sorted;
    tree.sort(sorted);
    for (auto it1 = first, it2 = sorted.begin(); it1 != last && it2 != sorted.end(); ++it1, ++it2) {
        *it1 = *it2;
    }
}


#endif
