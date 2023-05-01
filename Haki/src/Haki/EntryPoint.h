#pragma once

#ifdef HK_PLATFORM_WINDOWS

extern Haki::Application* Haki::CreateApplication();

int main(int argc, char** argv) {

	std::cout << "Hello.................";
	auto app = Haki::CreateApplication();
	app->run();

	delete app;
}

#endif