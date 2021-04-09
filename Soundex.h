#pragma once
#include "pch.h"
using namespace std;

static const size_t MaxCodeLength{ 4 };

class Soundex
{
	static const unordered_map<char, char> ConsonantsBook; 
	static const unordered_set<char> SpecialBook;
public:
	string encode(const string& word) const
	{
		// first letter
		char head = word.front();
		// Drop some special char
		string noSpecial = drop(string(next(word.begin()), word.end()));		
		// Replace char by Appropriate Digit
		auto digits = replace(noSpecial);
		// Pad with zero
		return zeroPad(head + digits);
	}
private:
	string replace(const string& word) const
	{
		string digits;
		for (char c : word)
			if (ConsonantsBook.find(c) != ConsonantsBook.end())
			{
				if (!digits.empty() && ConsonantsBook.at(c) == digits.back()) continue;
				digits += ConsonantsBook.at(c);
			}
		return digits;
	}
	string drop(const string& word) const
	{
		string res;
		for (char c : word)
			if (SpecialBook.find(c) == SpecialBook.end())
				res += c;
		return res;
	}
	string zeroPad(const string& word) const
	{
		size_t size = word.size();
		return  size < MaxCodeLength ? word + string(MaxCodeLength -size, '0') : string(word.begin(), word.begin()+ MaxCodeLength);
	}
};
const unordered_set<char> Soundex::SpecialBook{ 'a', 'e', 'i', 'o', 'u', 'y', 'h', 'w' };
const unordered_map<char, char> Soundex::ConsonantsBook{ {'b', '1'}, { 'f','1' }, { 'p','1' }, { 'v','1' },
									{'c','2'}, {'g','2'}, {'j','2'}, {'k','2'},{'q','2'}, {'s','2'}, {'x','2'},  {'z','2'},
									{'d','3'}, {'t','3'}, {'n','5'},
									{'l','4'}, {'m','5'}, {'r','6'}
};