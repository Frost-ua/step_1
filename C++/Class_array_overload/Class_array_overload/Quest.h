#pragma once
#include <string>
#include <iostream>
using std::string;

class Quest
{
public:
	Quest(const string &question, const string &answer);
	Quest();
	const string& getQuastion()const;
	const string& getAnswer()const;
	void setQuastion(const string& question);
	void setAnswer(const string& answer);
	void setQuest(const string& question, const string& answer);
private:

	string question;
	string answer;
};

inline Quest::Quest(const string& question, const string& answer)
{
	try
	{
		setQuastion(question);
		setAnswer(answer);
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what();
	}
}

inline Quest::Quest()
{
}

inline const string& Quest::getQuastion() const
{
	return question;
}

inline const string& Quest::getAnswer()const
{
	return answer;
}

inline void Quest::setQuastion(const string& question)
{
	if (!empty(question))
	{
		this->question = question;
	}
	else
	{
		throw std::exception("String is empty!");
	}
}

inline void Quest::setAnswer(const string& answer)
{
	
	if (!empty(answer))
	{
		this->answer = answer;
	}
	else
	{
		throw std::exception("String is empty!");
	}
}

inline void Quest::setQuest(const string& question, const string& answer)
{
	if (!empty(answer) && !empty(question))
	{
		this->answer = answer;
		this->question = question;
	}
	else
	{
		throw std::exception("Question or answer is empty!");
	}
}
