#include "order_line.h"

OrderLine::OrderLine(int id, int quantity, Product* product)
	: Entity(id), _quantity{quantity}, _product{product}
{
}
