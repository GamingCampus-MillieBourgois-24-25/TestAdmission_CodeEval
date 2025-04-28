#include "Library.h"

void Library::AddBook(const std::string& title, const std::string& author) {}

void Library::RemoveBook(const std::string& title, const std::string& author) {}

void Library::BorrowBook(const std::string& title) {}

void Library::ReturnBook(const std::string& title) {}

std::vector<std::string> Library::SearchByTitle(const std::string& keyword) const
{
	return {};
}

std::vector<std::string> Library::SearchByAuthor(const std::string& author) const
{
	return {};
}
