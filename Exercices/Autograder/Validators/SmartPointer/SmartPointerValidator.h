#pragma once

#include "Autograder/Core.h"
#include "Exercises/SmartPointer/SmartPointer.h"

class SmartPointerValidator : public Exercise<int, void>
{
public:
    static void Register()
    {
        TestRegistry::RegisterTest("SmartPointerValidator", []
        {
            return new SmartPointerValidator();
        });
    }

    SmartPointerValidator()
    {
        exerciseName = "SmartPointerValidator";
    }

protected:
    void ExecuteExercise(const int &testID) override;
    bool EvalInternal(const int &testID) override;

private:
    bool TestConstructorDestructor() const;
    bool TestDisplayGeneric() const;
    bool TestSpecializationInt() const;
    bool TestSpecializationString() const;
    bool TestMultipleSmartPointers() const;
};
