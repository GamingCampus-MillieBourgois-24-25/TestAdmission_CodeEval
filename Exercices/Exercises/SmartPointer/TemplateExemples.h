#pragma once

#include <iostream>
#include <string>
#include <vector>

/**
 * @brief Introduction to Templates in C++
 *
 * Templates are a powerful feature in C++ that allow you to write generic code.
 * They enable functions and classes to work with any data type without rewriting
 * the logic for each type.
 *
 * Key Points:
 * - Function Templates: Generic functions that work with multiple types.
 * - Class Templates: Generic classes to create flexible data structures.
 * - Benefits: Reusability, type safety, and reduced code duplication.
 *
 * Contents:
 * 1. Function Template: Find Maximum of Two Values
 * 2. Class Template: Generic Container
 * 3. Template Specialization (Advanced)
 * 4. Template Function with Containers
 */

/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */

/** 
 * @brief Function Template: Find Maximum of Two Values
 *
 * This template allows you to find the maximum of two values of the same type.
 * The 'T' is a placeholder for any type (int, double, string, etc.).
 * The compiler will replace 'T' with the actual type when the function is called.
 *
 * Syntax:
 * template <typename T>
 * T FunctionName(T param1, T param2) { ... }
 */
template <typename T>
T GetMax(T a, T b)
{
	return (a > b) ? a : b;
}

/**
 * Example Usage:
 * GetMax<int>(3, 5);        // Returns 5 (int)
 * GetMax<double>(3.5, 2.1);    // Returns 3.5 (double)
 *
 * If the type can be inferred from the arguments (because both arguments are of the same type for example), you can omit the type between '<>':
 * GetMax(3.51f, 2.14f);    // Returns 3.5 (float) 
 * GetMax('a', 'z');    // Returns 'z' (char)
 * GetMax("apple", "zebra"); // Returns "zebra" (string, uses lexicographical comparison)
 */

/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */

/**
 * @brief Class Template: Generic Container
 *
 * This template demonstrates a generic class that can hold a single value of any type.
 * The type is specified when creating an instance of the class.
 *
 * Syntax:
 * template <typename T>
 * class ClassName { ... };
 */
template <typename T>
class GenericContainer
{
public:
	// Constructor
	GenericContainer(T value) : value(value)
	{
	}

	// Getter for the stored value
	T GetValue() const
	{
		return value;
	}

	// Method to display the value
	void Display() const
	{
		std::cout << "Value: " << value << std::endl;
	}

private:
	T value; // Generic type
};

/**
 * Example Usage:
 * GenericContainer<int> intContainer(42);
 * intContainer.Display();  // Output: Value: 42
 *
 * GenericContainer<std::string> stringContainer("Hello");
 * stringContainer.Display();  // Output: Value: Hello
 */

/**
 * @brief Template Specialization (Advanced) - Specializing for 'std::string' for example
 * !! You need to read previous examples to understand this one !!
 *
 * A template can be specialized for specific types to provide custom behavior.
 * Below is an example of specializing 'GenericContainer' for 'std::string' to add
 * extra behavior specific to strings.
 *
 * Here, putting nothing in '<>' will make the compiler understand that it is a specialization of the template previously defined.
 * But instead of letting the compiler change all T by std::string, we specify that we want to specialize the template for std::string.
 */
template <>
class GenericContainer<std::string>
{
public:
	GenericContainer(const std::string& value) : value(value)
	{
	}

	// Specialized method for strings
	void Display() const
	{
		std::cout << "String Value: \"" << value << "\"" << std::endl;
	}

private:
	std::string value;
};

/**
 * Example Usage:
 * GenericContainer<std::string> stringContainer("Specialized Hello");
 * stringContainer.Display();  // Output: String Value: "Specialized Hello"
 */

/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */

/**
 * @brief Template Function with Containers
 *
 * Templates can also be used with containers like 'std::vector' to perform generic
 * operations. Below is an example of finding the maximum element in a vector.
 *
 * Practical Example:
 * std::vector<int> leaderboard = {100, 250, 300, 200};
 * std::cout << "Highest Score: " << FindMaxInVector(leaderboard) << std::endl;  // Output: Highest Score: 300
 */
template <typename T>
T FindMaxInVector(const std::vector<T>& vec)
{
	if (vec.empty())
	{
		throw std::invalid_argument("Vector is empty.");
	}

	T maxElement = vec[0];
	for (const auto& elem : vec)
	{
		if (elem > maxElement)
		{
			maxElement = elem;
		}
	}
	return maxElement;
}

/**
 * Example Usage:
 * std::vector<int> numbers = {1, 3, 7, 2};
 * std::cout << "Max: " << FindMaxInVector(numbers) << std::endl;  // Output: Max: 7
 *
 * std::vector<std::string> words = {"apple", "zebra", "banana"};
 * std::cout << "Max: " << FindMaxInVector(words) << std::endl;    // Output: Max: zebra
 */

/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */

/**
 * Glossary:
 * - Template: A C++ feature that allows writing generic code that works with multiple types.
 * - Specialization: A way to define custom behavior for specific types in a template.
 */

/**
 * Common Errors:
 * 1. Using different types in the same function call:
 *    GetMax(5, 3.14);  // Error: 'T' cannot deduce a common type
 *    Solution: Ensure both parameters have the same type, e.g., GetMax(5.0, 3.14);
 *
 * 2. Using an empty vector with FindMaxInVector:
 *    std::vector<int> emptyVec;
 *    FindMaxInVector(emptyVec);  // Error: Throws std::invalid_argument
 *    Solution: Check if the vector is empty before calling the function.
 */
