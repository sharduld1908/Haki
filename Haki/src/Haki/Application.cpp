
#include "hkpch.h"
#include "Application.h"

namespace Haki {

	Application::Application() {
		window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application() {}

	void Application::run() {
		while (true) {
			window->OnUpdate();
		}
	}

}