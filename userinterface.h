#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H

#include <iostream>        
#include <cstdio>          
#include <chrono>          
#include "QueryProcessor.h" 
#include "IndexHandler.h"  
#include "DocumentParser.h" 

//Class definition
class UserInterface
{
private:
    //Private variables
    std::chrono::duration<double> elapsedTrain; 
    IndexHandler ih;                           
    QueryProcessor qp;                         
    DocumentParser dp;                          

public:
    //Public function

    //Function to initiate and handle user interaction
    void initialQuestion(); 
};
#endif
