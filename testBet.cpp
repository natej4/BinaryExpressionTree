#include "bet.h"
#include <iostream>
#include <string>

using namespace std;

string iToP(BET t, string e);
bool lower(char a, char b);


int main()
{
  int choice;
  string e;
  char cont = 'Y';
  char c;
  BET t;
  
  //asking for type of expression and getting expression
  while ((cont == 'Y' || cont == 'y') && (cont != 'n' || cont != 'N')){
  cout << "Choose which type of expression you would like to input: \n1. Prefix\t2. Infix\t3. Postfix \n=> ";
  cin >> choice;
  cin.ignore();
  cout << "Enter expression: ";
  getline (cin,e);
  //cout << e << endl ;
  
  //inputting a prefix expression
  if (choice == 1)
  {
    int i;
    for (i=e.length(); i>=0; i--)
    {
      
      c=e[i];
      if (c != ' '){
        cout << c;
        if (c=='+' || c=='-' || c=='*' || c=='/')
          t.insertPrefixOperator(c);
        else
          t.insertOperand(c);                    
        }
     } 
  }
  
  //inputting an infix expression
  else if (choice == 2)
  {
    string f;
    f = iToP(t, e);
    //cout << f;
    int i;
 
    for (i=0; i<f.length(); i++)
    {
      c=f[i];
      if (c != ' '){
        //cout << c;
        if (c=='+' || c=='-' || c=='*' || c=='/')
          t.insertPostfixOperator(c);
        else
          t.insertOperand(c);
        }
     }     
    
  }
  
  //inputing a postfix expression
  else if (choice == 3)
  {
    int i;
 
    for (i=0; i<e.length(); i++)
    {
      c=e[i];
      if (c != ' '){
        //cout << c;
        if (c=='+' || c=='-' || c=='*' || c=='/')
          t.insertPostfixOperator(c);
        else
          t.insertOperand(c);
        }
     } 
   }
  
  //displaying expression in tree in 3 ways
  
  //Prefix Display
  cout << "\nPrefix Expression Produced From Tree:" << endl;
  t.preorder();
  
  //Infix display
  cout << "\nInfix Expression Produced From Tree:" << endl;
  t.inorder();
  
  //Postfix Display
  cout << "\nPostFix Expression Produced From Tree:" << endl;
  t.postorder();
  
  //clear tree and repeat as necessary
  t.makeEmpty();
  cout << "\nBuild another tree? (Y/N)";
  cin >> cont;
  }
  
  
  
}

//converts an inputted infix expression to a postfix expression for insertion in a BET
string iToP(BET t, string e)
{
  stack<char> s;
  int i;
  string out = " ";
  char c;
 
    for (i=0; i<e.length(); i++)
    {
      c=e[i];
      if (c != ' '){
        //out += c;
        if (c=='(' )
          s.push(c);
        else if (c=='+' || c=='-' || c=='*' || c=='/'){
          if (!s.empty()){
            while (!lower(c, s.top())){
            out += s.top();
            s.pop();
            }
          }
          s.push(c);
         
        }
        else if (c==')')
        {
          while (s.top()!='('){
            out += s.top();
            s.pop();
            }
          s.pop();
        }
        else
          out += c;
      }
    }
     
      while (!s.empty()){
        if(s.top() != ')' || !s.top() != '('){
          out += s.top();
          s.pop();
        }
        else
          s.pop();
        }
      return out;     
}

//checking to see if next is lower precedence than whats on the top of the stack
bool lower(char next, char stack)
{
  if (next==stack)
    return false;
  else if ((next=='*' || next=='/') && (stack=='*' || stack=='/'))
    return false;
  else if ((next=='+' || next =='-') && (stack =='+' || stack=='-'))
    return false;
  else if (( next=='*' || next=='/') && (stack =='+' || stack=='-'))
    return false;
  else
    return true;
}


