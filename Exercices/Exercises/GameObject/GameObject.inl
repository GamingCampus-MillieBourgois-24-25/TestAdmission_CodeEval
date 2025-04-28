#pragma once

template <typename T, typename... Args>
T* GameObject::CreateComponent(Args&&... args)
{
	return nullptr;
}

template <typename T>
T* GameObject::GetComponent() const
{
	return nullptr;
}

template <typename T>
bool GameObject::HasComponent() const
{
	return false;
}

template <typename T>
void GameObject::RemoveComponent()
{
}
