#include "Controller.h"
#include "Repo.h"
#include <string.h>
#include <stdlib.h>

Controller* createController(Repository* repository)
{
	Controller* controller;
	controller = (Controller*)malloc(sizeof(Controller));
	controller->repository = repository;
	return controller;
}

void destroyController(Controller* controller)
{
	destroyRepo(controller->repository);
	free(controller);
}

int addProductController(Controller* controller, int catalogueNumber, char* state, char* type, int value)
{
	Product addedProduct;
	addedProduct = createProduct(catalogueNumber, state, type, value);
	return addProductRepo(controller->repository, addedProduct);
}

int deleteProductController(Controller* controller, int catalogueNumber)
{
	Product deletedProduct = createProduct(catalogueNumber, "", "", 0);
	return deleteProductRepo(controller->repository, deletedProduct);
}

int updateProductController(Controller* controller, int catalogueNumber, char* newState, char* newType, int newValue)
{
	Product oldProduct = createProduct(catalogueNumber, "", "", 0);
	Product newProduct = createProduct(catalogueNumber, newState, newType, newValue);
	return updateProductRepo(controller->repository, oldProduct, newProduct);
}

Product* getAllProducts(Controller* controller)
{
	return getAllElementsRepo(controller->repository);
}

int getProductsLength(Controller* controller)
{
	return getSizeRepo(controller->repository);
}

Product* getFilteredProducts(Controller* controller, int filterValue)
{
	int i, j;
	Product filteredValues[105];
	controller->filterListLength = 0;
	for (i = 0; i < getSizeRepo(controller->repository); i++)
		if (getAllElementsRepo(controller->repository)[i].value < filterValue)
			filteredValues[controller->filterListLength] = getAllElementsRepo(controller->repository)[i], controller->filterListLength++;
	for(i = 0; i < controller->filterListLength; i++)
		for(j = i + 1; j < controller->filterListLength; j++)
			if (strcmp(filteredValues[i].type, filteredValues[j].type) > 0)
			{
				Product temp;
				temp = filteredValues[i];
				filteredValues[i] = filteredValues[j];
				filteredValues[j] = temp;
			}
	return filteredValues;
}

int getFilterListLength(Controller* controller)
{
	return controller->filterListLength;
}

int undoController(Controller* controller)
{
	return undo(controller->repository);
}

int redoController(Controller* controller)
{
	return redo(controller->repository);
}
