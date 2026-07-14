#ifndef _PRODUCT_H_
#define _PRODUCT_H_

#include <string>

class Product 
{
	private:
		int _id;
		std::string _description; 
		long _price;
 
	public:
		Product(int id, const std::string& description, long price); 
		// TODO: Copy Constructor
		
		int id(void) const { return _id; }
		std::string description(void) const { return _description; }
		long price(void) const { return _price; }
 };

#endif /*_PRODUCT_H_ */
