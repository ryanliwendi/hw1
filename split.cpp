/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions.
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <iostream>
using namespace std;

/* Add a prototype for a helper function here if you need */
// Pushs node cur into the list with root node n
void push_back(Node*& cur, Node* n);

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
  // WRITE YOUR CODE HERE
  if (in == nullptr)
    return;
  bool flag = in -> value % 2;
  Node* temp = in -> next;
  if (flag)
    push_back(odds, in);
  else
    push_back(evens, in);
  in = temp;
  split(in, odds, evens);
}

/* If you needed a helper function, write it here */
void push_back(Node*& cur, Node* n)
{
  if (cur == nullptr)
  {
    cur = n;
    cur -> next = nullptr;
  }
  else if (cur -> next == nullptr)
  {
    cur -> next = n;
    cur -> next -> next = nullptr;
  }
  else
    push_back(cur -> next, n);
}
