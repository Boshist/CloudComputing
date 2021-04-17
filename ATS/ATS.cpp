#include "ATS.h"

ATS::ATS()
{
	std::srand(std::time(nullptr));
}

void ATS::Call(std::string calledUser, std::string callingUser)
{

	if (ConversationLines.find(calledUser) == ConversationLines.end())
	{
		ConversationLines[calledUser] = callingUser;
		ConversationTimers[calledUser] = std::chrono::milliseconds(0);
		std::cout << calledUser << " received a call from " << callingUser << std::endl;
	}
	else
		WaitingLines[calledUser].push_back(callingUser);
}

bool ATS::Working()
{

	auto begin = std::chrono::steady_clock::now();

	if (ConversationLines.empty() && WaitingLines.empty())
		return false;
		
	//Hang off operation
	for (auto it = ConversationLines.begin(); it != ConversationLines.end();)
	{
		//if timer expired
		if (ConversationTimers[it->first] >= std::chrono::milliseconds(500))
		{
			std::cout << it->first << " stopped talking with " << it->second << std::endl;
			ConversationTimers.erase(it->first);
			ConversationLines.erase(it++);
		}
		else
			++it;
	}		

	//Transition from waiting to talking if the line is empty
	for (auto it = WaitingLines.begin(); it != WaitingLines.end();)
	{
		if (ConversationLines.find(it->first) == ConversationLines.end())
		{
			int randomCaller = std::rand() % it->second.size();
			Call(it->first, it->second[randomCaller]);
			it->second.erase(it->second.begin() + randomCaller);

			if (it->second.empty())
				WaitingLines.erase(it->first);
			else
				++it;
		}
		else
			++it;
	}

	//Update timers
	for (auto it = ConversationTimers.begin(); it != ConversationTimers.end(); ++it)
		it->second += std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - begin);

	return true;
}

ATS::~ATS()
{

}