#pragma once
#include "Domain.h"
typedef struct {
	int size;
	int capacity;
	Product* elements;
}DynamicArray;

/*
Dynamic array constructor
capacity - integer representing the capacity of the created array
*/

DynamicArray* createDynamicArray(int capacity);

/*
Checks if the dynamic array needs a resize
*/
int needsResize(DynamicArray* dynamicArray);

/*
Resizes the dynamic array prior to adding a new element (if needed)
*/
void resizeDynamicArray(DynamicArray* dynamicArray);

/*
Dynamic Array destructor
*/
void destroyDynamicArray(DynamicArray* dynamicArray, Product product);

/*
Adds the product to the dynamic array
product - Product type
*/
void addElementDynamicArray(DynamicArray* dynamicArray, Product product);

/*
Removes element from a given index
index - integer representing the index of the element to be deleted
*/
void removeElementFromIndex(DynamicArray* dynamicArray, int index);

/*
Updates an element from a given index with a new given product
index - integer representing the index of the product to be updated
newProduct - Product type representing the new product to update
*/
void updateElementAtIndex(DynamicArray* dynamicArray, int index, Product newProduct);

/*
Product getter from a given index 
index - integer representing the index of the element
*/
Product getElement(DynamicArray* dynamicArray, int index);

/*
Returns a copy of a given dynamic array
*/
DynamicArray* getCopy(DynamicArray* dynamicArray);

/*
Returns the size of a given dynamic array
*/
int size(DynamicArray* dynamicArray);
