#include "hkpch.h"
#include "WindowsWindow.h"

namespace Haki {

	static bool glfw_init = false;

	Window* Window::Create(const WindowProperties& props)
	{
		return new WindowsWindow(props);
	}

	void WindowsWindow::Init(const WindowProperties& props)
	{
		m_Data.width = props.width;
		m_Data.height = props.height;
		m_Data.Title = props.title;

		if (!glfw_init) {
			int success = glfwInit();
			if (!success) {
				HK_CORE_ERROR("Could not Initialize GLFW");
			}

			glfw_init = true;
		}

		HK_CORE_INFO("Creating Window {0} of size ({1},{2})", m_Data.Title, m_Data.width, m_Data.height);

		m_Window = glfwCreateWindow(m_Data.width, m_Data.height, m_Data.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);
	}

	void WindowsWindow::ShutDown()
	{
		glfwDestroyWindow(m_Window);
	}

	WindowsWindow::WindowsWindow(const WindowProperties& props)
	{
		Init(props);
	}

	WindowsWindow::~WindowsWindow()
	{
		ShutDown();
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void WindowsWindow::SetVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		m_Data.VSync = enabled;
	}

	bool WindowsWindow::IsVSync() const
	{
		return m_Data.VSync;
	}
}
