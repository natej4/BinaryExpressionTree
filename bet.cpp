#include <iostream>
#include <stack>
#include "bet.h"

using namespace std;

//constructor
BET::BET()
{
  root = NULL;
  
}

//destructor
BET::~BET()
{
  makeEmpty();
  cout << "Program Now Deconstructing Tree and Exiting..." << endl;
}

//public
bool BET::isEmpty() const
{
  return (root == NULL);
}

//public makeEmpty, calls private
void BET::makeEmpty()
{
  makeEmpty(root);
}

//private makeEmpty
void BET::makeEmpty(BETPtr& t) const
{
  if(t != NULL)
    {
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete(t);
        if(t->left != NULL)
            t->left = NULL;
        if(t->right != NULL)
            t->right = NULL;
        t=NULL;
    }
}

//public
void BET::insertPrefixOperator(char token)
{
  BinaryNode* newNode = new BinaryNode;
  newNode->info.whichType = OPERATOR;
  newNode->info.theContent.opsymbol = token;
 
  newNode->left = s.top();
  s.pop();
  newNode->right = s.top();
  s.pop();

  s.push(newNode);
  root = newNode;
}

//public
void BET::insertPostfixOperator(char token)
{
  BinaryNode* newNode = new BinaryNode;
  newNode->info.whichType = OPERATOR;
  newNode->info.theContent.opsymbol = token;
  newNode->right = s.top();
  s.pop();
  newNode->left = s.top();
  s.pop();
  
  s.push(newNode);
  root = newNode;
}

//public
void BET::insertOperand(char token)
{
  BinaryNode* newNode = new BinaryNode;
  newNode->info.whichType = OPERAND;
  newNode->info.theContent.variable = token;
  newNode->left = NULL;
  newNode->right = NULL;
  s.push(newNode);
}

//public
void BET::preorder() const
{
  if (isEmpty())
    cout << "Empty Tree";
  else 
    preorder(root);
  
  cout << endl;
}

//private
void BET::preorder(BETPtr t) const
{
  if (t != NULL)
  {
    if ((t->info.whichType) == OPERAND)
        cout << t->info.theContent.variable << " ";
    else
        cout << t->info.theContent.opsymbol << " ";
    preorder(t->left);
    preorder(t->right);
  }
}

//public
void BET::inorder() const
{
  if (isEmpty())
    cout << "Empty Tree";
  else 
    inorder(root);
  
  cout << endl;
}

//private
void BET::inorder(BETPtr t) const
{
  if (t != NULL)
  {
    if (t->left != NULL)
      cout << "( ";
    inorder(t->left);
    if ((t->info.whichType) == OPERAND)
      cout << t->info.theContent.variable << " ";
    else
      cout << t->info.theContent.opsymbol << " ";
    inorder(t->right);
    if (t->right != NULL)
      cout << ") ";
  }
}

//public
void BET::postorder() const
{
  if (isEmpty())
    cout << "Empty Tree";
  else 
    postorder(root);
  
  cout << endl;
}

//private
void BET::postorder(BETPtr t) const
{
  if (t != NULL)
  {
    postorder(t->left);
    postorder(t->right);
    if ((t->info.whichType) == OPERAND)
      cout << t->info.theContent.variable << " ";
    else
      cout << t->info.theContent.opsymbol << " ";
  }
}
