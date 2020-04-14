#define _CRT_SECURE_NO_WARNINGS
#include "DynamicArray.h"
#include <stdlib.h>
#include <stdio.h>

DynamicArray* createDynamicArray(int capacity)
{
	DynamicArray* dynamicArray = (DynamicArray*)malloc(sizeof(DynamicArray));
	dynamicArray->size = 0;
	dynamicArray->capacity = capacity;
	dynamicArray->elements = (Product*)malloc(sizeof(Product) * capacity);
	return dynamicArray;
}

void resizeDynamicArray(DynamicArray* dynamicArray)
{
	dynamicArray->capacity *= 2;
	Product* newElements = (Product*)malloc(sizeof(Product) * dynamicArray->capacity);
	int i;
	for (i = 0; i < dynamicArray->size; i++)
		newElements[i] = dynamicArray->elements[i];
	free(dynamicArray->elements);
	dynamicArray->elements = newElements;
}

void destroyDynamicArray(DynamicArray* dynamicArray, Product product)
{
	free(dynamicArray->elements);
	free(dynamicArray);	
}

void addElementDynamicArray(DynamicArray* dynamicArray, Product product)
{
	if (needsResize(dynamicArray))
	{
		resizeDynamicArray(dynamicArray);
	}
	++dynamicArray->size;
	dynamicArray->elements[dynamicArray->size - 1] = product;
	
	
}

void removeElementFromIndex(DynamicArray* dynamicArray, int index)
{
	int i;
	for (i = index; i < dynamicArray->size; i++)
		dynamicArray->elements[i] = dynamicArray->elements[i + 1];
	dynamicArray->size--;
}

void updateElementAtIndex(DynamicArray* dynamicArray, int index, Product newProduct)
{
	dynamicArray->elements[index] = newProduct;
}

Product getElement(DynamicArray* dynamicArray, int index)
{
	return dynamicArray->elements[index];
}

DynamicArray* getCopy(DynamicArray* dynamicArray)
{
	DynamicArray* copyArray = createDynamicArray(dynamicArray->capacity);
	int i;
	for (i = 0; i < dynamicArray->size; i++)
		addElementDynamicArray(copyArray, getElement(dynamicArray, i));
	return copyArray;
}

int size(DynamicArray* dynamicArray)
{
	return dynamicArray->size;
}

int needsResize(DynamicArray* dynamicArray)
{
	return dynamicArray->size == dynamicArray->capacity;
}
