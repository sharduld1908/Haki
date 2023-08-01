#pragma once

#include "Haki/Window.h"
#include "GLFW/glfw3.h"

namespace Haki {

	class WindowsWindow : public Window {
	private:
		GLFWwindow* m_Window;

		struct WindowData {
			std::string Title;
			unsigned int width, height;
			bool VSync;

			//EventCallBackFn event_callback;
		};

		WindowData m_Data;

		virtual void Init(const WindowProperties& props);
		virtual void ShutDown();

	public:
		WindowsWindow(const WindowProperties& props);
		virtual ~WindowsWindow();

		virtual void OnUpdate() override;

		virtual inline unsigned int GetWidth() const { return m_Data.width; }
		virtual inline unsigned int GetHeigth() const { return m_Data.height; }

		//inline void SetEventCallBack(const EventCallBackFn& callback) { m_Data.event_callback = callback; }
		virtual void SetVSync(bool enabled) override;
		virtual bool IsVSync() const override;


	};
}