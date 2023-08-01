#pragma once

#include "hkpch.h"

#include "Haki/Core.h"

namespace Haki {
	
	class WindowProperties {
	public:
		std::string title;
		int width;
		int height;

		WindowProperties(std::string title = "Haki Engine", unsigned const int width = 1280, unsigned const int height = 720)
			: title(title), width(width), height(height) {}
	};

	class HAKI_API Window {
	public:
		Window() {}
		virtual ~Window() {}

		//using EventCallBackFn = std::function(void<Event&>);

		virtual void OnUpdate() {}

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeigth() const = 0;

		//virtual void SetEventCallBack(const EventCallBackFn& callback) = 0;

		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		static Window* Create(const WindowProperties& props = WindowProperties());
	};

}