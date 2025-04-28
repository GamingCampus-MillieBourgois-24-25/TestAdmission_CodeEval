#pragma once

#include <functional>
#include <map>
#include <stdexcept>
#include <string>

#include "ExerciseType/ExerciseBase.h"

class TestRegistry
{
public:
	static void RegisterTest(const std::string& _test_name, const std::function<ExerciseBase*()>& _creator)
	{
		if (tests.contains(_test_name))
		{
			throw std::runtime_error("Test already registered: " + _test_name);
		}
		tests[_test_name] = _creator;
	}

	static ExerciseBase* CreateTestInstance(const std::string& _test_name)
	{
		if (const auto it = tests.find(_test_name); it != tests.end())
		{
			return it->second();
		}
		return nullptr;
	}

private:
	static inline std::map<std::string, std::function<ExerciseBase*()>> tests;
};
