#include "Kr.h"
#include <iomanip>

book::book()
{
	price = 0;
	pages = 0;
}

bool book::operator<(const book base)
{
	return pages < base.pages;
}

std::istream& operator>>(std::istream& in, book& a)
{
	std::string line;
	std::getline(in, line);

	std::string subs[4];

	for (auto i = 0; i < 3; i++)
	{
		const auto pos = line.find(';');
		subs[i] = line.substr(0, pos);
		line.erase(0, pos + 1);
	}
	subs[3] = line;

	a.name = subs[0];
	a.author = subs[1];
	a.price = std::stoi(subs[2]);
	a.pages = std::stoi(subs[3]);

	return in;
}