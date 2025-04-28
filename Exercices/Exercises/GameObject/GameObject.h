#pragma once

#include <vector>

#include "Component.h"

/**
 * @brief GameObject with Components Template Exercise
 *
 * In this exercise, you will implement a basic version of a 'GameObject' class
 * that manages a collection of 'Component' objects. Components are added to or
 * retrieved from the GameObject dynamically, and the use of templates will allow
 * type-safe interactions with these components.
 *
 * Objectives:
 * 1. Implement a 'GameObject' class that manages a vector of 'Component*'.
 * 2. Create functions to:
 *    - Add a new component of type 'T' ('CreateComponent<T>()').
 *    - Retrieve a component of type 'T' ('GetComponent<T>()').
 *    - Check if a component of type 'T' exists ('HasComponent<T>()').
 * 3. Use templates to enforce type safety and minimize casting.
 * 4. Prevent duplicate components of the same type within a single GameObject.
 * 5. Ensure proper handling of multiple component types and interactions.
 *
 * Your Tasks:
 * 1. Complete the 'CreateComponent<T>()' method to dynamically allocate and
 *    store a new component of type 'T'.
 * 2. Implement the 'GetComponent<T>()' method to return a pointer to a component
 *    of type 'T' if it exists, or throw an exception if it doesn't.
 * 3. Implement the 'HasComponent<T>()' method to check if a component of type 'T'
 *    exists in the GameObject.
 * 4. Add proper destruction logic in the 'GameObject' destructor to ensure all
 *    components are deleted.
 * 5. Implement functionality to remove a component of type 'T' ('RemoveComponent<T>()').
 *
 * Important Notes:
 * - Templates are used here to allow the GameObject to interact with different
 *   types of components without hardcoding specific types.
 * - Variadic templates (Args&&... args) allow passing any number of arguments
 *   to the constructor of the component. These are forwarded using 'std::forward'
 *   to construct the component in place.
 * - Each component type must inherit from the base 'Component' class to be managed
 *   properly.
 * - You will write these methods in a '.h' and corresponding '.inl' file.
 * - Test cases will validate the behavior of component management.
 */

class GameObject
{
public:
	GameObject() = default;
	~GameObject();

	template <typename T, typename... Args>
	T* CreateComponent(Args&&... args);

	template <typename T>
	T* GetComponent() const;

	template <typename T>
	bool HasComponent() const;

	template <typename T>
	void RemoveComponent();

private:
	std::vector<Component*> components;
};

#include "GameObject.inl"
