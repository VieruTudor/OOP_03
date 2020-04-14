#define _CRT_SECURE_NO_WARNINGS
#include "Tester.h"
#include <assert.h>

void test_All()
{
	test_Domain_All();
	test_Repo_All();
	test_Controller_All();

}
void test_Domain_All()
{
	test_Domain_createProduct();
	test_Domain_getCatalogueNumber();
	test_Domain_getState();
	test_Domain_getType();
	test_Domain_getValue();
}

void test_Domain_createProduct()
{
	int catalogueNumber = 1;
	char* state = "test_state";
	char* type = "test_type";
	int value = 10;
	Product testProduct = createProduct(catalogueNumber, state, type, value);
	Product testedProduct = createProduct(1, "test_state", "test_type", 10);
	assert(testProduct.catalogueNumber == testedProduct.catalogueNumber);
	assert(strcmp(testProduct.state, testedProduct.state) == 0);
	assert(strcmp(testProduct.type, testedProduct.type) == 0);
	assert(testProduct.value == testedProduct.value);

}

void test_Domain_getCatalogueNumber()
{
	Product testProduct = createProduct(1, "test_state", "test_type", 10);
	assert(testProduct.catalogueNumber == 1);
}

void test_Domain_getState()
{
	Product testProduct = createProduct(1, "test_state", "test_type", 10);
	assert(strcmp(testProduct.state, "test_state") == 0);
}

void test_Domain_getType()
{
	Product testProduct = createProduct(1, "test_state", "test_type", 10);
	assert(strcmp(testProduct.type, "test_type") == 0);
}

void test_Domain_getValue()
{
	Product testProduct = createProduct(1, "test_state", "test_type", 10);
	assert(testProduct.value == 10);
}


void test_Repo_All()
{
	test_Repo_addProductRepo();
	test_Repo_addProductRepo_duplicateProduct();
	test_Repo_deleteProductRepo();
	test_Repo_updateProductRepo();
	test_Repo_getSizeRepo();
	test_Repo_undo();
	test_Repo_redo();
}

void test_Repo_addProductRepo()
{
	Repository* repo = createRepo(1);
	Product testProduct1 = createProduct(1, "test1", "test1", 10);
	addProductRepo(repo, testProduct1);
	assert(searchProductRepo(repo, testProduct1) != -1);
	destroyRepo(repo);
}

void test_Repo_addProductRepo_duplicateProduct()
{
	Repository* repo = createRepo(1);
	Product testProduct1 = createProduct(1, "test1", "test1", 10);
	addProductRepo(repo, testProduct1);
	Product testProduct2 = createProduct(1, "test2", "test2", 15);
	assert(addProductRepo(repo, testProduct2) != -1);
	destroyRepo(repo);

}

void test_Repo_updateProductRepo()
{
	Repository* repo = createRepo(1);
	Product testProduct1 = createProduct(1, "test1", "test1", 10);
	addProductRepo(repo, testProduct1);
	Product replaceProduct = createProduct(1, "test2", "test2", 15);
	updateProductRepo(repo, testProduct1, replaceProduct);
	destroyRepo(repo);

}

void test_Repo_deleteProductRepo()
{
	Repository* repo = createRepo(1);
	Product testProduct1 = createProduct(1, "test1", "test1", 10);
	addProductRepo(repo, testProduct1);
	Product testProduct2 = createProduct(2, "test2", "test2", 15);
	addProductRepo(repo, testProduct2);
	Product testProduct3 = createProduct(3, "test3", "test3", 25);
	addProductRepo(repo, testProduct3);
	assert(searchProductRepo(repo, testProduct2) != -1);
	deleteProductRepo(repo, testProduct2);
	assert(searchProductRepo(repo, testProduct2) == -1);
	destroyRepo(repo);

}

void test_Repo_getSizeRepo()
{
	Repository* repo = createRepo(1);
	assert(getSizeRepo(repo) == 0);
	Product testProduct = createProduct(1, "test", "test", 10);
	addProductRepo(repo, testProduct);
	assert(getSizeRepo(repo) == 1);
	destroyRepo(repo);
}

