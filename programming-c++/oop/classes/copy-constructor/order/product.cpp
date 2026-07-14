#include "product.h"

using namespace std;

Product::Product(int id, const string& description, long price) 
	: _id{id}, _description{description}, _price{price}
{
}

// Copy Constructor
Product::Product(const Product& old)
{
	_id = old._id;
	_description = old._description;
	_price = old._price;
}	
