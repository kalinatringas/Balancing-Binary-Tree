#pragma once
#include <string>
#include "Tree.h"

bool processCommand(Tree& tree, const std::string& line);
bool isValidGatorID(std::string& gatorID);
bool isValidName(std::string& name);
std::string parsedQuote(std::istream& input);
