#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <chrono>


class UI {
public:
	static void TypeWriterEffect(std::string message) {
		for (char letter : message) {
			std::cout << letter;

			std::this_thread::sleep_for(std::chrono::milliseconds(20));
		}
	}

	static void ShowMessageBox(std::string message) {
		// Variable initialization
		std::string divider = "=====================================================\n";
		std::string padding = "  ";

		// Show Message Box Logic
		system("CLS");

		std::cout << divider << std::endl;

		std::cout << padding;

		TypeWriterEffect(message);

		std::cout << "\n" << std::endl;

		std::cout << divider << std::endl;

		std::cout << padding << "Press enter to continue..." << std::endl;
		std::cin.get();
	}

	static void ShowMessageBox(std::string subject, std::string message) {
		// Variable initialization
		std::string divider = "================================================================\n";
		std::string padding = "  ";

		// Show Message Box Logic
		system("CLS");

		std::cout << divider << std::endl;

		std::cout << padding << subject << ": ";

		TypeWriterEffect(message);

		std::cout << "\n" << std::endl;

		std::cout << divider << std::endl;

		std::cout << padding << "Press enter to continue..." << std::endl;
		std::cin.get();
	}

	static void DisplayMenu(std::string primeText, std::vector<std::string> menuOptions) {
		system("CLS");

		// Prime the user with choices
		std::cout << "  " << primeText << "\n" << std::endl;

		for (int i = 0; i < menuOptions.size(); i++) {
			std::cout << "  " << "[" << i + 1 << "] " << menuOptions[i] << std::endl;
		}
	}

	static std::string PromptUser(std::string promptText) {
		// Initializing variables
		std::string result = "";
		std::string padding = "  ";

		do {
			system("CLS");

			// Determining the value of result
			std::cout << padding << promptText << ": ";

			getline(std::cin, result);

			if (result == "") {
				std::cout << padding << promptText << " can not be empty! Please try again..." << std::endl;
				std::cin.get();
			}

		} while (result == "");

		// Return the result
		return result;
	}
};