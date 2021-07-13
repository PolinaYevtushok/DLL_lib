#pragma once
#include <string>
#include<iostream>


class IPlugin
{
public:
	IPlugin() = default;
	virtual ~IPlugin() = default;

	virtual std::string GetPluginName() const noexcept = 0;
};
