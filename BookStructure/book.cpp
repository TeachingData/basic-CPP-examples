#include <iostream>
#include <array>
#include <vector>

struct book {
	std::string title{};
	int year{};
	double price{};
	std::string author{};
	std::array<std::string, 3> genre;
	std::array<std::string, 5> languages;
};
std::vector<book> books;


void print_books() {
	for (const auto b : books) {
		std::cout << "Title is " << b.title << "\n";
		// Assume rest of book printed here

		// print out genre
		for (const auto g : b.genre) {
			if (!g.empty()) {
				std::cout << "A genre is " << g << "\n";
			}
		}
	}
}

void add_book() {
	std::cout << "foo";
}

void change_title() {
	std::cout << "foo";
}