#pragma once
#include <string>

class Book
{
public:
	Book(const std::string& title, const std::string& author);

	const std::string& GetTitle() const;
	const std::string& GetAuthor() const;
	bool IsBorrowed() const;

	void Borrow();
	void Return();

private:
	std::string title;
	std::string author;
	bool isBorrowed;
};
