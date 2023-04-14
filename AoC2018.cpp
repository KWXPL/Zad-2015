#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>

using namespace std;

class house 
{
	public:
	int x = 0;
	int y = 0;

	house(int _x, int _y) : x(_x), y(_y) {}

	bool operator==(const house& other) const 
	{
		return (x == other.x && y == other.y);
	}
};

struct hasz
{
	size_t operator()(const house& obj) const
	{
		size_t h = 0;
		hash<int> hashX;
		hash<int> hashY;
		h ^= hashX(obj.x);
		h ^= hashY(obj.y);
		return h;
	}
};

int main()
{
	int x = 0;
	int y = 0;
	ifstream input{"Dane.txt"};
	vector<char> inputData;
	unordered_set<house, hasz> houses;
	char data;
	cout << "Start programu\n";
	while (input >> data)
	{
		inputData.push_back(data);
	}
	cout << "Wielkosc danych wejsciowych " << inputData.size() << "\n";
	houses.insert(house(x, y));
	for (int i = 0; i < inputData.size(); i++)
	{
		switch (inputData[i])
		{
		case '<':
			x--;
			houses.insert(house(x, y));
			cout << "< : " <<  houses.size() << "\n";
			break;
		case '>':
			x++;
			houses.insert(house(x, y));
			cout << "> : " <<  houses.size() << "\n";
			break;
		case '^':
			y++;
			houses.insert(house(x, y));
			cout << "^ : " <<  houses.size() << "\n";
			break;
		case 'v':
			y--;
			houses.insert(house(x, y));
			cout << "V : " <<  houses.size() << "\n";
			break;
		default:
			break;
		}
	}
	cout << "Ilosc domow: " << houses.size() << "\n";
}
