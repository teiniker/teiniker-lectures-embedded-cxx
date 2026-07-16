#pragma once

#include "entity.h"
#include "product.h"

class OrderLine : public Entity 
{
	private:
		int _quantity;
		Product* _product; // ---[0..1]-> Product
 
	public:
		OrderLine(int id, int quantity, Product* product);

		int quantity(void) { return _quantity; }
		Product* product(void) { return _product; }
 };
