#ifndef NODE_LINKLIST_H
#define NODE_LINKLIST_H
#include "tasks.h"



template <typename T>
class node_linklist
{
public :
    node_linklist(const T & data , const int & index) ;
    const T & getData() const ;
    const int & getIndex() const ;
    node_linklist * getNextNode() const ;
    node_linklist * getPrevNode() const ;
    void setData(const T & data) ;
    void setIndex(const T & index) ;
    void setNextNode(node_linklist * nextNode) ;
    void setPrevNode(node_linklist * prevNode) ;
private :
    T m_data ;
    int m_index ;
    node_linklist * m_nextNode ;
    node_linklist * m_prevNode ;
} ;

template <typename T> node_linklist<T>::node_linklist(const T & data , const int & index) : m_data(data) , m_index(index) , m_nextNode(nullptr) , m_prevNode(nullptr) {}

template <typename T> const T & node_linklist<T>::getData() const { return m_data ; }

template <typename T> const int & node_linklist<T>::getIndex() const { return m_index ; }

template <typename T> node_linklist<T> * node_linklist<T>::getNextNode() const { return m_nextNode ; }

template <typename T> node_linklist<T> * node_linklist<T>::getPrevNode() const { return m_prevNode ; }

template <typename T> void node_linklist<T>::setData(const T & data) { m_data = data ; }

template <typename T> void node_linklist<T>::setIndex(const T & index) { m_index = index ; }

template <typename T> void node_linklist<T>::setNextNode(node_linklist<T> * nextNode) { m_nextNode = nextNode ; }

template <typename T> void node_linklist<T>::setPrevNode(node_linklist<T> * prevNode) { m_prevNode = prevNode ; }




#endif // NODE_LINKLIST_H
