// 언어 c++, 메모리 2024KB, 시간 140ms
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void)
{
	string sentence;
	stack<int> s;
	while (1)
	{
		getline(cin, sentence);
		if (sentence == ".") break;
		for (int i = 0; sentence[i] != '.'; i++)
		{
			if (sentence[i] == ')')
			{
				if (s.size() > 0 && s.top() == '(') s.pop();
				else s.push(sentence[i]);

			}
			else if (sentence[i] == ']')
			{
				if (s.size() > 0 && s.top() == '[') s.pop();
				else s.push(sentence[i]);
			}
			else if (sentence[i] == '(') s.push(sentence[i]);
			else if (sentence[i] == '[') s.push(sentence[i]);
		}
		if (s.size() == 0) cout << "yes" << "\n";
		else cout << "no" << "\n";
		while (!s.empty())
		{
			s.pop();
		}
	}
}
