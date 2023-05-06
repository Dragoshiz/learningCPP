#include "BitcoinExchange.hpp"


void checkNopen_File(std::string arg, std::ifstream &file) {
  if (arg.compare("data.csv") == 0) {
    file.open(arg.c_str(), std::ifstream::in);
    if (file.fail()) {
      std::cerr << "Error: no data.csv in the current directory" << std::endl;
      exit(1);
    }
    return;
  }
  file.open(arg.c_str(), std::ifstream::in);
  if (file.fail()) {
    std::cerr << "Error: argument file not found" << std::endl;
    exit(1);
  }
  return;
}

//checks if the string has only digits
bool isDigit(std::string& dateValue){
  std::string::const_iterator it = dateValue.begin();
  while(it != dateValue.end() && std::isdigit(*it)) ++it;
  if (!dateValue.empty() && it == dateValue.end())
    return true;
  return false;
}

//function to check date if is valid
bool date(std::string& dateValue){
  if (dateValue.length() != 10)
    return false;
  std::stringstream date(dateValue);
  std::string tokn;
  while (std::getline(date, tokn, '-')){
    if (!isDigit(tokn))
      return false;
  }
  return true;
}

bool separator(std::string &separator){
  return separator.compare("|");
}

bool isInt(std::string &value){
  std::stringstream ss(value);
  long num;
  if (ss >> num){
    if (num <= std::numeric_limits<int>::max() && num >= std::numeric_limits<int>::min())
      return true;
  }
  return false;
}

bool isFloat(std::string &value){
  std::stringstream ss(value);
  float num;
  if (ss >> num){
    if (num >= std::numeric_limits<float>::min() && num <= std::numeric_limits<float>::max())
      return true;
  }
  return false;
}

bool value(std::string &value){
  int count = 0;
  std::string::iterator it = value.begin();
  while (it != value.end()){
    if (std::isdigit(*it))
      continue;
    else if (*it == '.' && count == 0){
      count++;
      continue;
    }
    else
      break;
  }
  if (it == value.end() && !value.empty()){
    if (count == 1)
      return isFloat(value);
    return isInt(value);
  }
  return false;
}

void tokenizizer(std::string &line) {
  std::stringstream ss(line);
  while (ss.good()){
    std::string tokn;
    getline(ss, tokn, ' ');

  }
}

void populateMapDb(std::ifstream& file, std::map<std::string, std::string>& mapDb){
  std::string line;
  while(std::getline(file, line)){
     std::stringstream ss(line);
     while(ss.good()){
      std::string tokn_1, tokn_2;
      getline(ss, tokn_1, ',');
      getline(ss, tokn_2, ',');
      mapDb.insert(std::make_pair(tokn_1, tokn_2));
     }
  }
}

int parse_file(std::ifstream &file) {
  std::string line;
  while (std::getline(file, line)) {
    tokenizizer(line);
  }
  return 1;
}
