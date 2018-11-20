//
// Created by Administrator on 2018/11/20.
//

#ifndef SUMOVERSTL_NAMESPACE_H
#define SUMOVERSTL_NAMESPACE_H
namespace sme {
    template<typename TYPE>
    struct Node;

    template<typename value_type, int init_size = 0>
    class list;

    template<typename item>
    item sum(item begin, item end);
}
#endif //SUMOVERSTL_NAMESPACE_H
