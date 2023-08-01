workspace "Haki"
	architecture "x86_64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
IncludeDirs = {} 
IncludeDirs["GLFW"] = "Haki/libraries/GLFW"

include "Haki/libraries/GLFW"

project "Haki"
	location "Haki"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "hkpch.h"
	pchsource "Haki/src/hkpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.hpp",
		"%{prj.name}/src/**.cpp"
	}

	includedirs 
	{
		"%{prj.name}/src",
		"%{prj.name}/libraries/spdlog/include",
		"%{IncludeDirs.GLFW}/include"
	}

	links 
	{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines 
		{
			"HK_PLATFORM_WINDOWS",
			"HK_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "HK_DEBUG"
		symbols "On"
		staticruntime "off"
		runtime "Debug"

	filter "configurations:Release"
		defines "HK_RELEASE"
		optimize "On"
		staticruntime "off"
		runtime "Release"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Haki/libraries/spdlog/include",
		"Haki/src"
	}

	links 
	{
		"Haki"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines 
		{
			"HK_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "HK_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "HK_RELEASE"
		optimize "On"