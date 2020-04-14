#pragma once

#include "Domain.h"
#include "DynamicArray.h"
typedef struct {
	DynamicArray* productList;
	DynamicArray** historyList;
	int historyListCount;
	int historyListIndex;
	

}Repository;

/*
Repository object constructor
*/
Repository* createRepo(int capacity);

/*
Repo destructor
*/
void destroyRepo(Repository* repository);

/*
Appends the current state of the list in the repo to the history list.
*/
void appendRepoInHistory(Repository* repository);

/*
Returns a deep copy of the elements in the repo
*/
DynamicArray* getRepoListCopy(Repository* repository);



/*
Function that gets a repository and a product, searches for it in the list and returns:
- an integer representing the index, if the product exists in the repository
- -1 otherwise
*/
int searchProductRepo(Repository* repository, Product product);

/*
Function that gets a repository and a product, tries to add it and returns:
- an integer representing the index if the product is already in the list
- -1 if the product was added successfully
*/
int addProductRepo(Repository* repository, Product product);

/*
Function that gets a repository and a product, tries to delete it and returns:
- -1 if the product is not in the list
- nothing if the operation performed successfully
*/
int deleteProductRepo(Repository* repository, Product product);

/*
Function that gets a repository, an old product to be replaced and a new one, tries to update and returns:
- -1 if the product is not in the list 
- an integer representing the index of the replaced product, if the operation performed successfully
*/
int updateProductRepo(Repository* repository, Product oldProduct, Product newProduct);


Product* getAllElementsRepo(Repository* repository);

int getSizeRepo(Repository* repository);

int undo(Repository* repository);
int redo(Repository* repository);
