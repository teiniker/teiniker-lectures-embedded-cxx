#ifndef _ORDERLINE_H_
#define _ORDERLINE_H_

#include <string>
#include "product.h"

class OrderLine 
{
	private:
		int _id; 
		int _quantity;
		Product* _product; // ---[0..1]-> Product
 
	public:
		OrderLine(int id, int quantity, Product* product);
		OrderLine(const OrderLine& old);	// Copy Constructor

		int id(void) const { return _id; }
		int quantity(void) const { return _quantity; }
		Product* product(void) const { return _product; }
		void set_product(Product* product) { _product = product; }
};

#endif /*_ORDERLINE_H_ */
