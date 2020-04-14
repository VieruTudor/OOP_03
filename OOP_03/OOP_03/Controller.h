#pragma once

#include "Repo.h"

typedef struct {
	Repository* repository;

	int filterListLength;
}Controller;

/*
Function that constructs a controller based on a repository
*/
Controller* createController(Repository* repository);

/*
Controller destructor
*/
void destroyController(Controller* controller);

/*
Function that gets a catalogue number, a state, a type and a value from the UI, creates a Product and sends it to
the repo for adding, returning the value of the performed operation.
*/
int addProductController(Controller* controller, int catalogueNumber, char* state, char* type, int value);

/*
Function that gets a catalogue number from the UI, creates a "dummy object" having only catalogue number as an
empty field, and sends it to the repo for deleting
*/
int deleteProductController(Controller* controller, int catalogueNumber);

/*
Function that gets a catalogue number, a state, a type and a value from the UI, creates a Product and sends it to
the repo for updating, returning the value of the performed operation.
*/
int updateProductController(Controller* controller, int catalogueNumber, char* newState, char* newType, int newValue);

/*
Calls the repo and returns all the products from it
*/
Product* getAllProducts(Controller* controller);

/*
Calls the repo and returns the size of its product list
*/
int getProductsLength(Controller* controller);

/*
Returns the list of filtered products, based on a given value, sorted alphabetically
*/
Product* getFilteredProducts(Controller* controller, int filterValue);

/*
Returns the length of the filtered products
*/
int getFilterListLength(Controller* controller);

/*
Calls the Repo for the undo function
*/
int undoController(Controller* controller);

/*
Calls the Repo for the redo function
*/
int redoController(Controller* controller);
