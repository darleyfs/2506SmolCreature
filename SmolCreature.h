#pragma once

#include <string>
#include <vector>
#include "Move.h"

class SmolCreature {
	std::string name;
	int attack;
	int defense;
	int special;
	int currentHp;
	int maxHp;
	int level;
	Type type1;
	Type type2;
	std::vector<Move> moves;

public:
	SmolCreature() {
		name = "";
		level = -1;
		attack = -1;
		defense = -1;
		special = -1;
		currentHp = -1;
		maxHp = -1;
		level = -1;
		type1 = Type::NONE;
		type2 = Type::NONE;
		moves = std::vector<Move>(4);
	}

	SmolCreature(std::string _name, int _level, int _attack, int _defense, int _special,
		int _currentHp, int _maxHp, Type _type1, Type _type2, std::vector<Move> _moves) {
		name = _name;
		level = _level;
		attack = _attack;
		defense = _defense;
		special = _special;
		currentHp = _currentHp;
		maxHp = _maxHp;
		type1 = _type1;
		type2 = _type2;
		moves = _moves;
	}

	std::string GetName() {
		return name;
	}

	int GetLevel() {
		return level;
	}

	Type GetType1() {
		return type1;
	}

	Type GetType2() {
		return type2;
	}

	bool LearnMove(Move move) {
		bool result = false;

		for (int i = 0; i < moves.size(); i++) {
			Move currentMove = moves[i];

			if (currentMove.GetType() == Type::NONE) {
				moves[i] = move;
				
				result = true;

				break;
			}
		}

		return result;
	}

	bool ForgetMove(std::string name) {
		bool result = false;

		for (int i = 0; i < moves.size(); i++) {
			Move currentMove = moves[i];

			if (currentMove.GetName() == name) {
				moves[i] = Move();
			
				result = true;

				break;
			}
		}

		return result;
	}
};