#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

template <class T>
std::ostream &operator <<(std::ostream &os, const std::vector<T> vector);

std::vector<std::string> getLongestStrings(std::vector<std::string> input);

int main()
{

	std::vector<std::string> input = { "aa", "aaaaaaa", "b", "b", "bbbbb" };

	std::vector<std::string> output = getLongestStrings(input);
	std::cout << output;
	return 0;
}

std::vector<std::string> getLongestStrings(std::vector<std::string> input)
{

	std::map<char, std::string> LongestCharacterStrings;
	std::vector<std::string> output;

	for (unsigned int i = 0; i < input.size(); i++)
		if (LongestCharacterStrings.find(input[i][0]) == LongestCharacterStrings.end())
			LongestCharacterStrings[input[i][0]] = input[i][0];
		else if (input[i].length() > LongestCharacterStrings[input[i][0]].length())
			LongestCharacterStrings[input[i][0]] = input[i];

	for (auto it = LongestCharacterStrings.begin(); it != LongestCharacterStrings.end(); ++it)
		output.push_back(it->second + "->" + std::to_string(it->second.length()));

	std::sort(output.begin(), output.end(), [](const std::string &a, const std::string &b) { return a[0] < b[0]; });

	return output;
}

template <class T>
std::ostream &operator <<(std::ostream &os, const std::vector<T> vector)
{
	os << "[";
	for (unsigned int i = 0; i < vector.size() - 1; i++)
		os << vector[i] << ", ";

	os << vector[vector.size() - 1] << "]";

	return os;
}