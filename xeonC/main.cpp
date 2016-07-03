#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "Scheduler.h"

void extractContents(std::string fileName, int schedulerChoice);

int main() {

}

void extractContents(std::string fileName, int schedulerChoice) {
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
      schedulerChoice(pcb, 0);
    }
  }

}
