#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "Scheduler.h"

void getPCBandSetScheduler(std::string fileName, int schedulerChoice);

int main() {
  Scheduler * list = new Scheduler();
  bool exit = false;
  while(exit != false){
    std::cin >> input;
    if(input == 0) {
      exit == false;
    }
    else if(input == 1) {
      //input file
    }
    else if(input == 2) {
      //add pcb
      //list.defaultInsert()
    }
    else if(input == 3) {
      //delete pcb
    }
    else {
      std::cout << "Not a valid input\n";
    }
  }
}

void getPCBandSetScheduler(std::string fileName, int schedulerChoice) {
  std::ifstream file("processes.txt", std::ios::in);
  std::std::vector<int> pcb;
  int ext;
  if(file.good()) {
    std::string line;
    while(getline(file, line)) {
      std::stringstream ss(line);
      while (ss >> ext) {
        pcb.push_back(ext);
        if(ss.peak() == ',' || ss.peak() == ' ') {
          ss.ignore();
        }
      }
      schedulerChoice(pcb, list, 0);
    }
  } else {
    std::cout << "Please enter a valid file name\n"
  }

}
