#include <iostream>
#include <string>
#include "tstack.h"

 using namespace std;
 
 int prioritet(char c)
 {
    switch (c)
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
        char c = inf[i];
        int p = prioritet(c);

        if (p == -1)
            outof.append( string(1,c) );
        else
            if( stack.isEmpty() || p == 0 || p > prioritet( stack.get()))
                stack.push(c);
            else
            {
                if (c == ')')
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
                        if (prioritet(lastStackl) >= p)
                            outof.append(string(1,lastStackl));
                    }
                    stack.push(c);
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
        char c = pst[i];
        int p = prioritet(c);
    } 
        if ( p == -1)
            stack.push(c - 48);
        else
        {
            int  num1=stack.get(); 
            stack.pop();

            int num2 = stack.get();
            stack.pop();

            int res = calc(num2, num1, c);
            stack.push(res);
        }

    }
    return stack.get();
}
