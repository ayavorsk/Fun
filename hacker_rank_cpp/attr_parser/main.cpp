#include <cmath>
#include <cstdio>
#include <vector>
#include <list>
#include <map>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

struct s_tag
{
	string name;
	map<string, string> attrs;
	int level;
};

class Tag
{
public:
	Tag();
	void readInput();
	void printInput();
	void processRequests();
private:
	int _lines;
	int _requests;
	vector <s_tag> input;
	void addAttrs(s_tag& curTag, stringstream& ss);
	s_tag* findTagByName(string const& name, int level);
};

Tag::Tag()
{
	string str;
	getline(cin, str);
	stringstream ss;
	ss.str(str);
	ss >> _lines >> _requests;
}

void Tag::readInput()
{
	int level = 0;
	for (int i = 0; i < _lines; i++)
	{
		string line;
		getline(cin, line);

		if (line[1] == '/')
			level--;
		else
		{
			s_tag curTag;
			stringstream ss;
			ss.str(line.substr(1, line.size()-2));
			ss >> curTag.name;
			addAttrs(curTag, ss);
			curTag.level = level;
			input.push_back(curTag);
			level++;
		}
	}
}

void Tag::printInput()
{
	for (auto it : input)
	{
		cout << it.name << '*' << it.level << endl;
		for (auto tt : it.attrs)
			cout << tt.first << '=' << tt.second << endl;
	}
}

void Tag::addAttrs(s_tag& curTag, stringstream& ss)
{
	string key, value;
	while (ss)
	{
		ss >> key >> value >> value;
		curTag.attrs.insert(pair<string, string>(key, value));
	}
}

void Tag::processRequests()
{
	for (int j = 0; j < _requests; j++)
	{
		string line;
		getline(cin, line);
		int begin = 0, level = 0, i = 0;
		s_tag* myTag = NULL;
		myTag = NULL;
		while (1)
		{
			begin = i;
			while (line[i] && line[i] != '.' && line[i] != '~')
				i++;
			if (line[i] == '.')
			{
				string nameOfTag;
				nameOfTag = line.substr(begin, i - begin);
				myTag = findTagByName(nameOfTag, level);
				if (myTag == NULL)
				{
					cout << "Not Found!" << endl;
					break ;
				}
				level++;
				i++;
			}
			else if (line[i] == '~')
			{
				string nameOfTag;
				nameOfTag = line.substr(begin, i - begin);
				myTag = findTagByName(nameOfTag, level);
				if (myTag == NULL)
				{
					cout << "Not Found!" << endl;
					break ;
				}
				string nameOfKey = line.substr(i+1);
				map<string, string>::iterator it = myTag->attrs.find(nameOfKey);
				if (it == myTag->attrs.end())
					cout << "Not Found!" << endl;
				else
					cout << it->second.substr(1, it->second.size()-2) << endl;
				break;
			}
			else
				break ;
		}
	}
}

s_tag* Tag::findTagByName(string const& name, int level)
{
	vector<s_tag>::iterator it = input.begin();
	while (it != input.end())
	{
		if ((*it).name == name && (*it).level == level)
			return &(*it);
		it++;
	}
	return NULL;
}

int main()
{
	Tag tag;
	tag.readInput();
	tag.processRequests();
	return 0;
}
