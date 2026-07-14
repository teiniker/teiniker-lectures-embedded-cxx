#include "order_line.h"

using namespace std;

OrderLine::OrderLine(int id, int quantity, Product* product)
	: _id{id}, _quantity{quantity}, _product{product}
{
}
