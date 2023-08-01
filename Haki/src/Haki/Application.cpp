
#include "hkpch.h"
#include "Application.h"
#include "GLFW/glfw3.h"

namespace Haki {

	Application::Application() {
		window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application() {}

	void Application::run() {
		while (true) {
			glClearColor(0, 1, 0, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			window->OnUpdate();
		}
	}

}