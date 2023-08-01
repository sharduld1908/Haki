#pragma once

#ifdef HK_PLATFORM_WINDOWS

extern Haki::Application* Haki::CreateApplication();

int main(int argc, char** argv) {
	 
	Haki::Logger::Init();
	HK_CORE_WARN("Hello World!!!");
	HK_CLIENT_INFO("I am fine!!");

	auto app = Haki::CreateApplication();
	app->run();

	delete app;
}

#endif