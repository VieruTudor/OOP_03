#define _CRT_SECURE_NO_WARNINGS
#include "UI.h"
#include "Controller.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


UI* createUI(Controller* controller)
{
	UI* ui;
	ui = (UI*)malloc(sizeof(UI));
	ui->controller = controller;
	return ui;
}
void destroyUI(UI* ui)
{
	destroyController(ui->controller);
	free(ui);
}

void printProduct(Product product)
{
	printf("Product %d, is %s, of type %s, with a value of %d\n", product.catalogueNumber, product.state, product.type, product.value);
}
void addProductUI(UI* ui, int catalogueNumber, char* state, char* type, int value)
{
	int addIndex = addProductController(ui->controller, catalogueNumber, state, type, value);
	if (addIndex != -1)
		printf("No!");
}

void deleteProductUI(UI* ui, int catalogueNumber)
{
	int deleteIndex = deleteProductController(ui->controller, catalogueNumber);
	if (deleteIndex == -1)
		printf("No!");
}

void updateProductUI(UI* ui, int catalogueNumber, char* newState, char* newType, int newValue)
{
	int updateIndex = updateProductController(ui->controller, catalogueNumber, newState, newType, newValue);
	if (updateIndex == -1)
		printf("No!");
}

void listProducts(UI* ui)
{
	int i;
	for (i = 0; i < getProductsLength(ui->controller); i++)
	{
		printProduct(getAllProducts(ui->controller)[i]);
	}
}

void listProductsOfType(UI* ui, char* type)
{
	int i;
	for (i = 0; i < getProductsLength(ui->controller); i++)
		if (strcmp(getAllProducts(ui->controller)[i].type, type) == 0)
			printProduct(getAllProducts(ui->controller)[i]);
}


void undoUI(UI* ui)
{
	int completedUndo = undoController(ui->controller);
	if (completedUndo == 0)
		printf("Nothing to undo!\n");
}

void redoUI(UI* ui)
{
	int completedRedo = redoController(ui->controller);
	if (completedRedo == 0)
		printf("Nothing to redo!\n");
}



void readAddCommand(UI* ui, int* catalogueNumber, char* state, char* type, int* value)
{
	char* partPointer;
	char part[50];

	partPointer = strtok(0, ",");
	strcpy(part, partPointer);
	*catalogueNumber = atoi(part);

	partPointer = strtok(0, ",");
	strcpy(part, partPointer + 2);
	strcpy(state, partPointer);

	partPointer = strtok(0, ", ");
	strcpy(part, partPointer + 2);
	strcpy(type, partPointer);

	partPointer = strtok(0, ",");
	strcpy(part, partPointer + 1);
	*value = atoi(part);

	if (catalogueNumber == 0 || value == 0)
		printf("Incantation bad!\n");

}

void readUpdateCommand(UI* ui, int* catalogueNumber, char* newState, char* newType, int* newValue)
{
	char* partPointer;
	char part[50];

	partPointer = strtok(0, ",");
	strcpy(part, partPointer);
	*catalogueNumber = atoi(part);

	partPointer = strtok(0, ",");
	strcpy(part, partPointer + 1);
	strcpy(newState, partPointer);

	partPointer = strtok(0, ",");
	strcpy(part, partPointer + 1);
	strcpy(newType, partPointer);

	partPointer = strtok(0, ",");
	strcpy(part, partPointer + 1);
	*newValue = atoi(part);

	if (catalogueNumber == 0 || newValue == 0)
		printf("Incantation bad!\n");
}
void readDeleteCommand(UI* ui, int* catalogueNumber)
{
	char* partPointer;
	char part[50];

	partPointer = strtok(0, " ");
	strcpy(part, partPointer);
	*catalogueNumber = atoi(part);
	
	if (catalogueNumber == 0)
		printf("Incantation bad!\n");
}

void listMaximumPotencyValue(UI* ui, int filterValue)
{
	Product* filteredValues = getFilteredProducts(ui->controller, filterValue);
	int i;
	for (i = 0; i < getFilterListLength(ui->controller); i++)
		printProduct(filteredValues[i]);
}


int readUserCommand(UI* ui)
{
	int catalogueNumber, value, newValue;
	char state[50], type[50], newState[50], newType[50], userCommand[100], operation[15];
	char* partPointer;

	gets(userCommand);

	partPointer = strtok(userCommand, " ");
	strcpy(operation, partPointer);

	if (strcmp(operation, "exit") == 0)
		return 1;

	if (strcmp(operation, "add") == 0)
	{
		readAddCommand(ui, &catalogueNumber, state, type, &value);
		addProductUI(ui, catalogueNumber, state, type, value);
		return 0;
	}

	if (strcmp(operation, "update") == 0)
	{
		readUpdateCommand(ui, &catalogueNumber, newState, newType, &newValue);
		updateProductUI(ui, catalogueNumber, newState, newType, newValue);
		return 0;
	}

	if (strcmp(operation, "delete") == 0)
	{
		readDeleteCommand(ui, &catalogueNumber);
		deleteProductUI(ui, catalogueNumber);
		return 0;
	}
	
	if (strcmp(operation, "undo") == 0)
	{
		undoUI(ui);
		return 0;
	}

	if (strcmp(operation, "redo") == 0)
	{
		redoUI(ui);
		return 0;
	}


	if (strcmp(operation, "list") == 0)
	{
		partPointer = strtok(NULL, " ");
		if (partPointer == NULL)
		{
			listProducts(ui);
		}
		else
		{
			int filterValue = atoi(partPointer);
			if (filterValue != 0) // it is a number
			{
				listMaximumPotencyValue(ui, filterValue);
			}
			else // it is not
			{
				strcpy(type, partPointer);
				listProductsOfType(ui, type);
			}
		}
		return 0;
	}
	else
	{
		printf("Incantation bad!\n");
		return 0;
	}
		
}

void run(UI* ui)
{
	int isRunning;
	isRunning = readUserCommand(ui);
	if (isRunning == 0)
		run(ui);
}

