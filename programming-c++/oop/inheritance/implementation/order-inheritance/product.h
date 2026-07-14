#ifndef _PRODUCT_H_
#define _PRODUCT_H_

#include <string>
#include "entity.h"


class Product : public Entity
{
	private:
		std::string _description; 
		long _price;
 
	public:
		Product(int id, const std::string& description, long price); 

		std::string description(void) { return _description; }
		long price(void) { return _price; }
};

#endif /*_PRODUCT_H_ */
