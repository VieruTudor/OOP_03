#include "Repo.h"
#include <stdio.h>
#include <stdlib.h>
#define MAXIMUM_NUMBER_OF_OPERATIONS 100
Repository* createRepo(int capacity)
{
	Repository* repo;
	repo = (Repository*)malloc(sizeof(Repository));
	repo->productList = createDynamicArray(capacity);
	repo->historyList = (DynamicArray**)malloc(sizeof(DynamicArray*) * MAXIMUM_NUMBER_OF_OPERATIONS);
	repo->historyListCount = 1;
	repo->historyListIndex = 0;
	appendRepoInHistory(repo);
	return repo;
}

void destroyRepo(Repository* repository)
{
	free(repository->productList->elements);
	free(repository->productList);
	free(repository);
}


void appendRepoInHistory(Repository* repository)
{
	repository->historyList[repository->historyListCount] = getRepoListCopy(repository);
	repository->historyListCount++;
	repository->historyListIndex++;
}

DynamicArray* getRepoListCopy(Repository* repository)
{
	DynamicArray* arrayCopy = getCopy(repository->productList);
	return arrayCopy;
}

int searchProductRepo(Repository* repository, Product product)
{
	int index;
	for (index = 0; index < repository->productList->size; index++)
		if (getElement(repository->productList, index).catalogueNumber == product.catalogueNumber)
			return index;
	return -1;
}

int addProductRepo(Repository* repository, Product product)
{
	int productIndex;
	productIndex = searchProductRepo(repository, product);
	if (productIndex != -1)
		return productIndex;
	addElementDynamicArray(repository->productList, product);
	appendRepoInHistory(repository);
	return -1;
}

int deleteProductRepo(Repository* repository, Product product)
{
	int productIndex;
	productIndex = searchProductRepo(repository, product);
	if (productIndex == -1)
		return productIndex;
	removeElementFromIndex(repository->productList, productIndex);
	appendRepoInHistory(repository);
}

int updateProductRepo(Repository* repository, Product oldProduct, Product newProduct)
{
	int productIndex;
	productIndex = searchProductRepo(repository, oldProduct);
	if (productIndex == -1)
		return productIndex;
	updateElementAtIndex(repository->productList, productIndex, newProduct);
	appendRepoInHistory(repository);
	return productIndex;
}

Product* getAllElementsRepo(Repository* repository)
{
	return repository->productList->elements;
}

int getSizeRepo(Repository* repository)
{
	return repository->productList->size;
}

int undo(Repository* repository)
{
	
	if (repository->historyListIndex == 0)
		return 0;
	repository->productList = getCopy(repository->historyList[repository->historyListIndex - 1]);
	repository->historyListIndex--;
	return 1;
}

int redo(Repository* repository)
{
	if (repository->historyListIndex == repository->historyListCount)
		return 0;
	repository->productList = getCopy(repository->historyList[repository->historyListIndex + 1]);
	repository->historyListIndex++;
	return 1;
}
