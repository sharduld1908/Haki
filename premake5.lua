workspace "Haki"
	architecture "x86_64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Haki"
	location "Haki"
	kind "SharedLib"
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
		"%{prj.name}/libraries/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.22000.0"

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

	filter "configurations:Debug"
		defines "HK_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "HK_DIST"
		optimize "On"


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
		systemversion "10.0.22000.0"

		defines 
		{
			"HK_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "HK_DEBUG"
		symbols "On"

	filter "configurations:Debug"
		defines "HK_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "HK_DIST"
		optimize "On"