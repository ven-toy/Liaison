project "App"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"
    targetdir "Binaries/%{cfg.buildcfg}"
    staticruntime "off"

    -- Include directories
    includedirs 
    { 
        "Source", 
        "../Core/Source" 
    }

    -- Links
    links 
    { 
        "Core" 
    }

    -- Define the path to the Modules directory
    local modulesPath = "../Modules"

    -- Find all Build.lua files within the Modules directory and its subdirectories
    local buildFiles = os.matchfiles(modulesPath .. "/**/Build.lua")

    -- Iterate over each found Build.lua file
    for _, buildFile in ipairs(buildFiles) do
        -- Extract the module directory from the build file path
        local moduleDir = path.getdirectory(buildFile)

        -- Add the module's Source directory to the include directories
        includedirs { path.join(moduleDir, "Source") }

        -- Extract the module name from the directory path
        local moduleName = path.getname(moduleDir)

        -- Link the module
        links { moduleName }

        print("Linked " .. moduleName .. " with the App!")
    end

    targetdir ("../Binaries/" .. OutputDirectory .. "/%{prj.name}")
    objdir ("../Binaries/Intermediates/" .. OutputDirectory .. "/%{prj.name}")

    filter "system:windows"
        systemversion "latest"
        defines { }
    
    filter "configurations:Debug"
        defines { "DEBUG" }
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines { "RELEASE" }
        runtime "Release"
        optimize "On"
        symbols "On"

    filter "configurations:Distribution"
        defines { "DIST" }
        runtime "Release"
        optimize "On"
        symbols "Off"
