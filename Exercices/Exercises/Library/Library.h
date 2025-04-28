#pragma once

#include <string>
#include <vector>

#include "Book.h"

/**
 * Exercise: Library Management System
 *
 * In this exercise, you will implement a simple library management system
 * using object-oriented programming principles. The system will manage a collection
 * of books, allowing operations such as adding books, borrowing them, and searching
 * for specific titles or authors.
 *
 * Requirements:
 * --------------
 * 1. **Class Name:** Library
 * 2. **Attributes (Private):**
 *    - A collection of books (e.g., `std::vector` or `std::unordered_map`).
 *
 * 3. **Class Book (Nested or Separate):**
 *    - Attributes:
 *      - `title` (std::string): The title of the book.
 *      - `author` (std::string): The name of the author.
 *      - `isBorrowed` (bool): True if the book is borrowed, false otherwise.
 *    - Methods:
 *      - Getters for the title and author.
 *      - A method to check if the book is borrowed.
 *
 * 4. **Public Methods in Library:**
 *    - `void AddBook(const std::string& title, const std::string& author)`
 *      - Adds a new book to the library.
 *      - If a book with the same title and author already exists, throw an exception.
 *
 *    - `void RemoveBook(const std::string& title, const std::string& author)`
 *      - Removes a book from the library.
 *      - If the book does not exist, throw an exception.
 *
 *    - `void BorrowBook(const std::string& title)`
 *      - Marks a book as borrowed.
 *      - If the book does not exist or is already borrowed, throw an exception.
 *
 *    - `void ReturnBook(const std::string& title)`
 *      - Marks a book as returned.
 *      - If the book does not exist or is not borrowed, throw an exception.
 *
 *    - `std::vector<std::string> SearchByTitle(const std::string& keyword)`
 *      - Returns a list of books whose titles contain the keyword (case-sensitive).
 *
 *    - `std::vector<std::string> SearchByAuthor(const std::string& author)`
 *      - Returns a list of books written by the specified author.
 *
 * Example Use Cases:
 * ------------------
 * 1. Adding books:
 *      Library lib;
 *      lib.AddBook("The Catcher in the Rye", "J.D. Salinger");
 *      lib.AddBook("To Kill a Mockingbird", "Harper Lee");
 *
 * 2. Borrowing and returning books:
 *      lib.BorrowBook("The Catcher in the Rye"); // Marks it as borrowed.
 *      lib.ReturnBook("The Catcher in the Rye"); // Marks it as available again.
 *
 * 3. Searching for books:
 *      lib.SearchByTitle("Mockingbird"); // Returns ["To Kill a Mockingbird"]
 *      lib.SearchByAuthor("J.D. Salinger"); // Returns ["The Catcher in the Rye"]
 *
 * 4. Error handling:
 *      - Borrowing a book that's already borrowed should throw an exception.
 *      - Adding a duplicate book should throw an exception.
 *      - Returning a book that's not borrowed should throw an exception.
 *
 * Tests:
 * ------
 * 1. Adding and removing books (valid and invalid cases).
 * 2. Borrowing and returning books (valid and invalid cases).
 * 3. Searching for books by title or author.
 * 4. Handling edge cases like empty library or multiple matching results.
 *
 * Notes:
 * ------
 * - Use exceptions to handle invalid operations.
 * - Write clean, modular, and reusable code following object-oriented principles.
 */

class Library
{
public:
	void AddBook(const std::string& title, const std::string& author);
	void RemoveBook(const std::string& title, const std::string& author);

	void BorrowBook(const std::string& title);
	void ReturnBook(const std::string& title);

	std::vector<std::string> SearchByTitle(const std::string& keyword) const;
	std::vector<std::string> SearchByAuthor(const std::string& author) const;

private:
	std::vector<Book> books;
};
