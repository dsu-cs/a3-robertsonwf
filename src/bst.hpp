#pragma once

// include this library to use NULL, otherwise use nullptr instead
#include <cstddef>
#include <iostream>
#include "node.hpp"

template<class T>
class BST{
public:
    // Constructor for the BST class, creates an empty tree
    BST(void);
    // Destructor for the BST class, destroys the tree
    ~BST(void);
    // Inserts data into the tree
    // param: The data to be inserted into the tree
    void insert(T);
    // Removes data from the tree
    // param: The data to be removed from the tree
    void remove(T);
    // Performs an inorder traversal
    // returns: pointer to a vector containing the tree traversal
    std::vector<T> *inorder(void);
    // Performs an postorder traversal
    // returns: pointer to a vector containing the tree traversal
    std::vector<T> *postorder(void);
    // Performs an preorder traversal
    // returns: pointer to a vector containing the tree traversal
    std::vector<T> *preorder(void);
    // Searches the tree for a given value
    // param: the data to search for
    // returns: a pointer to the node containing the data or NULL if the data
    //          was not found
    Node<T> *search(T);
    // Gets the current number of nodes in the tree
    // returns: the number of nodes in the tree
    int get_size(void);
private:
    // the root node of the tree
    Node<T> *root;
    // the number of nodes in the tree
    int node_count;

    Node<T>* insert_helper(Node<T>*, T);
    Node<T>* search_helper(T, Node<T>*);
 

};

template<class T>
BST<T>::BST()
{
    root = NULL;
    node_count = 0;
}

template<class T>
BST<T>::~BST()
{
    root = NULL;
    while(root != NULL)
    {
        remove(root->get_data());
    }
}

template<class T>
 std::vector<T> * BST<T>::inorder()
{
    std::vector<T> *vec = new std::vector<T>;

    return vec;
}


template<class T>
 std::vector<T> * BST<T>::preorder()
{
    std::vector<T> *vec = new std::vector<T>;
    return vec;
}


template<class T>
 std::vector<T> * BST<T>::postorder()
{
    std::vector<T> *vec = new std::vector<T>;

    return vec;
}

//insert function that calls insert_helper function
template<class T>
void BST<T>::insert(T new_data)
{
    root = insert_helper(root, new_data);
}


//insert_helper function for recursive inserting
template<class T>
Node<T>* BST<T>::insert_helper(Node<T> *root, T data)
{
    if(root == NULL)
    {
        Node<T> *tmp = new Node<T>;
        tmp->set_data(data);
        tmp->set_left(NULL);
        tmp->set_right(NULL);
        node_count++;
        return tmp;
    }
    else
    {
        if(data < root->get_data())
        {
           root->set_left(insert_helper(root->get_left(), data));
        }
        else
        {
            root->set_right(insert_helper(root->get_right(), data));
        }
        
    }
   return root;
}

template<class T>
Node<T> *BST<T>::search(T val)
{
    return search_helper(val, root);
}

template<class T>
Node<T>* BST<T>::search_helper(T key, Node<T> *currNode)
{
    
    if(currNode == NULL)
    {
        return currNode;
    }
    else if(key < currNode->get_data())
    {
        return search_helper(key, currNode->get_left());
    }
    else if(key > currNode->get_data())
    {
        return search_helper(key, currNode->get_right());
    
    }
    return currNode;
}


template<class T>
void BST<T>::remove(T val)
{

}



template<class T>
int BST<T>::get_size()
{
    return node_count;
}