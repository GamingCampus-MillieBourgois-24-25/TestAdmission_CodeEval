#pragma once

#include "Autograder/Core.h"
#include "Exercises/Library/Library.h"

class LibraryValidator : public Exercise<int, void>
{
public:
	static void Register()
	{
		TestRegistry::RegisterTest("LibraryValidator", []
		{
			return new LibraryValidator();
		});
	}

	LibraryValidator()
	{
		exerciseName = "LibraryValidator";
	}

protected:
	void ExecuteExercise(const int& _input) override {}
	bool EvalInternal(const int& _input) override;

private:
	bool TestAddAndRemoveBooks() const;
	bool TestBorrowAndReturnBooks() const;
	bool TestSearchByTitle() const;
	bool TestSearchByAuthor() const;
	bool TestInvalidOperations() const;
};
