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
        Book(const std::string& title, const std::string& author, const std::string& isbn);

        ~Book() = default;  // Default destructor

        // Getter and Setter Methods
        std::string title() const { return _title; }                // inline method
        void title(const std::string& title) { _title = title; }    // inline method

        std::string author() const { return _author; }                // inline method
        void author(const std::string& author) { _author = author; }  // inline method

        std::string isbn() const { return _isbn; }                  // inline method
        void isbn(const std::string& isbn) { _isbn = isbn; }        // inline method
};

#endif // _BOOK_H_