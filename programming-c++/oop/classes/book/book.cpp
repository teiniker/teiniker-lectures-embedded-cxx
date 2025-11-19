#include "book.h"

Book::Book(const std::string& title, const std::string& author, const std::string& isbn)
    : _title{title}, _author{author}, _isbn{isbn}
{
}

std::string Book::author() const 
{ 
    return _author; 
}                
void Book::author(const std::string& author) 
{ 
    _author = author; 
}  

std::string Book::isbn() const 
{ 
    return _isbn; 
}                  
void Book::isbn(const std::string& isbn) 
{ 
    _isbn = isbn; 
}        
