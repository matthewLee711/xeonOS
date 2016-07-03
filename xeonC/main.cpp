#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "Scheduler.h"

void getPCBandSetScheduler(std::string fileName, Scheduler * list, int schedulerChoice);

int main() {
	Scheduler * list = new Scheduler();
	bool exit = true;
	std::string input;
	while (exit != false) {
		std::cout << "Make a choice\n";
		std::cin >> input;
		if (input == "0") {
			exit = false;
		}
		else if (input == "1") {
			//input file
			getPCBandSetScheduler("", list, 1);
		}
		else if (input == "2") {
			//add pcb
			//list->defaultInsert()
		}
		else if (input == "3") {
			//delete pcb
		}
		else if (input == "4") {
			list->display();
		}
		else {
			std::cout << "Not a valid input\n";
		}
	}
}

void getPCBandSetScheduler(std::string fileName, Scheduler * list, int schedulerChoice) {
	std::ifstream file("processes.txt", std::ios::in);
	std::vector<int> pcb;
	int ext;
	if (file.good()) {
		std::string line;
		while (getline(file, line)) {
			std::stringstream ss(line);
			//std::cout << "line: " << line << std::endl;
			while (ss >> ext) {
				pcb.push_back(ext);
				if (ss.peek() == ',' || ss.peek() == ' ') {
					ss.ignore();
				}
			}
			list->schedulerChooser(pcb, list, 2);
			pcb.clear();
		}
	}
	else {
		std::cout << "Please enter a valid file name\n";
	}

}
