//
// Created by 19210 on 2025/1/31.
//

#ifndef SKIPLIST_SKIPLIST_H
#define SKIPLIST_SKIPLIST_H
#include "Node.h"
#include <stack>
#include <cstdlib>
#include <ctime>
#include <utility>
#include <cstdio>

template<class keyType, class valueType>
class SkipList {
public:
    static const int MAX_LEVEL;
private:
    int level;//层数
    Node<keyType, valueType>* head;
public:
    SkipList() {
        level = 0;
        head = new Node<keyType, valueType>(0, 0, MAX_LEVEL);
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
    }
    ~SkipList() {
        std::stack<Node<keyType, valueType>* > st;
        Node<keyType, valueType>* p = head->next[0];
        while (p != nullptr) {
            st.push(p);
            p = p->next[0];
        }
        while (!st.empty()) {
            p = st.top();
            st.pop();
            delete p;
        }
        delete head;
    }

    std::pair<bool, valueType> search(keyType key) {
        Node<keyType, valueType>* p = head, *q = nullptr;
        for (int i = level - 1; i >= 0; --i) {
            q = p->next[i];
            while (q != nullptr && q->key < key) {
                p = q;
                q = p->next[i];
            }
            if (q != nullptr && q->key == key) {
                return {true, q->value};
            }
        }
        return {false, 0};
    }

    bool insert(keyType key, valueType value) {
        Node<keyType, valueType>* p = head, *q = nullptr;
        Node<keyType, valueType>* update[MAX_LEVEL];
        for (int i = 0; i < MAX_LEVEL; ++i) {
            update[i] = nullptr;
        }
        for (int i = level - 1; i >= 0; --i) {
            q = p->next[i];
            while (q != nullptr && q->key < key) {
                p = q;
                q = p->next[i];
            }
            update[i] = p;
        }
        if (q != nullptr && q->key == key) {
            q->value = value;
            return true;
        }

        int randomLevel = generateRandomLevel();
        if (randomLevel > level) {
            for (int i = level; i < randomLevel; ++i) {
                update[i] = head;
            }
            level = randomLevel;
        }

        q = new Node<keyType, valueType>(key, value, randomLevel);
        for (int i = randomLevel - 1; i >= 0; --i) {
            q->next[i] = update[i]->next[i];
            update[i]->next[i] = q;
        }
        return true;
    }
    //从最高层开始逐层打印
    void print()
    {
        Node<keyType, valueType> *q;
        for(int i = level - 1; i >= 0; --i) {
            q = head->next[i];
            printf("level %d:\n", i + 1);
            while(q) {
                printf("key:%d val:%d\t", q->key, q->value);
                q = q->next[i];
            }
            printf("\n");
        }
    }
private:
    int generateRandomLevel() {
        int res = 1;
        while (std::rand() % 2) {
            ++res;
        }
        return std::min(res, MAX_LEVEL);
    }
};

template<class keyType, class valueType>
const int SkipList<keyType, valueType>::MAX_LEVEL = 5;

#endif //SKIPLIST_SKIPLIST_H
