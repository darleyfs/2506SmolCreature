#pragma once
#include <string>
#include "Type.h"

class Move {
	std::string name;
	int power;
	float accuracy;
	int pp;
	Type type;


public:
	Move() {
		name = "";
		power = -1;
		accuracy = -1.0f;
		pp = -1;
		type = Type::NONE;
	}

	Move(std::string _name, int _power, float _accuracy, int _pp, Type _type) {
		name = _name;
		power = _power;
		accuracy = _accuracy;
		pp = _pp;
		type = _type;
	}

	std::string GetName() {
		return name;
	}

	int GetPower() {
		return power;
	}

	float GetAccuracy() {
		return accuracy;
	}

	int GetPp() {
		return pp;
	}

	Type GetType() {
		return type;
	}

};