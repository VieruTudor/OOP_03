#pragma once

#include "Controller.h"

typedef struct {
	Controller* controller;
}UI;

/*
Constructs a UI based on a controller
*/
UI* createUI(Controller* controller);

/*
UI Destroyer
*/
void destroyUI(UI* ui);

/*
Gets a product as parameter and formats its attributes for displaying.
*/
void printProduct(Product product);


/*
Gets a catalogue number, a state, a type and a value from the user input  and sends them to the Controller for
the adding process.
*/
void addProductUI(UI* ui, int catalogueNumber, char* state, char* type, int value);

/*
Gets a catalogue number from the user input and sends it to the Controller for the deleting process.
*/
void deleteProductUI(UI* ui, int catalogueNumber);

/*
Gets a catalogue number, a state, a type and a value from the user input  and sends them to the Controller for
the updating process.
*/
void updateProductUI(UI* ui, int catalogueNumber, char* newState, char* newType, int newValue);

/*
Iterates through all the objects and prints them
*/
void listProducts(UI* ui);

/*
Iterates through all the objects and prints the objects with the given type.
*/
void listProductsOfType(UI* ui, char* type);

/*
Parses the add command and updates the parameter variables for the addProductUI function
*/
void readAddCommand(UI* ui, int* catalogueNumber, char* state, char* type, int* value);

/*
Parses the update command and updates the parameter variables for the updateProductUI function
*/
void readUpdateCommand(UI* ui, int* catalogueNumber, char* newState, char* newType, int* newValue);

/*
Parses the delete command and updates the parameter variable for the deleteProductUI function
*/
void readDeleteCommand(UI* ui, int* catalogueNumber);

/*
Reads the user input and parses the main command, separating the operation from the parameters
*/
int readUserCommand(UI* ui);

/*
Starts the UI
*/
void run(UI* ui);

/*
Calls the Controller for the undo function
*/
void undoUI(UI* ui);


/*
Calls the Controller for the undo function
*/
void redoUI(UI* ui);

