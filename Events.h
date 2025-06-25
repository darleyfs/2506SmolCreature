#pragma once
#include "UI.h"
#include "Handler.h"
#include "Move.h"

class Events {
public:
	static void Intro(Handler& player, Handler& rival) {
		UI::ShowMessageBox("MAPLE", "Welcome to the Wonderful World of Smol Creatures!");
		UI::ShowMessageBox("MAPLE", "In this world, we catch smol creatures and make them fight!");
		UI::ShowMessageBox("MAPLE", "What's your name, trainer?");
		
		std::string playerName = UI::PromptUser("Name");
		player.SetName(playerName);

		UI::ShowMessageBox("MAPLE", "Welcome, " + playerName + "!");
				
		UI::ShowMessageBox("MAPLE", "Your lifelong bul-...friend is also my grandson!");
		UI::ShowMessageBox("MAPLE", "The family doesn't really like him, so I forgot his name...");
		UI::ShowMessageBox("MAPLE", "What WAS his name again?");

		std::string rivalName = UI::PromptUser("Rival Name");
		rival.SetName(rivalName);
	}

	static void WakeUp(std::string playerName) {
		UI::ShowMessageBox(playerName + " wake up in their room!");

		// ================================

		// Initialize variables
		std::string userInput = "";
		int choice = 0;

		do {
			// Clear the screen before display new text
			system("CLS");

			std::vector<std::string> menuOptions = {
				"Go back to sleep",
				"Play video games",
				"Touch some grass"
			};

			UI::DisplayMenu("What do you want to do with your day??", menuOptions);

			// Prompt the user
			std::cout << "\n" << "  " << "Choice: ";

			// Capture input
			getline(std::cin, userInput);

			// Convert provided input into an integer
			choice = std::stoi(userInput);


			switch (choice) {
			case 1:
				UI::ShowMessageBox(playerName + " decides to go back to sleep.\n  Today just ain't the day.");
				break;
			case 2:
				UI::ShowMessageBox(playerName + " decides to play video games all day.");
				break;
			case 3:
				UI::ShowMessageBox(playerName + " decides to go outside and touch some grass maybe.");
				break;
			default:
				std::cout << "  Invalid choice. Please try again!" << std::endl;
				std::cin.get();
				break;
			}
		} while (choice != 3);
	}

	static void TouchGrass(std::string playerName) {

		UI::ShowMessageBox(playerName + " heads outside and wanders around a bit.");

		std::string input = "";
		int menuChoice = 0;

		do {
			system("CLS");

			UI::ShowMessageBox(playerName
				+ " stops briefly at a small patch of tall grass\n  at the entrance of town.");

			std::vector<std::string> menuOptions = {
				"Touch grass",
				"Not quite yet..."
			};

			UI::DisplayMenu("Do you want to touch grass?", menuOptions);

			std::cout << "  Choice: ";
			getline(std::cin, input);

			menuChoice = std::stoi(input);

			switch (menuChoice) {
			case 1:
				UI::ShowMessageBox("MAPLE", "WHAT THE *&$% ARE YOU DOING?!!");
				UI::ShowMessageBox("MAPLE", "You can't just go out touching grass like that!");
				break;
			case 2:
				UI::ShowMessageBox(playerName + " just scrubbed their shoes, and really\n  isn't feelin' grass right now.");
				break;
			default:
				std::cout << "  Invalid choice. Please try again!" << std::endl;
				std::cin.get();
				break;
			}

		} while (menuChoice != 1);

		UI::ShowMessageBox("MAPLE", "There could be BUGS in that grass!");
		UI::ShowMessageBox("Prof Maple looks visibly nauseus holding back vomit.\n  He must really not like bugs...");
		UI::ShowMessageBox("MAPLE", "Forget it! Just meet me in my lab!");
	}

	static void SmolCreatureLab(Handler& player, Handler& rival) {
		UI::ShowMessageBox(player.GetName() + " enters Prof Maple's weird lab thing...");
		UI::ShowMessageBox("MAPLE", "Welcome! Now select a pet that you will use to fight people!");

		std::string input = "";
		int menuChoice = 0;

		SmolCreature fireGuy = SmolCreature("Fireguy", 5, 52, 43, 50, 39, 39, Type::FIRE, Type::NONE, std::vector<Move>(4));
		SmolCreature splasher = SmolCreature("Splasher", 5, 48, 65, 50, 44, 44, Type::WATER, Type::NONE, std::vector<Move>(4));
		SmolCreature leafling = SmolCreature("Leafling", 5, 45, 49, 65, 45, 45, Type::GRASS, Type::POISON, std::vector<Move>(4));

		Move scratch("Scratch", 40, 1, 35, Type::NORMAL);
		Move tackle("Tackle", 40, 1, 35, Type::NORMAL);

		fireGuy.LearnMove(scratch);
		splasher.LearnMove(tackle);
		leafling.LearnMove(scratch);

		std::vector<std::string> menuOptions = {
			fireGuy.GetName(),
			splasher.GetName(),
			leafling.GetName()
		};

		do {
			system("CLS");

			UI::DisplayMenu("Select a Smol Creature", menuOptions);

			std::cout << "  Choice: ";
			getline(std::cin, input);

			menuChoice = std::stoi(input);

			switch (menuChoice) {
			case 1:
				player.AddSmolCreatureToTeam(fireGuy);
				rival.AddSmolCreatureToTeam(splasher);
				break;
			case 2:
				player.AddSmolCreatureToTeam(splasher);
				rival.AddSmolCreatureToTeam(leafling);
				break;
			case 3:
				player.AddSmolCreatureToTeam(leafling);
				rival.AddSmolCreatureToTeam(fireGuy);
				break;
			default:
				std::cout << "  Invalid choice. Please try again!" << std::endl;
				std::cin.get();
				break;
			}

		} while (menuChoice < 1 || menuChoice > menuOptions.size());
	}

	void Battle(Handler player, Handler handler) {
		UI::ShowMessageBox(handler.GetName() + " approaches!");
	}
};