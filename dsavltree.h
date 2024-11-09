#ifndef DSAVL_TREE_H
#define DSAVL_TREE_H
#define DEBUG
#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <map>

// Template class for a node in an AVL tree
template <typename Comparable, typename Value>
class DSAvlTree
