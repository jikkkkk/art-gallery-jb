#ifndef COLLECTIONISFULLEXCEPTION_H
#define COLLECTIONISFULLEXCEPTION_H
#include <exception>

//exception class to throw error when the collection is full
class CollectionIsFullException : public exception //inherits code from exception class standard class in c++
{
    public:
        virtual const char* what() const throw(){
            return "EXCEPTION: This Collection is full. You cannot add any more exhibits.";
        }
};

#endif // COLLECTIONISFULLEXCEPTION_H

