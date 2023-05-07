#include "BitcoinExchange.hpp"

void errMsgs(int msg){
  std::string one = "Error: not a positive number.";
  std::string two = "Error: too large a number.";
  std::string three = "Error: bad input => ";
  std::string four = "Error: could not open file.";

  if(msg == 1)
    std::cout << one << std::endl;
  else if(msg == 2)
    std::cout << two << std::endl;
  else if(msg == 3)
    std::cout << three;
  else if(msg == 4)
    std::cout << four << std::endl;
}

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

bool validDate(std::string& date, int ymd){
  std::stringstream ss(date);

  int num;
  if(ss >> num){
    if(ymd == 0 && (num > 2008 && num < 2023))
      return true;
    else if (ymd == 1 && (num > 0 && num < 13))
      return true;
    else if (ymd == 2 && (num > 0 && num < 32))
      return true;
  }
  return false;
}

//check that date is valid (leap years, and )
bool yyyymmdd(std::string& dateValue){
  std::string leaps[] = {"2012", "2016", "2020"};
  std::string sh_months[] = {"04", "06", "09", "11"};
  std::string yyyy = dateValue.substr(0,4);
  std::string mm = dateValue.substr(5,2);
  std::string dd = dateValue.substr(8,2);
  std::stringstream ss(dd);
  int day;
  ss >> day;
  if (mm == "02" && day == 29 ){
    for (int i=0; i < 3; i++){
      if(yyyy == leaps[i])
        return true;
    }
  }
  for (int i=0; i < 4; i++){
    if ((sh_months[i] == mm && day > 30)|| (mm == "02" && day > 28)){
        return false;
    }
  }
  return true;
}

//function to check date if is valid
bool datechck(std::string& dateValue){
  if (dateValue.length() != 10)
    return false;
  int counter = 0;
  std::stringstream date(dateValue);
  std::string tokn;
  while (std::getline(date, tokn, '-')){
    if (!isDigit(tokn) || !validDate(tokn, counter % 3))
      return false;
    counter++;
  }
  return yyyymmdd(dateValue);
}

bool separator(std::string &separator){
  return separator.compare("|") == 0;
}

bool isInt(std::string &value){
  std::stringstream ss(value);
  long num;
  if (ss >> num){
    if (num <= std::numeric_limits<int>::max())
      return true;
    else if (num > std::numeric_limits<int>::max())
      errMsgs(2);
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
    if (std::isdigit(*it)){
      ++it;
      continue;
    }
    else if (*it == '.' && count == 0){
      count++;
      ++it;
      continue;
    }
    else if (*it == '-'){
      errMsgs(1);
      break;
    }
  }
  if (it == value.end() && !value.empty()){
    if (count == 1)
      return isFloat(value);
    return isInt(value);
  }
  return false;
}

void getline_forward(std::stringstream& ss, std::string& tokn, int num){
  for (int i=0; i<num;i++){
    getline(ss, tokn, ' ');
  }
}

void searchMap(std::map<std::string, std::string>& mapdb,std::string& date, std::string& tokn){
  std::map<std::string, std::string>::iterator it = mapdb.find(date);
  std::stringstream value(tokn);
  if (it != mapdb.end()){
    if(isInt(tokn)){
      float db_value;
      int num_int;
      value >> num_int;
      std::stringstream db_ss(it->second);
      db_ss >> db_value;
      std::cout << date << " => " << db_value * num_int << std::endl;
    }
    else if(isFloat(tokn)){
      float db_value;
      float num_fl;
      value >> num_fl;
      std::stringstream db_ss(it->second);
      db_ss >> db_value;
      std::cout << date << " => " << db_value * num_fl << std::endl;
    }
  }
}

void tokenizizer(std::string &line, std::map<std::string, std::string>& mapdb){
  std::stringstream ss(line);
  std::string tokn;
  std::string date, num;
  while (ss.good()){
    getline_forward(ss, tokn, 1);
    if (datechck(tokn)){
      date = tokn;
       getline_forward(ss, tokn, 1);
      if (separator(tokn)){
         getline_forward(ss, tokn, 1);
        if (value(tokn)){
          num = tokn;
          searchMap(mapdb, date, num);
        }
      }
      else{
        errMsgs(3);
        std::cout << tokn << std::endl;
        getline_forward(ss, tokn, 1);
      }
    }
    else{
      errMsgs(3);
      std::cout << tokn << std::endl;
      getline_forward(ss, tokn, 2);
    }
  }
}

void populateMap(std::ifstream& file, std::map<std::string, std::string>& map, char delim){
  std::string line;
  while(std::getline(file, line)){
     std::stringstream ss(line);
     while(ss.good()){
      std::string tokn_1, tokn_2;
      getline(ss, tokn_1, delim);
      getline(ss, tokn_2, delim);
      if (tokn_2.empty())
        tokn_2 = "noValue";
      map.insert(std::make_pair(tokn_1, tokn_2));
     }
  }
}

int parse_file(std::ifstream &file, std::map<std::string, std::string>& mapdb){
  std::string line;
  std::getline(file, line);
  if (line.compare("date | value") != 0){
    std::cerr << "Error: wrong input, should be 'date | value'" << std::endl;
    exit(1);
  }
  while (std::getline(file, line)){
    tokenizizer(line, mapdb);
  }
  return 1;
}