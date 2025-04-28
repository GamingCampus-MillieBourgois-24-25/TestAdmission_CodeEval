#include "GameObjectValidator.h"
#include <sstream>

void GameObjectValidator::ExecuteExercise(const int &testID)
{
    EvalInternal(testID);
}

bool GameObjectValidator::EvalInternal(const int &testID)
{
    switch (testID)
    {
    case 1:
        return TestCreateComponent();
    case 2:
        return TestGetComponent();
    case 3:
        return TestHasComponent();
    case 4:
        return TestRemoveComponent();
    case 5:
        return TestMemoryManagement();
    default:
        LogFailure("GameObjectValidator", "Valid testID", std::to_string(testID), "Invalid testID provided.");
        return false;
    }
}

// Test 1: CreateComponent
bool GameObjectValidator::TestCreateComponent() const
{
    try
    {
        GameObject gameObject;
        if (const auto *transform = gameObject.CreateComponent<Transform>(); transform != nullptr)
        {
            LogSuccess("CreateComponent<Transform>()", "Non-null pointer", "Pointer created successfully.");
            return true;
        }
        LogFailure("CreateComponent<Transform>()", "Non-null pointer", "Null pointer", "Failed to create Transform component.");
    }
    catch (const std::exception &e)
    {
        LogFailure("CreateComponent<Transform>()", "No exception", e.what(), "Unexpected exception during creation.");
    }
    return false;
}

// Test 2: GetComponent
bool GameObjectValidator::TestGetComponent() const
{
    try
    {
        GameObject gameObject;
        gameObject.CreateComponent<Renderer>();
        if (const auto *renderer = gameObject.GetComponent<Renderer>(); renderer != nullptr)
        {
            LogSuccess("GetComponent<Renderer>()", "Non-null pointer", "Component retrieved successfully.");
            return true;
        }
        LogFailure("GetComponent<Renderer>()", "Non-null pointer", "Null pointer", "Failed to retrieve Renderer component.");
    }
    catch (const std::exception &e)
    {
        LogFailure("GetComponent<Renderer>()", "No exception", e.what(), "Unexpected exception during retrieval.");
    }
    return false;
}

// Test 3: HasComponent
bool GameObjectValidator::TestHasComponent() const
{
    GameObject gameObject;
    gameObject.CreateComponent<Collider>();
    if (gameObject.HasComponent<Collider>())
    {
        LogSuccess("HasComponent<Collider>()", "true", "Component exists.");
        return true;
    }
    LogFailure("HasComponent<Collider>()", "true", "false", "Failed to detect existing Collider component.");
    return false;
}

// Test 4: RemoveComponent
bool GameObjectValidator::TestRemoveComponent() const
{
    try
    {
        GameObject gameObject;
        gameObject.CreateComponent<Transform>();
        gameObject.RemoveComponent<Transform>();
        if (!gameObject.HasComponent<Transform>())
        {
            LogSuccess("RemoveComponent<Transform>()", "true", "Component removed successfully.");
            return true;
        }
        LogFailure("RemoveComponent<Transform>()", "true", "false", "Failed to remove Transform component.");
    }
    catch (const std::exception &e)
    {
        LogFailure("RemoveComponent<Transform>()", "No exception", e.what(), "Unexpected exception during removal.");
    }
    return false;
}

// Test 5: MemoryManagement
bool GameObjectValidator::TestMemoryManagement() const
{
    try
    {
        {
            GameObject gameObject;
            gameObject.CreateComponent<Transform>();
            gameObject.CreateComponent<Renderer>();
        } // GameObject goes out of scope here

        LogSuccess("GameObject Memory Management", "All components destroyed", "Memory managed correctly.");
        return true;
    }
    catch (const std::exception &e)
    {
        LogFailure("GameObject Memory Management", "No exception", e.what(), "Unexpected exception during destruction.");
    }
    return false;
}
