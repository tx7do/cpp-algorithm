//
// Created by YLB on 2022/2/11.
//

#ifndef CPP_ALGORITHM_TRIESEARCH_H
#define CPP_ALGORITHM_TRIESEARCH_H

#include <bits/stdc++.h>

class Trie {
public:
    static const int ALPHABET_SIZE = 26;

    struct Node {
        struct Node *children[ALPHABET_SIZE];
        bool isEndOfWord;

        ~Node() {
            for (auto &i: this->children) {
                if (i != nullptr) {
                    delete i;
                    i = nullptr;
                }
            }
        }
    };

    Trie() {
        root = createNode();
    }

    ~Trie() {
        delete root;
    }

public:
    void insert(const std::string &key) {
        auto *pCrawl = this->root;

        for (char i: key) {
            int index = i - 'a';
            if (!pCrawl->children[index]) {
                pCrawl->children[index] = createNode();
            }

            pCrawl = pCrawl->children[index];
        }

        pCrawl->isEndOfWord = true;
    }

    bool search(const std::string &key) {
        auto *pCrawl = this->root;

        for (char i: key) {
            int index = i - 'a';
            if (!pCrawl->children[index]) {
                return false;
            }
            pCrawl = pCrawl->children[index];
        }

        return (pCrawl->isEndOfWord);
    }

protected:
    static Node *createNode() {
        auto *pNode = new Node;

        pNode->isEndOfWord = false;

        for (auto &i: pNode->children) {
            i = nullptr;
        }

        return pNode;
    }

private:
    Node *root;
};

bool TrieSearch(const std::vector<std::string> &vec, const std::string &target) {
    if (vec.empty())return -1;
    Trie trie;
    for (auto &i: vec) {
        trie.insert(i);
    }
    return trie.search(target);
}

#endif //CPP_ALGORITHM_TRIESEARCH_H
