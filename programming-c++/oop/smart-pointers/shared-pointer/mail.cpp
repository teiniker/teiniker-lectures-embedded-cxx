#include <iostream>
#include <mail.h>

using namespace std;

Mail::Mail(const string& address) 
    : address_{address} 
{
    cout << "Mail - constructor" << endl;
}
    
Mail::~Mail(void) 
{
    cout << "Mail - destructor" << endl;
}
