#include "Repo.h"
#include "Controller.h"
#include "UI.h"
#include "Tester.h"
#include <crtdbg.h>

int main()
{
	Repository* repository;
	repository = createRepo(1);
	Controller* controller;
	controller = createController(repository);
	UI* ui;
	ui = createUI(controller);
	test_All();
	run(ui);
	destroyUI(ui);
	
	_CrtDumpMemoryLeaks();
	return 0;
}