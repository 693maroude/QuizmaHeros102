#include "QuestionManager.hpp"

namespace Quizma
{
	QuestionManager::QuestionManager(std::string question, std::string answer[])
	{
		quest = question;

		decltype(this->ans->size()) i = 0;
		for (; i < SIZE_OF_ANS; i++) {
			this->ans[i] = answer[i];
		}
		correct_ans = answer[i];
	}

	void QuestionManager::setValue(std::string question, std::string answer[])
	{
		quest = question;

		for (decltype(this->ans->size()) i = 0; i < SIZE_OF_ANS; i++) {
			this->ans[i] = answer[i];
		}
	}

	std::ostream &operator<<(std::ostream &output, const QuestionManager &q)
	{
		output << q.quest << std::endl;

		for (decltype(q.ans->size()) i = 0; i < SIZE_OF_ANS; i++) {
			output << q.ans[i] << std::endl;
		}

		return output;
	}
}