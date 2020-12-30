#include <stack>
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	while (true)
	{
        string s;
		getline(cin, s);
        
		stack<char> bracket;
		if (s[0] == '.') 
            break;

		for (int i = 0; i < s.length() - 1; i++)
		{
			if (s[i] == '(') 
                bracket.push('(');
			if (s[i] == '[') 
                bracket.push('[');
			if (s[i] == ']'){
		        if (!bracket.empty() && bracket.top() == '[') 
                    bracket.pop();
				else { 
                    printf("no\n"); 
                    break; }
			}

			if (s[i] == ')'){
				if (!bracket.empty() && bracket.top() == '(') 
                    bracket.pop();
				else {
                    printf("no\n"); 
                    break; 
                }
			}

			if (bracket.empty() && i == s.length() - 2) 
                printf("yes\n");
			else if (!bracket.empty() && i == s.length() - 2)
                printf("no\n");
		}

	}
}
