/*
 * node234.h
 *
 *  Created on: Apr 1, 2019
 *      Author: Nicholas Leung
 *      		nml170001
 */

#ifndef NODE234_H_
#define NODE234_H_

// Node for 234 tree
class node234
{
	public:
		// Keys
		int leftKey;
		int midKey;
		int rightKey;
		// Child node pointers
		node234* leftLeft;
		node234* leftMid;
		node234* rightMid;
		node234* rightRight;
		// Constructors
		node234();
		node234(int key);
		node234(int key, node234* left, node234* right);
		// Functions
		bool is2Node();
		bool is3Node();
		bool is4Node();
		bool isLeaf();
};

// Default constructor
node234::node234()
{
	leftKey = 0;
	midKey = 0;
	rightKey = 0;
	leftLeft = nullptr;
	leftMid = nullptr;
	rightMid = nullptr;
	rightRight = nullptr;
}

// Constructor with just one key
node234::node234(int key)
{
	leftKey = key;
	midKey = 0;
	rightKey = 0;
	leftLeft = nullptr;
	leftMid = nullptr;
	rightMid = nullptr;
	rightRight = nullptr;
}

// Constructor to create a 2 node
node234::node234(int key, node234* left, node234* right)
{
	leftKey = key;
	midKey = 0;
	rightKey = 0;
	leftLeft = left;
	leftMid = right;
	rightMid = nullptr;
	rightRight = nullptr;
}

// If a 2 node
bool node234::is2Node()
{
	return (leftKey != 0 && midKey == 0 && rightKey == 0);
}

// If a 3 node
bool node234::is3Node()
{
	return (leftKey != 0 && midKey != 0 && rightKey == 0);
}

// If a 4 node
bool node234::is4Node()
{
	return (leftKey != 0 && midKey != 0 && rightKey != 0);
}

// If a leaf
bool node234::isLeaf()
{
	return (leftLeft == nullptr && leftMid == nullptr &&
			rightMid == nullptr && rightRight == nullptr);
}

#endif /* NODE234_H_ */
