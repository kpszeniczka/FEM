workspace "FEMCPP"
    architecture "x64"
    startproject "FEMCPP"

    configurations {
        "Debug",
        "Release"
    }

    filter "system:windows"
        buildoptions { "/EHsc", "/Zc:preprocessor", "/Zc:__cplusplus" }

    OutputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
    
    include "FEMCPP/premake5.lua"