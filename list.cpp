//
// Created by Administrator on 2018/11/20.
//

#include "list.h"

template<typename value_type, int init_size>
sme::Node<value_type> *sme::list<value_type, init_size>::__get(int num) {
    sme::Node<value_type> *pointer = this->__begin_node;
    while (num--) {
        pointer = pointer->__next__;
    }
    return pointer;
}

template<typename value_type, int init_size>
sme::list<value_type, init_size>::list() :__begin_node(new sme::Node<value_type>()) {}

template<typename value_type, int init_size>
int sme::list<value_type, init_size>::size() const {
    sme::Node<value_type> *pointer = __begin_node->__next__;
    int iter = 0;
    while (pointer)
        iter++, pointer = pointer->__next__;
    return iter;
}

template<typename value_type, int init_size>
value_type &sme::list<value_type, init_size>::begin() const { return __begin_node->__next__->__value__; }

template<typename value_type, int init_size>
value_type &sme::list<value_type, init_size>::end() const {
    sme::Node<value_type> *pointer = __begin_node->__next__;
    while (pointer->__next__)
        pointer = pointer->__next__;
    return pointer->__value__;
}

template<typename value_type, int init_size>
void sme::list<value_type, init_size>::add_begin(const value_type &value) {
    __begin_node->__value__ = value;
    auto *ne = new Node<value_type>(value);
    ne->__next__ = __begin_node;
    __begin_node = ne;
}

template<typename value_type, int init_size>
void sme::list<value_type, init_size>::add_end(const value_type &value) {
    sme::Node<value_type> *pointer = __begin_node;
    while (pointer->__next__)
        pointer = pointer->__next__;
    pointer->__next__ = new Node<value_type>(value);
}

template<typename value_type, int init_size>
template<typename function>
void sme::list<value_type, init_size>::map(function __func) {
    sme::Node<value_type> *pointer = __begin_node->__next__;
    while (pointer) {
        __func(pointer->__value__);
        pointer = pointer->__next__;
    }
}

template<typename value_type, int init_size>
value_type &sme::list<value_type, init_size>::operator[](int t) const {
    return __get(t);
}

template<typename value_type, int init_size>
sme::list<value_type, init_size>::list(const sme::list<value_type> &list1) :__begin_node(new Node<value_type>()) {
    sme::Node<value_type> *pointer = list1.__begin_node->__next__, *thisPointer = __begin_node;
    while (pointer) {
        thisPointer->__next__ = new Node<value_type>(pointer->__value__);
        pointer = pointer->__next__;
        thisPointer = thisPointer->__next__;
    }
}

template<typename value_type, int init_size>
void sme::list<value_type, init_size>::insert(int pos, const value_type &value) {
    sme::Node<value_type> *pointer = __begin_node->__next__;
    while (pos--)
        pointer = pointer->__next__;
    auto *newNode = new sme::Node<value_type>(value);
    newNode->__next__ = pointer->__next__;
    pointer->__next__ = newNode;
}

template<typename value_type, int init_size>
void sme::list<value_type, init_size>::delete_begin() {
    auto node = __begin_node;
    __begin_node = __begin_node->__next__;
    delete node;
}

template<typename value_type, int init_size>
void sme::list<value_type, init_size>::delete_end() {
    if (!__begin_node->__next__)
        return;
    auto pointer = __begin_node;
    while (pointer->__next__->__next__) {
        pointer = pointer->__next__;
    }
    delete pointer->__next__;
    pointer->__next__ = nullptr;
}

template<typename value_type, int init_size>
void sme::list<value_type, init_size>::deleteAt(int pos) {
    sme::Node<value_type> *pointer = __begin_node->__next__, *before = __begin_node;
    --pos;
    while (pos--) {
        pointer = pointer->__next__;
        before = before->__next__;
    }
    before->__next__ = pointer->__next__;
    delete pointer;
}

template<typename value_type, int init_size>
template<typename function>
void sme::list<value_type, init_size>::filter(function __func) {
    sme::Node<value_type> *before = __begin_node, *pot = __begin_node->__next__;
    while (pot) {
        if (!__func(pot->__value__)) {
            before->__next__ = pot->__next__;
            delete pot;
            pot = before->__next__;
        } else {
            before = before->__next__;
            pot = pot->__next__;
        }
    }
}

template<typename value_type, int init_size>
template<typename function>
void sme::list<value_type, init_size>::ranger(function __func, int end) {
    sme::Node<value_type> *pot = __begin_node->__next__;
    while (pot && end--) {
        __func(pot->__value__);
        pot = pot->__next__;
    }
}

template<typename value_type, int init_size>
template<typename function>
void sme::list<value_type, init_size>::ranger(function __func, int begin, int end) {
    sme::Node<value_type> *pot = __begin_node->__next__;
    while (begin-- && end-- && pot)
        pot = pot->__next__;
    while (pot && end--) {
        __func(pot->__value__);
        pot = pot->__next__;
    }
}

template<typename value_type, int init_size>
template<typename function>
void sme::list<value_type, init_size>::ranger(function __func, int begin, int end, int step) {
    sme::Node<value_type> *pot = __begin_node->__next__;
    while (begin-- && end--)
        pot = pot->__next__;
    while (pot && ((end) > 0)) {
        __func(pot->__value__);
        for (int i = 0; i < step && pot; ++i)
            pot = pot->__next__, end--;
    }
}

