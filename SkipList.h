//
// Created by 19210 on 2025/1/31.
//

#ifndef SKIPLIST_SKIPLIST_H
#define SKIPLIST_SKIPLIST_H
#include "Node.h"
#include <stack>

template<class keyType, class valueType>
class SkipList {
public:
    static const int MAX_LEVEL = 5;
private:
    int level;//层数
    Node<keyType, valueType>* head;
public:
    SkipList() {
        head = new Node<keyType, valueType>(0, 0, MAX_LEVEL);
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

};

#endif //SKIPLIST_SKIPLIST_H
