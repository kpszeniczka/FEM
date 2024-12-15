project "FEMCPP"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++20"

	targetdir ("../bin/" .. OutputDir .. "/%{prj.name}")
	objdir ("../bin-int/" .. OutputDir .. "/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.cpp",
	}

	includedirs
	{
		"src",
	}

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		defines "DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "RELEASE"
		runtime "Release"
		optimize "on"