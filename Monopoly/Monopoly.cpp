#include "Application.h"

int main() {
	printf("Hello");
	Application* app;
	app = new Application();
	app->run();
	if(app != nullptr) delete app;
}