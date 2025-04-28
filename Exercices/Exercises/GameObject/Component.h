#pragma once

#include <iostream>

class Component
{
public:
	virtual ~Component() = default;
	virtual void Display() const = 0;
};

class Transform : public Component
{
public:
	void Display() const override
	{
		std::cout << "Transform Component" << std::endl;
	}
};

class Renderer : public Component
{
public:
	void Display() const override
	{
		std::cout << "Renderer Component" << std::endl;
	}
};

class Collider : public Component
{
public:
	void Display() const override
	{
		std::cout << "Collider Component" << std::endl;
	}
};
