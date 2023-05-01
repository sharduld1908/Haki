#pragma once

#include "Core.h"

namespace Haki {

	class HAKI_API Application
	{
	public:
		Application();
		virtual ~Application();

		void run();
	};

	Application* CreateApplication();

}

