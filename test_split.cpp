/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include <iostream>
#include "split.h"

int main(int argc, char* argv[])
{
    Node *Node4 = new Node(2, nullptr);
    Node *Node3 = new Node(3, Node4);
    Node *Node2 = new Node(4, Node3);
    Node *Node1 = new Node(5, Node2);
    Node *NodeOdd = nullptr;
    Node *NodeEven = nullptr;
    split(Node4, NodeOdd, NodeEven);
}
