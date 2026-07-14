#include <string>
#include <sstream>
#include <book.h>

using namespace std;

// Constructor
Book::Book(const string& isbn, const string& author, const string& title)
    : _isbn(isbn), _author(author), _title(title)
{
}

// Method to convert the object to JSON
string Book::toJson() const
{
    ostringstream json;
    json << "{"
         << "\"isbn\":\"" << _isbn << "\","
         << "\"author\":\"" << _author << "\","
         << "\"title\":\"" << _title << "\""
         << "}";
    return json.str();
}

