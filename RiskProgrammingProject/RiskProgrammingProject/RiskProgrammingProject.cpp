#include <iostream>
#include <vector>
using namespace std;

class Territory {
public:
	Territory(string initName) { name = initName; currentArmyCount = 0; }

	string getName() { return name; }
	void setName(string newName) { name = newName; }

	int getCurrentArmyCount() { return currentArmyCount; }
	void addArmies(int amount) { currentArmyCount += amount; }

	vector<Territory> getAdjacentTerritories() { return adjacentTerritories; }
	int getAdjacentCount() { return adjacentTerritories.size(); }

	void assignAdjacentTerritories(vector<Territory> initAdjacentTerritories) { 
		for (int i = 0; i < initAdjacentTerritories.size(); i++) {
			adjacentTerritories.push_back(initAdjacentTerritories.at(i));
		}
	}
private:
	string name;
	int currentArmyCount;
	vector<Territory> adjacentTerritories;
};

class Continent {
public:
	Continent(int initArmiesGiven, vector<Territory> initTerritories) { armiesGiven = initArmiesGiven; territories = initTerritories; }
	int getArmiesGiven() { return armiesGiven; }
	vector<Territory> getTerritories() { return territories; }
private:
	int armiesGiven;
	vector<Territory> territories;
};

int main() {
	Territory testTerritory1("India");
	Territory testTerritory2("China");
	Territory testTerritory3("Afghanistan");

	vector<Territory> terr1Adjacents{ testTerritory2, testTerritory3 };
	testTerritory1.assignAdjacentTerritories(terr1Adjacents);

	cout << "Adjacent territories to India: " << endl;
	for (int i = 0; i < testTerritory1.getAdjacentCount(); i++) {
		cout << testTerritory1.getAdjacentTerritories().at(i).getName() << ", ";
	}

	return 0;
}