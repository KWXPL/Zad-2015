#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>

using namespace std;

class House 
{
	public:
	int x = 0;
	int y = 0;

	House(int _x, int _y) : x(_x), y(_y) {}

	bool operator==(const House& other) const 
	{
		return (x == other.x && y == other.y);
	}
};

class Santa
{
	public:
	int x = 0;
	int y = 0;

	void calculate(char data)
	{
		switch (data)
		{
		case '<':
			x--;
			break;
		case '>':
			x++;
			break;
		case '^':
			y++;
			break;
		case 'v':
			y--;
			break;
		default:
			break;
		}
	}
};

struct hasz
{
	size_t operator()(const House& obj) const
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
	int numberOfHouses = 0;
	char data;
	vector<char> inputData;

	Santa santa;
	Santa robo;

	unordered_set<House, hasz> houses;
	
	ifstream input{"Dane.txt"};
	
	while (input >> data)
	{
		inputData.push_back(data);
	}
	houses.insert(House(0, 0));
	for (int i = 0; i < inputData.size(); i++)
	{
		if(i % 2 ==0)
		{
			santa.calculate(inputData[i]);
			houses.insert(House(santa.x, santa.y));
		} 
		else 
		{
			robo.calculate(inputData[i]);
			houses.insert(House(robo.x, robo.y));
		}
	}
	numberOfHouses = houses.size();
	cout << "Ilosc domow: " << numberOfHouses << "\n";
	return 0;
}
