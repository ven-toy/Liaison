-- /Build.lua
workspace "LiaisonApp"
    architecture "x86_64"
    -- startProject "App"

    configurations { "Debug", "Release", "Distribution" }
    flags { "MultiProcessorCompile" }


OutputDirectory = "%{cfg.system}-%{cfg.architecture}/%{cfg.buildcfg}"

include "Build-Vendor.lua"

