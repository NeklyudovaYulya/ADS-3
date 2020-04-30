#include <iostream>
#include <string>
#include "tstack.h"

 using namespace std;
 
 int getPriority(char ch)
 {
    switch (ch)
    {
    case '(': return 0;
    case ')': return 1;
    case '+': return 2;
    case '-': return 2;
    case '*': return 3;
    case '/': return 3;    
    default: return -1;
    }
} 

 string infx2pstfx(string inf)
{
    TStack<char> stack;
    string outOf = "";
    for (int i = 0; i < inf.size(); i++)
    {
        char ch = inf[i];
        int priority = getPriority(ch);

        if (priority == -1)
            outOf.append( string(1,ch) );
        else
            if( stack.isEmpty() || priority == 0 || priority > getPriority( stack.get()))
                stack.push(ch);
            else
            {
                if (ch == ')')
                    while(true)
                    {
                        char lastStackl = stack.get();
                        stack.pop();
                        if (lastStackl != '(')
                            outOf.append(string(1,lastStackl));
                        else
                            break;
                            }
                else
                {
                    while(!stack.isEmpty())
                    {
                        char lastStackl = stack.get();
                        stack.pop();
                        if (getPriority(lastStackl) >= priority)
                            outOf.append(string(1,lastStackl));
                    }
                    stack.push(ch);
                }
            }
    }
    while(!stack.isEmpty())
    {
        char lastStackl = stack.get();
        stack.pop();
        outOf.append(string(1,lastStackl));
    }
    return outOf;
}

int calculate(int num1, int num2, char operation)
{
    switch (operation)
    {
    case '+': return num1 + num2;
    case '-': return num1 - num2;
    case '*': return num1 * num2;
    case '/': return num1 / num2;    
    default: return -1;
    }
}

int eval(string pst)
{
    TStack<int> stack;
    for (int i = 0; i < pst.size(); i++)
    
        char ch = pst[i];
        int priority = getPriority(ch);
   
        if ( priority == -1)
            stack.push(ch - 48);
        else
        {
            int  num1=stack.get(); 
            stack.pop();

            int num2 = stack.get();
            stack.pop();

            int result = calculate(num2, num1, ch);
            stack.push(result);
        }

    }
    return stack.get();
}
