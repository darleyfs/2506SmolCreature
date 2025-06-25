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
	
    static int CheckEffectiveness(Type defenderType, Move move) {

        int modifier = 10;

        switch (defenderType)
        {
        case Type::NORMAL:
            if (move.GetType() == Type::FIGHTING)
            {
                modifier = 20;
            }

            if (move.GetType() == Type::GHOST)
            {
                modifier = 0;
            }

            break;
        case Type::FIRE:
            if (move.GetType() == Type::FIRE || move.GetType() == Type::GRASS || move.GetType() == Type::BUG)
            {
                modifier = 5;
            }

            if (move.GetType() == Type::WATER || move.GetType() == Type::GROUND || move.GetType() == Type::ROCK) {
                modifier = 20;
            }

            break;
        case Type::WATER:
            if (move.GetType() == Type::FIRE || move.GetType() == Type::WATER || move.GetType() == Type::ICE)
            {
                modifier = 5;
            }

            if (move.GetType() == Type::ELECTRIC || move.GetType() == Type::GRASS)
            {
                modifier = 20;
            }
            break;
        case Type::ELECTRIC:
            if (move.GetType() == Type::ELECTRIC || move.GetType() == Type::FLYING)
            {
                modifier = 5;
            }

            if (move.GetType() == Type::GROUND)
            {
                modifier = 20;
            }

            break;
        case Type::GRASS:
            if (move.GetType() == Type::WATER || move.GetType() == Type::ELECTRIC || move.GetType() == Type::GRASS || move.GetType() == Type::GROUND)
            {
                modifier = 5;
            }

            if (move.GetType() == Type::FIRE || move.GetType() == Type::ICE || move.GetType() == Type::POISON || move.GetType() == Type::FLYING || move.GetType() == Type::BUG)
            {
                modifier = 20;
            }
            break;
        }

        return modifier;
    }
};