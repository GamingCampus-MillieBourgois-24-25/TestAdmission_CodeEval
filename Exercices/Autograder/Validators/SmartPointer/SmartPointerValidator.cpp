#include "SmartPointerValidator.h"
#include <sstream>

// Test the SmartPointer constructor and destructor
bool SmartPointerValidator::TestConstructorDestructor() const
{
	try
	{
		const SmartPointer<int> intPtr;
		*intPtr = 42;
		if (*intPtr == 42)
		{
			LogSuccess("SmartPointer<int> Constructor/Destructor", "Create/Destroy", "Success");
			return true;
		}
		LogFailure("SmartPointer<int> Constructor/Destructor", "42", std::to_string(*intPtr), "Incorrect value");
	}
	catch (const std::exception& e)
	{
		LogFailure("SmartPointer<int> Constructor/Destructor", "No exception", e.what(), "Unexpected exception");
	}
	return false;
}

// Test the generic Display method
bool SmartPointerValidator::TestDisplayGeneric() const
{
	try
	{
		const std::ostringstream output;
		const SmartPointer<double> doublePtr;
		*doublePtr = 3.14;

		std::streambuf* oldCout = std::cout.rdbuf(output.rdbuf());
		doublePtr.Display();
		std::cout.rdbuf(oldCout);

		if (output.str().find("Cannot display object") != std::string::npos)
		{
			LogSuccess("SmartPointer<double>::Display()", "Cannot display object", "Correct generic output");
			return true;
		}
		LogFailure("SmartPointer<double>::Display()", "Cannot display object", output.str(),
		           "Incorrect generic output");
	}
	catch (const std::exception& e)
	{
		LogFailure("SmartPointer<double>::Display()", "No exception", e.what(), "Unexpected exception");
	}
	return false;
}

// Test the specialization for int
bool SmartPointerValidator::TestSpecializationInt() const
{
	try
	{
		const std::ostringstream output;
		const SmartPointer<int> intPtr;
		*intPtr = 42;

		std::streambuf* oldCout = std::cout.rdbuf(output.rdbuf());
		intPtr.Display();
		std::cout.rdbuf(oldCout);

		if (output.str().find("Value = 42") != std::string::npos)
		{
			LogSuccess("SmartPointer<int>::Display()", "Value = 42", output.str(), "Correct specialization for int");
			return true;
		}
		LogFailure("SmartPointer<int>::Display()", "Value = 42", output.str(), "Incorrect specialization for int");
	}
	catch (const std::exception& e)
	{
		LogFailure("SmartPointer<int>::Display()", "No exception", e.what(), "Unexpected exception");
	}
	return false;
}

// Test the specialization for std::string
bool SmartPointerValidator::TestSpecializationString() const
{
	try
	{
		const std::ostringstream output;
		const SmartPointer<std::string> stringPtr;
		*stringPtr = "Hello, Templates!";

		std::streambuf* oldCout = std::cout.rdbuf(output.rdbuf());
		stringPtr.Display();
		std::cout.rdbuf(oldCout);

		if (output.str().find("Value = \"Hello, Templates!\"") != std::string::npos)
		{
			LogSuccess("SmartPointer<std::string>::Display()", "Value = \"Hello, Templates!\"", output.str(),
			           "Correct specialization for std::string");
			return true;
		}
		LogFailure("SmartPointer<std::string>::Display()", "Value = \"Hello, Templates!\"", output.str(),
		           "Incorrect specialization for std::string");
	}
	catch (const std::exception& e)
	{
		LogFailure("SmartPointer<std::string>::Display()", "No exception", e.what(), "Unexpected exception");
	}
	return false;
}

// Test multiple SmartPointers
bool SmartPointerValidator::TestMultipleSmartPointers() const
{
	try
	{
		const SmartPointer<int> ptr1;
		*ptr1 = 10;
		const SmartPointer<int> ptr2;
		*ptr2 = 20;

		if (*ptr1 == 10 && *ptr2 == 20)
		{
			LogSuccess("Multiple SmartPointers", "Managed independently", "Success");
			return true;
		}
		LogFailure("Multiple SmartPointers", "ptr1=10, ptr2=20", "Incorrect values");
	}
	catch (const std::exception& e)
	{
		LogFailure("Multiple SmartPointers", "No exception", e.what(), "Unexpected exception");
	}
	return false;
}

// Execute the test based on testID
void SmartPointerValidator::ExecuteExercise(const int& testID)
{
	EvalInternal(testID);
}

// Evaluate the tests
bool SmartPointerValidator::EvalInternal(const int& testID)
{
	switch (testID)
	{
	case 1:
		return TestConstructorDestructor();
	case 2:
		return TestDisplayGeneric();
	case 3:
		return TestSpecializationInt();
	case 4:
		return TestSpecializationString();
	case 5:
		return TestMultipleSmartPointers();
	default:
		LogFailure("SmartPointerValidator", "Valid testID", std::to_string(testID), "Invalid testID provided");
		return false;
	}
}
