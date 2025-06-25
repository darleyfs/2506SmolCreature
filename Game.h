#pragma once
#include "Handler.h"
#include "Events.h"

class Game {
	Handler player;
	Handler rival;

public:
	Game() {
		player = Handler();
		rival = Handler();
	}

	Game(Handler _player, Handler _rival) {
		player = _player;
		rival = _rival;
	}

	Handler GetPlayer() {
		return player;
	}

	Handler GetRival() {
		return rival;
	}

	void SetPlayer(Handler _player) {
		player = _player;
	}

	void SetRival(Handler _rival) {
		rival = _rival;
	}

	void Start() {
		// Call a series of Events
		Events::Intro(player, rival);
		Events::WakeUp(player.GetName());
		Events::TouchGrass(player.GetName());
		Events::SmolCreatureLab();
	}
};