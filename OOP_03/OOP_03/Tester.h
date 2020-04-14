#pragma once

#include "Domain.h"
#include "Repo.h"
#include "Controller.h"


void test_All();
void test_Domain_All();
void test_Domain_createProduct();
void test_Domain_getCatalogueNumber();
void test_Domain_getState();
void test_Domain_getType();
void test_Domain_getValue();

void test_Repo_All();
void test_Repo_addProductRepo();
void test_Repo_updateProductRepo();
void test_Repo_deleteProductRepo();
void test_Repo_getSizeRepo();
void test_Repo_addProductRepo_duplicateProduct();
void test_Repo_undo();
void test_Repo_redo();

void test_Controller_All();
void test_Controller_addProductController();
void test_Controller_addProductController_duplicateProduct();
void test_Controller_deleteProductController_successful();
void test_Controller_deleteProductController_failed();
void test_Controller_updateProductController_successful();
void test_Controller_updateProductController_failed();
void test_Controller_getProductsLength();

