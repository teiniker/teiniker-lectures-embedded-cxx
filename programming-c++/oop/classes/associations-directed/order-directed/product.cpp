#include "product.h"

using namespace std;

Product::Product(int id, const string& description, long price) 
	: _id{id}, _description{description}, _price{price}
{
}
