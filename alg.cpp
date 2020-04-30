#include <iostream>
#include <string>
#include "tstack.h"

 using namespace std;
 
 int setPrioritet(char ch)
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
    string outof = "";
    for (int i = 0; i < inf.size(); i++)
    {
        char ch = inf[i];
        int prioritet = setPrioritet(ch);

        if (p == -1)
            outof.append( string(1,ch) );
        else
            if( stack.isEmpty() || prioritet == 0 || prioritet > setPrioritet( stack.get()))
                stack.push(ch);
            else
            {
                if (ch == ')')
                    while(true)
                    {
                        char lastStackl = stack.get();
                        stack.pop();
                        if (lastStackl != '(')
                            outof.append(string(1,lastStackl));
                        else
                            break;
                            }
                else
                {
                    while(!stack.isEmpty())
                    {
                        char lastStackl = stack.get();
                        stack.pop();
                        if (setPrioritet(lastStackl) >= p)
                            outof.append(string(1,lastStackl));
                    }
                    stack.push(ch);
                }
            }
    }
    while(!stack.isEmpty())
    {
        char lastStackl = stack.get();
        stack.pop();
        outof.append(string(1,lastStackl));
    }
    return outof;
}

int calc(int num1, int num2, char oper)
{
    switch (oper)
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
    {
        char ch = pst[i];
        int prioritet = setPrioritet(ch);
    } 
        if ( prioritet == -1)
            stack.push(ch - 48);
        else
        {
            int  num1=stack.get(); 
            stack.pop();

            int num2 = stack.get();
            stack.pop();

            int result = calc(num2, num1, ch);
            stack.push(result);
        }

    }
    return stack.get();
}
