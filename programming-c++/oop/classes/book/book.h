#ifndef _BOOK_H_
#define _BOOK_H_

#include <cstdint>
#include <string>

class Book 
{
private:
    std::string _title;
    std::string _author;
    std::string _isbn;

public:
    // Initializing Constructor
    Book(const std::string& title, const std::string& author, const std::string& isbn);

    // Copy Constructor
    Book(const Book &book) = default;

    // Default destructor
    ~Book() = default;  

    // Getter and Setter Methods
    std::string title() const { return _title; }                // inline method
    void title(const std::string& title) { _title = title; }    // inline method

    std::string author() const;
    void author(const std::string& author);

    std::string isbn() const;
    void isbn(const std::string& isbn);
};

#endif // _BOOK_H_