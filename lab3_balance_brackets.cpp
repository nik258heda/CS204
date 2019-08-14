#include <bits/stdc++.h>
using namespace std;
string check(string s)
{
}
int main()
{
	long long t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		stack<char> a;
		int n = s.length();
		int k = 0;
		char x;
		for (int i = 0; i < n; i++)
		{

			if (s[i] == '(' || s[i] == '{' || s[i] == '[' || s[i] == '<')
			{
				a.push(s[i]);
			}
			else if (s[i] == ')')
			{
				if (!a.empty() && a.top() == '(')
				{
					a.pop();
				}
				else
				{
					cout << "NO"
						 << "\n";
					break;
				}
			}
			else if (s[i] == '}')
			{
				if (!a.empty() && a.top() == '{')
				{
					a.pop();
				}
				else
				{
					cout << "NO"
						 << "\n";
					break;
				}
			}
			else if (s[i] == ']')
			{
				if (!a.empty() && a.top() == '[')
				{
					a.pop();
				}
				else
				{
					cout << "NO"
						 << "\n";
					break;
				}
			}
			else if (s[i] == '>')
			{
				if (!a.empty() && a.top() == '<')
				{
					a.pop();
				}
				else
				{
					cout << "NO"
						 << "\n";
					break;
				}
			}
			else if (s[i] == '|')
			{
				if (a.empty())
				{
					a.push('|');
				}
				else if (!a.empty() && a.top() == '|')
				{
					a.pop();
				}
				else
				{
					a.push('|');
				}
			}
			k++;
		}
		if (k == n)
		{
			if (a.empty())
			{
				cout << "YES"
					 << "\n";
			}
			else
			{
				cout << "NO"
					 << "\n";
			}
		}
	}
	return 0;
}
