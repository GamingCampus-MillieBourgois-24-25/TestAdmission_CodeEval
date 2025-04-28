#pragma once

#include "Autograder/Core.h"
#include "Exercises/GameObject/GameObject.h"

class GameObjectValidator : public Exercise<int, void>
{
public:
    static void Register()
    {
        TestRegistry::RegisterTest("GameObjectValidator", []
        {
            return new GameObjectValidator();
        });
    }

    GameObjectValidator()
    {
        exerciseName = "GameObjectValidator";
    }

protected:
    void ExecuteExercise(const int &testID) override;
    bool EvalInternal(const int &testID) override;

private:
    bool TestCreateComponent() const;
    bool TestGetComponent() const;
    bool TestHasComponent() const;
    bool TestRemoveComponent() const;
    bool TestMemoryManagement() const;
};
