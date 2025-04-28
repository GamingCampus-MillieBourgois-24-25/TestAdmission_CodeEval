#include "LibraryValidator.h"
#include "Exercises/Library/Library.h"

bool LibraryValidator::EvalInternal(const int& _input)
{
	switch (_input)
	{
	case 1:
		return TestAddAndRemoveBooks();
	case 2:
		return TestBorrowAndReturnBooks();
	case 3:
		return TestSearchByTitle();
	case 4:
		return TestSearchByAuthor();
	case 5:
		return TestInvalidOperations();
	default:
		LogFailure(std::to_string(_input), "1-5", "Invalid test ID", "No matching test for the provided input.");
		return false;
	}
}

bool LibraryValidator::TestAddAndRemoveBooks() const
{
	bool success = true;

	try
	{
		Library library;
		library.AddBook("1984", "George Orwell");
		library.AddBook("Brave New World", "Aldous Huxley");

		auto search_result = library.SearchByTitle("1984");
		if (!search_result.empty() && search_result[0] == "1984")
		{
			LogSuccess("AddBook(1984, Orwell)", "1984", search_result[0], "Book added successfully.");
		}
		else
		{
			LogFailure("AddBook(1984, Orwell)", "1984", "Not found", "Failed to add the book.");
			success = false;
		}

		library.RemoveBook("1984", "George Orwell");
		search_result = library.SearchByTitle("1984");
		if (search_result.empty())
		{
			LogSuccess("RemoveBook(1984, Orwell)", "No result", "No result", "Book removed successfully.");
		}
		else
		{
			LogFailure("RemoveBook(1984, Orwell)", "No result", "Found", "Failed to remove the book.");
			success = false;
		}
	}
	catch (const std::exception& e)
	{
		LogFailure("TestAddAndRemoveBooks", "No exceptions", e.what(), "Unexpected exception thrown.");
		success = false;
	}

	return success;
}

bool LibraryValidator::TestBorrowAndReturnBooks() const
{
	Library library;
	bool success = true;

	library.AddBook("Dune", "Frank Herbert");

	try
	{
		library.BorrowBook("Dune");
		if (const std::string is_borrowed = library.SearchByTitle("Dune")[0]; is_borrowed == "Dune")
		{
			LogSuccess("BorrowBook(Dune)", "Borrowed", "Borrowed", "Book borrowed successfully.");
		}
		else
		{
			LogFailure("BorrowBook(Dune)", "Borrowed", "Available", "Book was not marked as borrowed.");
			success = false;
		}

		library.ReturnBook("Dune");
		LogSuccess("ReturnBook(Dune)", "Returned", "Returned", "Book returned successfully.");
	}
	catch (const std::exception& e)
	{
		LogFailure("TestBorrowAndReturnBooks", "No exceptions", e.what(), "Unexpected exception thrown.");
		success = false;
	}

	return success;
}

bool LibraryValidator::TestSearchByTitle() const
{
	Library library;
	bool success = true;

	library.AddBook("The Hobbit", "J.R.R. Tolkien");
	library.AddBook("The Lord of the Rings", "J.R.R. Tolkien");

	if (const std::vector<std::string> results = library.SearchByTitle("The"); results.size() == 2 && results[0] == "The Hobbit" && results[1] == "The Lord of the Rings")
	{
		LogSuccess("SearchByTitle(The)", "[The Hobbit, The Lord of the Rings]", "Correct results", "Title search succeeded.");
	}
	else
	{
		LogFailure("SearchByTitle(The)", "[The Hobbit, The Lord of the Rings]", "Incorrect results", "Title search failed.");
		success = false;
	}

	return success;
}

bool LibraryValidator::TestSearchByAuthor() const
{
	Library library;
	bool success = true;

	library.AddBook("Pride and Prejudice", "Jane Austen");
	library.AddBook("Sense and Sensibility", "Jane Austen");

	if (const std::vector<std::string> results = library.SearchByAuthor("Jane Austen"); results.size() == 2 && results[0] == "Pride and Prejudice" && results[1] == "Sense and Sensibility")
	{
		LogSuccess("SearchByAuthor(Jane Austen)", "[Pride and Prejudice, Sense and Sensibility]", "Correct results", "Author search succeeded.");
	}
	else
	{
		LogFailure("SearchByAuthor(Jane Austen)", "[Pride and Prejudice, Sense and Sensibility]", "Incorrect results", "Author search failed.");
		success = false;
	}

	return success;
}

bool LibraryValidator::TestInvalidOperations() const
{
	Library library;
	bool success = true;

	try
	{
		library.BorrowBook("Nonexistent Book");
		LogFailure("BorrowBook(Nonexistent Book)", "Exception", "No exception", "Borrowing a nonexistent book did not throw.");
		success = false;
	}
	catch (const std::exception&)
	{
		LogSuccess("BorrowBook(Nonexistent Book)", "Exception", "Exception", "Borrowing a nonexistent book threw as expected.");
	}

	try
	{
		library.ReturnBook("Nonexistent Book");
		LogFailure("ReturnBook(Nonexistent Book)", "Exception", "No exception", "Returning a nonexistent book did not throw.");
		success = false;
	}
	catch (const std::exception&)
	{
		LogSuccess("ReturnBook(Nonexistent Book)", "Exception", "Exception", "Returning a nonexistent book threw as expected.");
	}

	return success;
}
