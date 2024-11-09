#ifndef QUERY_PROCESSOR_H
#define QUERY_PROCESSOR_H

#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <math.h>
#include <sstream>
#include "IndexHandler.h"
#include "porter2_stemmer.h"

// Class definition for QueryProcessor
class QueryProcessor
{
private:
