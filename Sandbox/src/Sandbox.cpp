#include <Haki.h>

class Sandbox : public Haki::Application {
public:
	Sandbox() {

	}

	~Sandbox() {

	}
};

Haki::Application* Haki::CreateApplication()
{
	return new Sandbox();
}