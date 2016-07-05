#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "Scheduler.h"

void getPCBandSetScheduler(std::string fileName, Scheduler * list, int schedulerChoice);

int main() {
  std::cout << "-----------------------------------------------\n";
  std::cout << "xeonOS\n";
  std::cout << "-----------------------------------------------\n";
	Scheduler * list = new Scheduler();
	bool exit = true;
	std::string input;
	while (exit != false) {
    std::cout << "-----------------------------------------------\n";
		std::cout << "Press 1 to insert pcb file of your choice\n";
		std::cout << "Press 2 to insert a pcb\n";
		std::cout << "Press 3 to delete a pcb\n";
		std::cout << "Press 4 to display the current scheduler\n";
		std::cout << "-----------------------------------------------\n";
		std::cin >> input;
		if (input == "0") {
			exit = false;
		}
		else if (input == "1") {
			int scheduler;
			std::cout << "Please enter the pcb query file name\n";
			std::cin >> input;
			std::cout << "Please choose a scheduler you would like to use\n";
			std::cout << "Press 0 for the Shortest Job First\n";
			std::cout << "Press 1 for the Non-Preemptive Priority\n";
			std::cout << "Press 2 for the Default Add\n";
			std::cin >> scheduler;
			getPCBandSetScheduler(input, list, scheduler);
		}
		else if (input == "2") {
			std::vector<int> add;
			printf("Enter an ID\n");
			std::cin >> input;
			add.push_back(std::stoi(input));
			printf("Enter an arrival time\n");
			std::cin >> input;
			add.push_back(std::stoi(input));
			printf("Enter an burst time\n");
			std::cin >> input;
			add.push_back(std::stoi(input));
			printf("Enter an priority\n");
			std::cin >> input;
			add.push_back(std::stoi(input));
			printf("To insert in Shortest Job First Scheduler, press 0\n");
			printf("To insert in Non Preemptive Priority Scheduler, press 1\n");
			std::cin >> input;
			list->schedulerChooser(add, list, std::stoi(input));
		}
		else if (input == "3") {
      std::cout << "Please choose a scheduler you would like to use\n";
			std::cout << "Press 0 for the default delete (delete from head)\n";
			std::cout << "Press 1 to delete by PID\n";
      std::cin >> input;
      if(std::stoi(input) == 0) {
        list->defaultDelete();
      }
      else if(std::stoi(input) == 1) {
        std::cout << "Enter a PID to delete\n";
        std::cin >> input;
        list->deletePCB(std::stoi(input));
      }
      else {
        std::cout << "Not a valid input\n";
      }
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
			while (ss >> ext) {
				pcb.push_back(ext);
				if (ss.peek() == ',' || ss.peek() == ' ') {
					ss.ignore();
				}
			}
			list->schedulerChooser(pcb, list, schedulerChoice);
			pcb.clear();
		}
	}
	else {
		std::cout << "Please enter a valid file name\n";
	}

}
