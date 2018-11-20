//
// Created by sumover on 2018/11/20.
//

#ifndef SUMOVERSTL_LIST_H
#define SUMOVERSTL_LIST_H

#include "namespace.h"
template<typename TYPE>
struct sme::Node {
    TYPE __value__;
    Node *__next__;

    explicit Node(const TYPE &type) : __value__(type), __next__(nullptr) {}

    Node() : __next__(nullptr) {}

    Node(const sme::Node<TYPE> &node) : __value__(node.__value__), __next__(node.__next__) {}

    Node &operator=(const Node<TYPE> &node);
};

template<typename value_type, int init_size>
class sme::list {
private:
    sme::Node<value_type> *__begin_node;

    sme::Node<value_type> *__get(int num);

public:
    list();

    explicit list(const list<value_type> &list1);

    int size() const;

    value_type &begin() const;

    value_type &end() const;

    void add_begin(const value_type &value);

    void add_end(const value_type &value);

    void insert(int pos, const value_type &value);

    void delete_begin();

    void delete_end();

    void deleteAt(int pos);


    template<typename function>
    void map(function __func);

    template<typename function>
    void filter(function __func);

    template<typename function>
    void ranger(function __func, int end);

    template<typename function>
    void ranger(function __func, int begin, int end);

    template<typename function>
    void ranger(function __func, int begin, int end, int step);

    value_type &operator[](int t) const;
};
#endif //SUMOVERSTL_LIST_H
