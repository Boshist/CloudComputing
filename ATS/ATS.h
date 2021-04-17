#pragma once
#include <unordered_map>
#include <vector>
#include <string>

#include <iostream>

#include <cstdlib>
#include <ctime>

#include <chrono>
#include <thread>

class ATS
{

public:

	ATS();
	void Call(std::string calledUser, std::string callingUser);
	bool Working();
	~ATS();

private:

	std::unordered_map<std::string, std::string> ConversationLines;
	std::unordered_map<std::string, std::vector<std::string>> WaitingLines;

	std::unordered_map<std::string, std::chrono::milliseconds> ConversationTimers;
};

