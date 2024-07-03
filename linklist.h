#ifndef LINKLIST_H
#define LINKLIST_H

#include "node_linklist.h"


template <typename T>
class Linklist
{
public :
    Linklist() ;
    const node_linklist<T> * getHeadNode() const ;
    const node_linklist<T> * getTailNode() const ;
    const int & getSize() const ;
    void pushBack(const T & data) ;
    void popBack() ;
    node_linklist<T> * operator[] (int index) ;
    const node_linklist<T> * operator[] (int index) const ;
    ~ Linklist () ;
private :
    node_linklist<T> * m_headNode ;
    node_linklist<T> * m_tailNode ;
    int m_size ;
} ;

template <typename T>
Linklist<T>::Linklist() : m_headNode(nullptr), m_tailNode(nullptr) , m_size(0) {}

template <typename T>
const node_linklist<T> * Linklist<T>::getHeadNode() const { return m_headNode; }

template <typename T>
const node_linklist<T> * Linklist<T>::getTailNode() const { return m_tailNode; }

template <typename T>
const int & Linklist<T>::getSize() const { return m_size; }

template <typename T>
void Linklist<T>::pushBack(const T & data) {
    node_linklist<T> * newNode = new node_linklist<T>(data , m_size) ;
    if (m_size) {
        newNode->setPrevNode(m_tailNode) ;
        m_tailNode->setNextNode(newNode) ;
    } else {
        m_headNode = newNode ;
    }
    m_tailNode = newNode ;
    m_size++ ;
}

template <typename T>
void Linklist<T>::popBack() {
    node_linklist<T> * node = m_tailNode ;
    if (m_size) {
        m_tailNode = m_tailNode->getPrevNode() ;
        if (m_tailNode) m_tailNode->setNextNode(nullptr) ;
        else m_headNode = nullptr ;
    }
    delete node ;
    m_size -- ;
}

template <typename T>
node_linklist<T> * Linklist<T>::operator[] (int index) {
    if(index >= m_size || m_size == 0 || index < 0) return nullptr ;
    else {
        node_linklist<T> * node = m_headNode ;
        while (node->getIndex() != index) node = node->getNextNode() ;
        return node ;
    }
}

template <typename T>
const node_linklist<T> * Linklist<T>::operator[] (int index) const {
    if(index >= m_size ||  m_size == 0 || index < 0) return nullptr ;
    else {
        node_linklist<T> * node = m_headNode ;
        while (node->getIndex() != index) node = node->getNextNode() ;
        return node ;
    }
}

template <typename T>
Linklist<T>::~Linklist() {
    while (m_size > 0) popBack() ;
}

#endif // LINKLIST_H
