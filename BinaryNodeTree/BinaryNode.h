/**
 * @Author: Amirah Abdullah <amirah>
 * @Date:   November 10, 2018
 * @Email:  amirah.ghada@ku.edu
 * @Filename: BinaryNode.h
 * @Last modified by:   amirah
 * @* Description: This is the header file for the node.cpp. This contains the constructor for the node object. This will be used
 by other files in order to clearly see which nodes in the file will allow for you to be able to create the nodes in the tree
 */


//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** A class of nodes for a link-based binary tree.
  Listing 16-2.
  @file BinaryNode.h */

#ifndef _BINARY_NODE
#define _BINARY_NODE


template <typename ItemType>
class BinaryNode {
private:
  ItemType item;                        // Data portion
  BinaryNode<ItemType>* leftChildPtr;   // Pointer to left child
  BinaryNode<ItemType>* rightChildPtr;  // Pointer to right child

public:
  BinaryNode(const ItemType& anItem);

  BinaryNode(const ItemType& anItem, BinaryNode<ItemType>* leftPtr, BinaryNode<ItemType>* rightPtr);

  void setItem(const ItemType& anItem);

  ItemType getItem() const;

  bool isLeaf() const;

  BinaryNode<ItemType>* getLeftChildPtr() const;

  BinaryNode<ItemType>* getRightChildPtr() const;

  void setLeftChildPtr(BinaryNode<ItemType>* leftPtr);

  void setRightChildPtr(BinaryNode<ItemType>* rightPtr);
};  // end BinaryNode

// #include "BinaryNode.cpp"
#endif
