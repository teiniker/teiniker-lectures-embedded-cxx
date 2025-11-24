#include "book.h"

using namespace std;

Book::Book(const string& title, const string& author, const string& isbn)
    : _title{title}, _author{author}, _isbn{isbn}
{
}

string Book::author() const 
{ 
    return _author; 
}                
void Book::author(const string& author) 
{ 
    _author = author; 
}  

string Book::isbn() const 
{ 
    return _isbn; 
}                  
void Book::isbn(const string& isbn) 
{ 
    _isbn = isbn; 
}        
