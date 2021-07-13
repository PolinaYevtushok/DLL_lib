#include <iostream>
#include <filesystem>
#include <string>
#include "plugin.h"
#include <Windows.h>
using dll_function = IPlugin*(*)();

int main()
{
	const std::string path = "../Dll-lib/Plugins";

	for (const auto& entry : std::filesystem::recursive_directory_iterator(path))
	{
		auto file = entry.path().c_str();
		auto dll = LoadLibrary(file);
		auto f = reinterpret_cast<dll_function>(GetProcAddress(dll, "create_plugin"));
		auto* plugin = f();
		std::cout << plugin->GetPluginName() << std::endl;
		delete plugin;
	}
}