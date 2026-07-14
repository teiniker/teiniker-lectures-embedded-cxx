#include "book.h"

using namespace std;

Book::Book(const string& title, const string& author, const string& isbn)
    : _title{title}, _author{author}, _isbn{isbn}
{
}
