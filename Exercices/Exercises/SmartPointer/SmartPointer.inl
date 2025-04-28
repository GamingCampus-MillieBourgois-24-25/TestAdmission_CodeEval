#pragma once

/** !! NO #include "SmartPointer.h" here !! **/

#include <string>

template <typename T>
SmartPointer<T>::SmartPointer()
{
}

template <typename T>
SmartPointer<T>::~SmartPointer()
{
}

template <typename T>
T* SmartPointer<T>::Get() const
{
	return nullptr;
}

template <typename T>
T& SmartPointer<T>::operator*() const
{
	/** Intentionally erroneous code to allow compilation, return the correct value in the final implementation **/
	T var;
	return var;
	/** Intentionally erroneous code to allow compilation, return the correct value in the final implementation **/
}

template <typename T>
T* SmartPointer<T>::operator->() const
{
	return nullptr;
}

template <typename T>
void SmartPointer<T>::Display() const
{
}

inline void SmartPointer<int>::Display() const
{
}

inline void SmartPointer<std::string>::Display() const
{
}
