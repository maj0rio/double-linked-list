/**
 * @file list_iterator.hpp
 * @author maj0rio
 * @brief header of double link iterator
 * @version 0.1
 * @date 2024-04-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef _LIST_ITERATOR_HPP
#define _LIST_ITERATOR_HPP


#include "list_node.hpp"


template<typename T>
class Iterator {
public:
    explicit Iterator(Node<T>* node);

    Node<T>* node() const;
    T& value() const;

    Iterator& operator++();
    Iterator& operator--();

    bool operator==(const Iterator&) const;
    bool operator!=(const Iterator&) const;

private:
    Node<T>* m_pNode;
};

#endif