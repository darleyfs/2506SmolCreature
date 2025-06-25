#pragma once

#include "SmolCreature.h";
#include <vector>

class Handler {
	std::string name;
	std::vector<SmolCreature> team;

public:
	Handler() // default
	{
		name = "";
		team = std::vector<SmolCreature>(6);
	}

	// overloaded constructor
	Handler(std::string _name, std::vector<SmolCreature> _team) {
		name = _name;
		team = _team;
	}

	std::string GetName() {
		return name;
	}

	std::vector<SmolCreature> GetTeam() {
		return team;
	}

	SmolCreature GetCreatureAtPosition(int position) {
		return team[position];
	}

	void SetName(std::string _name) {
		if (_name != "") {
			name = _name;
		}
	}

	bool AddSmolCreatureToTeam(SmolCreature creature) {

		// Initialize a placeholder variable
		bool result = false;

		// Iterate through the team of SmolCreature
		for (int i = 0; i < team.size(); i++) {
			// Pull out a "current" creature
			SmolCreature currentCreature = team[i];

			// See if it's a default creature
			if (currentCreature.GetType1() == Type::NONE) {
				// Store creature in team member field
				team[i] = creature;
				
				// Set result to true
				result = true;
				
				// Stop looking for additional spot
				break;
			}
		}

		// Return the result 
		return result;
	}

	bool RemoveSmolCreature(std::string name) {

		bool result = false;

		for (int i = 0; i < team.size(); i++) {
			SmolCreature creature = team[i];

			if (creature.GetName() == name) {
				team[i] = SmolCreature();

				result = true;

				break;
			}
		}

		return result;
	}
};