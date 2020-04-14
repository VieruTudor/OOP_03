#define _CRT_SECURE_NO_WARNINGS
#include "Domain.h"
#include <stdlib.h>
#include <string.h>

Product createProduct(int catalogueNumber, char* state, char* type, int value)
{
	Product product;
	product.catalogueNumber = catalogueNumber;
	strcpy(product.state, state);
	strcpy(product.type, type);
	product.value = value;

	return product;
}

void destroyProduct(Product* product)
{
	free(product);
}

int getCatalogueNumber(Product* product)
{
	return product->catalogueNumber;
}

char* getState(Product* product)
{
	return product->state;
}

char* getType(Product* product)
{
	return product->type;
}

int getValue(Product* product)
{
	return product->value;
}

