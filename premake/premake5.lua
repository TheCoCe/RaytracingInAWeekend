solution "RaytracingInAWeekend"
	configurations { "Debug", "Release" }
	platforms { "x64" }
	systemversion("latest")
	
	--
	-- Debug/Release Configurations
	--
	configuration "Debug"
		defines
		{
			"_DEBUG"
		}
		symbols "On"
		vectorextensions "SSE"
		warnings "Extra"

	configuration "Release"
		defines
		{
			"NDEBUG"
		}
		symbols "Off"
		vectorextensions "SSE"
		optimize "Speed"
		warnings "Extra"
	
	configuration { "vs*" }
		targetdir ".."
		flags
		{
			"NoManifest",
			"NoMinimalRebuild",
			"No64BitChecks",
		}
		exceptionhandling "Off"
		editandcontinue "Off"
		buildoptions
		{
			-- multi processor support
			"/MP",
			
			-- warnings to ignore:
			-- "/wd4711", -- smells like old people
			
			-- warnings to force
			
			-- An accessor overrides, with or without the virtual keyword, a base class accessor function,
			-- but the override or new specifier was not part of the overriding function signature.
			"/we4485",
		}
		
	
	configuration { "vs*", "Debug" }
		buildoptions
		{
			-- turn off Smaller Type Check
			--"/RTC-",
		
			-- turn off Basic Runtime Checks
			--"/RTC1-",
		}
		
	configuration { "vs*", "Release" }
		buildoptions
		{
			-- turn off Whole Program Optimization
			--"/GL-",
			
			-- Inline Function Expansion: Any Suitable (/Ob2)
			"/Ob2",
			
			-- Favor fast code
			"/Ot",
			
			-- enable Intrinsic Functions
			"/Oi",
			
			-- Omit Frame Pointers
			"/Oy",
		}

project "RaytracingInAWeekend"
	targetname "RaytracingInAWeekend"
	language "C++"
	kind "ConsoleApp"
	files
	{
		"../src/**.h", "../src/**.cpp",
	}
		
	configuration { "vs*", "x64" }
	targetdir "../bin/Win64"
		links
		{			
			"kernel32",
			"user32",
			"gdi32",
			"winspool",
			"comdlg32",
			"advapi32",
			"shell32",
			"ole32",
			"oleaut32",
			"uuid",
			"odbc32",
			"odbccp32",
		}
			
	

	

