#pragma once
#include <string>
#include "Type.h"

class Move {
	std::string name;
	int power;
	float accuracy;
	Type type;

public:
	Move() {
		name = "";
		power = -1;
		accuracy = -1.0f;
		type = Type::NONE;
	}

	Move(std::string _name, int _power, float _accuracy, Type _type) {
		name = _name;
		power = _power;
		accuracy = _accuracy;
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

	Type GetType() {
		return type;
	}

};