#pragma once

/**
 * @brief SmartPointer Template Exercise
 *
 * In this exercise, you will implement a simplified version of a SmartPointer in C++.
 * The goal is to learn how to use templates and specialize behavior for specific types.
 *
 * Objectives:
 * 1. Implement the SmartPointer template class to manage a dynamically created object.
 * 2. Ensure proper memory management (allocate with new and deallocate with delete).
 * 3. Overload the `Display()` method for specific types like `int` and `std::string`.
 * 4. Prevent copying of SmartPointer instances.
 * 5. Implement partial specializations for `Display()` in a corresponding `.inl` file.
 *
 * Important Notes:
 * - Template implementations must reside in the `.h` or `.inl` file. This is because templates
 *   are instantiated during compilation, and their definitions must be available wherever they
 *   are used.
 * - You will provide the partial specializations for `Display()` in the `.inl` file. Keeping them
 *   inline ensures they are included wherever the template is instantiated, while maintaining
 *   a separation of concerns for better organization.
 *
 * Your Tasks:
 * 1. Complete the constructor and destructor to handle the creation and deletion of the object.
 * 2. Implement the generic `Display()` method.
 * 3. Add partial specializations of `Display()` for `int` and `std::string` in the `.inl` file.
 */


template <typename T>
class SmartPointer
{
public:
	// Constructor: Create a new object (with new)
	SmartPointer();

	// Destructor: Delete the managed object (with delete)
	~SmartPointer();

	// Access the underlying pointer
	T* Get() const;

	// Overload dereference operator (return reference to the object)
	T& operator*() const;

	// Overload arrow operator (return pointer to the object)
	T* operator->() const;

	// Display: Generic version (to be specialized for specific types)
	void Display() const;

	// Delete copy constructor and assignment operator
	SmartPointer(const SmartPointer&) = delete;
	SmartPointer& operator=(const SmartPointer&) = delete;

private:
	T* ptr; // Managed pointer
};

#include "SmartPointer.inl"