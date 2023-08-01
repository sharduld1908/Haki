#pragma once

#ifdef HK_PLATFORM_WINDOWS

extern Haki::Application* Haki::CreateApplication();

int main(int argc, char** argv) {
	 
	Haki::Logger::Init();
	
	auto app = Haki::CreateApplication();
	HK_CLIENT_INFO("Starting Client!!");

	app->run();
	HK_CORE_WARN("Starting Core!!");

	delete app;
}

#endif