/**
 * @file list_iterator.cpp
 * @author maj0rio
 * @brief implementation of double link iterator
 * @version 0.1
 * @date 2024-04-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef _LIST_ITERATOR_CPP
#define _LIST_ITERATOR_CPP


#include <stdexcept>

#include "list.hpp"
#include "list_node.hpp"


template<typename T>
List<T>::Iterator::~Iterator() {
    m_pNode = nullptr;
    m_List = nullptr;
}

template<typename T>
List<T>::Iterator::Iterator(const Iterator& other) {
    m_pNode = other.m_pNode;
    m_List = other.m_List;
}

template<typename T>
typename List<T>::Iterator& List<T>::Iterator::operator=(const Iterator& rhs) {
    if (this != &rhs) {
        this->m_pNode = rhs.m_pNode;
        this->m_List = rhs.m_List;
    }
    return *this;
}

template<typename T>
typename List<T>::Iterator& List<T>::Iterator::operator++() {
    if (m_pNode == nullptr)
        throw std::runtime_error("Iterator does not point to a valid node");
    else
        m_pNode = m_pNode->next;

    return *this;
}

template<typename T>
typename List<T>::Iterator& List<T>::Iterator::operator--() {
    if (m_pNode == nullptr)
            m_pNode = m_List->tail_;
    else 
        m_pNode = m_pNode->prev;
    
    return *this;
}

template<typename T>
Node<T>* List<T>::Iterator::operator->() const {
    if (m_pNode == nullptr)
        throw std::runtime_error("you cannot unpack iterator .end()");
    
    return m_pNode;
}

template<typename T>
T& List<T>::Iterator::operator*() const {
    if (m_pNode == nullptr)
        throw std::runtime_error("you cannot unpack iterator .end()");
    
    return m_pNode->data;
}

template<typename T>
bool List<T>::Iterator::operator==(const Iterator &other) const {
    return other.m_pNode == m_pNode && m_List == other.m_List;
}

template<typename T>
bool List<T>::Iterator::operator!=(const Iterator &other) const {
    return !operator==(other);
}

#endif