void test_Repo_undo()
{
	Repository* repo = createRepo(1);
	Product testProduct1 = createProduct(1, "test1", "test1", 10);
	addProductRepo(repo, testProduct1);
	undo(repo);
	assert(searchProductRepo(repo, testProduct1) == -1);

}

void test_Repo_redo()
{
	Repository* repo = createRepo(1);
	Product testProduct1 = createProduct(1, "test1", "test1", 10);
	addProductRepo(repo, testProduct1);
	undo(repo);
	assert(searchProductRepo(repo, testProduct1) == -1);
	redo(repo);
	assert(searchProductRepo(repo, testProduct1) != -1);
}


void test_Controller_All()
{
	//test_Controller_addProductController();
	//test_Controller_addProductController_duplicateProduct();
	test_Controller_deleteProductController_successful();
	test_Controller_deleteProductController_failed();
	test_Controller_updateProductController_successful();
	test_Controller_updateProductController_failed();
	test_Controller_getProductsLength();
	
}

void test_Controller_addProductController()
{
	Repository* repo = createRepo(1);
	Controller* controller = createController(repo);
	int catalogueNumber = 1;
	char* state = "test";
	char* type = "test";
	int value = 10;
	assert(addProductController(controller, catalogueNumber, state, type, value) == -1);
}

void test_Controller_addProductController_duplicateProduct()
{
	Repository* repo = createRepo(1);
	Controller* controller = createController(repo);
	int catalogueNumber = 1;
	char* state = "test";
	char* type = "test";
	int value = 10;
	addProductController(controller, catalogueNumber, state, type, value);
	catalogueNumber = 1;
	strcpy(state,"test2");
	strcpy(type, "test2");
	value = 15;
	assert(addProductController(controller, catalogueNumber, state, type, value) != -1);
	
}

void test_Controller_deleteProductController_successful()
{
	Repository* repo = createRepo(1);
	Controller* controller = createController(repo);
	int catalogueNumber = 1;
	char* state = "test";
	char* type = "test";
	int value = 10;
	addProductController(controller, catalogueNumber, state, type, value);
	assert(deleteProductController(controller, catalogueNumber) != -1);
}

void test_Controller_deleteProductController_failed()
{
	Repository* repo = createRepo(1);
	Controller* controller = createController(repo);
	int catalogueNumber = 1;
	char* state = "test";
	char* type = "test";
	int value = 10;
	addProductController(controller, catalogueNumber, state, type, value);
	assert(deleteProductController(controller, catalogueNumber) != -1);
	assert(deleteProductController(controller, catalogueNumber) == -1);
	
}

void test_Controller_updateProductController_successful()
{
	Repository* repo = createRepo(1);
	Controller* controller = createController(repo);
	int catalogueNumber = 1;
	char* state = "test";
	char* type = "test";
	int value = 10;
	addProductController(controller, catalogueNumber, state, type, value);
	char* newState = "test2";
	char* newType = "test2";
	int newValue = 15;
	assert(updateProductController(controller, catalogueNumber, newState, newType, newValue) != -1);

}

void test_Controller_updateProductController_failed()
{
	Repository* repo = createRepo(1);
	Controller* controller = createController(repo);
	int catalogueNumber = 1;
	char* state = "test";
	char* type = "test";
	int value = 10;
	addProductController(controller, catalogueNumber, state, type, value);
	catalogueNumber = 2;
	char* newState = "test2";
	char* newType = "test2";
	int newValue = 15;
	assert(updateProductController(controller, catalogueNumber, newState, newType, newValue) == -1);
}

void test_Controller_getProductsLength()
{
	Repository* repo = createRepo(1);
	Controller* controller = createController(repo);
	int catalogueNumber = 1;
	char* state = "test";
	char* type = "test";
	int value = 10;
	addProductController(controller, catalogueNumber, state, type, value);
	assert(getProductsLength(controller) == getSizeRepo(controller->repository));
}


