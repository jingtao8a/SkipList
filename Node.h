//
// Created by 19210 on 2025/1/31.
//

#ifndef SKIPLIST_NODE_H
#define SKIPLIST_NODE_H

template<class keyType, class valueType>
struct Node {
    keyType key;
    valueType value;
    Node** next;
    int n;
    Node() {}
    Node(keyType key, keyType value, int n) {
        this->key = key;
        this->value = value;
        this->next = new Node*[n];
        for (int i = 0; i < n; ++i) {
            this->next[i] = nullptr;
        }
        this->n = n;
    }
    Node(const Node& node)=delete;
    Node(Node&& node)=delete;
    void operator=(const Node& node)=delete;
    void operator=(Node&& node)=delete;

    ~Node() {
        if (this->next != nullptr) {
            delete this->next;
        }
    }
};


#endif //SKIPLIST_NODE_H
