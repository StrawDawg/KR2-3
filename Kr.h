#pragma once
#include <vector>
#include <algorithm>
#include <string>

class book
{
public:
	std::string name;
	std::string author;
	int price;
	int pages;

	book();
	~book() = default;
	bool operator < (const book base);
	friend std::istream& operator>>(std::istream& in, book& obj);
};

template<typename T>
class my_class
{
	std::vector<T> objects_list;
public:
	my_class() = default;
	my_class(my_class const&) = delete;
	my_class(my_class &&) = delete;



	T& operator[](int index)
	{
		return objects_list[index];
	}

	friend std::ostream& operator<<(std::ostream& out, T const& object)
	{
		for (int i = 0; i < object.objects_list.size(); i++)
			out << object.objects_list[i];
		return out;
	}

	friend std::istream& operator>>(std::istream& in, T& object)
	{
		std::string temp;

		std::getline(in, temp);

		if (!temp.empty())
		{
			object.objects_list.push_back(T(temp));
		}
		return in;
	}

	std::vector<T> compare_name(std::string const& str)
	{
		typename std::vector<T>::iterator temp = std::find_if(objects_list.begin(), objects_list.end(), [&str](T const& c)
		{
			int len1 = c.name.length(), len2 = str.length();
			int min_len = len1 <= len2 ? len1 : len2;

			return c.name.substr(0, min_len) == str.substr(0, min_len);
		});

		std::vector<T> found_obj;

		while (temp != objects_list.end())
		{
			found_obj.push_back(*temp);

			temp = std::find_if(++temp, objects_list.end(), [&str](T const& c)
			{
				int len1 = c.name.length(), len2 = str.length();
				int min_len = len1 <= len2 ? len1 : len2;

				return c.name.substr(0, min_len) == str.substr(0, min_len);
			});
		}

		return found_obj;
	}

	void sort_()
	{
		std::sort(objects_list.begin(), objects_list.end(), [](T c1, T c2) -> bool
		{
			return c1 < c2;
		});
	}
};