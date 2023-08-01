#pragma once

#include "Core.h"
#include "Window.h"

namespace Haki {

	class HAKI_API Application
	{
	public:
		Application();
		virtual ~Application();

		void run();

	private:
		std::unique_ptr<Window> window;
	};

	Application* CreateApplication();

}

