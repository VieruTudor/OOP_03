#pragma once

#include <string.h>
#include <stdlib.h>

typedef struct {
	int catalogueNumber;
	char state[30];
	char type[30];
	int value;
}Product;

/*
Creates a product "object" based on given fields
*/
Product createProduct(int catalogueNumber, char* state, char* type, int value);
/*
Destroys the product
*/
void destroyProduct(Product* product);
/*
Function that gets as input a Product and returns its catalogue number
*/
int getCatalogueNumber(Product* product);
/*
Function that gets as input a Product and returns its state

*/
char* getState(Product* product);
/*
Function that gets as input a Product and returns its catalogue type
*/
char* getType(Product* product);
/*
Function that gets as input a Product and returns its value
*/
int getValue(Product* product);


