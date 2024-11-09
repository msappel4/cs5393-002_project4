#ifndef HASH_H
#define HASH_H
#include <map>
#include <functional>
#include <ostream>

// Template class for a hash table
template <typename Comparable, typename Value>
class Hash
{
private:
