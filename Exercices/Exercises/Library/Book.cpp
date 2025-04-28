#include "Book.h"

Book::Book(const std::string& title, const std::string& author) {}

const std::string& Book::GetTitle() const
{
	return "";
}

const std::string& Book::GetAuthor() const
{
	return "";
}

bool Book::IsBorrowed() const
{
	return false;
}

void Book::Borrow() {}

void Book::Return() {}
