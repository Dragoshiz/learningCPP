#include "BitcoinExchange.hpp"

void errMsgs(int msg){
  switch (msg)
  {
    case 1:
      std::cerr << "Error: not a positive number." << std::endl;
      break;
    case 2:
      std::cerr << "Error: too large a number." << std::endl;
      break;
    case 3:
      std::cerr << "Error: bad input => ";
      break;
    case 4:
      std::cerr << "Error: could not open file." << std::endl;
      break;
    case 5:
      std::cerr << "Error: Bitcoin didn't exist back then" << std::endl;
      break;
    case 6:
      std::cerr << "Error: argument file not found" << std::endl;
      break;
  }
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
    errMsgs(4);
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
  size_t i = 0;

  if (value[i] == '+')
    i++;

  while(i < value.length()){
    if(!std::isdigit(value[i]))
      return false;
    i++;
  }
  if (ss >> num){
    if (num <= std::numeric_limits<int>::max() && num <= 1000)
      return true;
    else if (num > std::numeric_limits<int>::max())
      errMsgs(2);
  }
  return false;
}

bool isFloat(std::string &value){
  std::stringstream ss(value);
  float num;
  size_t i = 0;
  bool dot = false;
  if (value[i] == '+')
    i++;

  while(i < value.length()){
    if(std::isdigit(value[i]))
      i++;
    else if (value[i] == '.' && !dot){
      dot = true;
      i++;
    }
    else
      return false;
    }
  if (ss >> num){
    if ((num >= std::numeric_limits<float>::min() && num <= std::numeric_limits<float>::max()) || num == 0)
      return true;
  }
  return false;
}

bool check_value(std::string& value){
  if (value.empty())
    value = "No value given";
  if (value.at(value.length() - 1) == '.' || value[0] == '.' || value.find("--") != std::string::npos){
    errMsgs(3);
    std::cerr << value << std::endl;
    return false;
  }
  else if (value[0] == '-'){
    errMsgs(1);
    return false;
  } 
  for(int i=0; value[i]; i++){
    if (!std::isdigit(value[i]) && value[i] != '.'){
      errMsgs(3);
      std::cerr << value << std::endl;
      return false;
    }
  }
  return true;
}

//function to check fo
bool value(std::string& value){
    if(!check_value(value))
      return false;

  size_t decimal = value.find(".");
  if (decimal == std::string::npos)
    return isInt(value);
  else if (decimal == 0)
    return false;
  else if (decimal == value.length() - 1)
    return false;
  else{
    std::string int_part = value.substr(0, decimal);
    std::string fractional_part = value.substr(decimal + 1);
    return isInt(int_part) && isInt(fractional_part) && isFloat(value);
  }
}


void multiply_values(std::map<std::string, std::string>::iterator& it, std::string& tokn, std::string& date){
   std::stringstream value(tokn);
  if(isInt(tokn)){
      float db_value;
      int num_int;
      value >> num_int;
      std::stringstream db_ss(it->second);
      db_ss >> db_value;
      std::cout << date << " => "<< num_int << " = " << db_value * num_int << std::endl;
  }
  else if(isFloat(tokn)){
    float db_value;
    float num_fl;
    value >> num_fl;
    std::stringstream db_ss(it->second);
    db_ss >> db_value;
    std::cout << date << " => " << num_fl << " = " << db_value * num_fl << std::endl;
  }
}


void getline_forward(std::stringstream& ss, std::string& tokn, int num){
  for (int i=0; i<num;i++){
    getline(ss, tokn, ' ');
  }
}

//function that searches for the closest date if the user defined date is not found
void getClosestDate(std::map<std::string, std::string>& mapdb, std::string& tokn, std::string& date){
  std::map<std::string, std::string>::iterator it = mapdb.lower_bound(date);
  if (it == mapdb.begin()){
    errMsgs(5);
    return;
  }
  else{
    multiply_values(it, tokn , date);
  }
}

//function to search for the date value from the user defined file inside the data map
void searchMap(std::map<std::string, std::string>& mapdb,std::string& date, std::string& tokn){
  std::map<std::string, std::string>::iterator it = mapdb.find(date);
  std::stringstream value(tokn);
  if (it != mapdb.end()){
    multiply_values(it, tokn, date);
  }
  else if(date == "2009-01-01"){
    errMsgs(5);
    return;
  }
  else{
    getClosestDate(mapdb, tokn,  date);
  }
}

//function that check each line of the file passed by the user
void tokenizizer(std::string &line, std::map<std::string, std::string>& mapdb){
  std::stringstream ss(line);
  std::string tokn;
  std::string date;
  while (ss.good()){
    getline_forward(ss, tokn, 1);
    if (datechck(tokn)){
      date = tokn;
       getline_forward(ss, tokn, 1);
      if (separator(tokn)){
         getline_forward(ss, tokn, 1);
        if (value(tokn))
          searchMap(mapdb, date, tokn);
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

//function to populate the map with the data.csv
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

//function to parse the file passed by the user
void parse_file(std::ifstream &file, std::map<std::string, std::string>& mapdb){
  std::string line;
  std::getline(file, line);
  if (line.compare("date | value") != 0){
    std::cerr << "Error: wrong input, should be 'date | value'" << std::endl;
    exit(1);
  }
  while (std::getline(file, line)){
    tokenizizer(line, mapdb);
  }
}