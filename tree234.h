/*
 * tree234.h
 *
 *  Created on: Apr 1, 2019
 *      Author: Nicholas Leung
 *      		nml170001
 */

#ifndef TREE234_H_
#define TREE234_H_

#include "node234.h"

// 234 tree
class tree234
{
	public:
		node234* root;
		tree234();
		void insert(int key);
		void display(node234* node);

};

// Default constructor
tree234::tree234()
{
	root = nullptr;
}

// Insert key into tree
void tree234::insert(int key)
{
	node234* current = root;
	node234* parent = root;

	// If the tree is empty
	if (root == nullptr)
	{
		root = new node234(key);
	}
	else
	{
		while (true)
		{
			// If current is not a 4 node and not a leaf
			// Continue moving down tree
			if (!current->isLeaf() && !current->is4Node())
			{
				parent = current;
				// If current is a 2 node
				if (current->is2Node())
				{
					if (key < current->leftKey)
					{
						current = current->leftLeft;
					}
					else
					{
						current = current->leftMid;
					}
				}
				// If current is a 3 node
				else
				{
					if (key < current->leftKey)
					{
						current = current->leftLeft;
					}
					else if (key < current->midKey)
					{
						current = current->leftMid;
					}
					else
					{
						current = current->rightMid;
					}
				}
			}

			// If current is a 4 node
			else if (current->is4Node())
			{
				// If parent is a 2 node
				if (parent->is2Node())
				{
					// If current is the right child of parent
					if (parent->leftKey < current->leftKey)
					{
						parent->midKey = current->midKey;
						parent->leftMid = new node234(current->leftKey,
								current->leftLeft, current->leftMid);
						parent->rightMid = new node234(current->rightKey,
								current->rightMid, current->rightRight);
					}
					// If current is the left child of parent
					else
					{
						parent->midKey = parent->leftKey;
						parent->rightMid = parent->leftMid;
						parent->leftKey = current->midKey;
						parent->leftLeft = new node234(current->leftKey,
								current->leftLeft, current->leftMid);
						parent->leftMid = new node234(current->rightKey,
								current->rightMid, current->rightRight);
					}
					// Continue moving down the tree
					// Go down to left child
					if (key < parent->leftKey)
					{
						current = parent->leftLeft;
					}
					// Go down to mid child
					else if (key < parent->midKey)
					{
						current = parent->leftMid;
					}
					// Go down to right child
					else
					{
						current = parent->rightMid;
					}

				}
				// If parent is a 3 node
				else if (parent->is3Node())
				{
					// If current is the right child of parent
					if (parent->midKey < current->leftKey)
					{
						parent->rightKey = current->midKey;
						parent->rightMid = new node234(current->leftKey,
								current->leftLeft, current->leftMid);
						parent->rightRight = new node234(current->rightKey,
								current->rightMid, current->rightRight);
					}
					// If current is the middle child of parent
					else if(parent->leftKey < current->leftKey)
					{
						parent->rightKey = parent->midKey;
						parent->rightRight = parent->rightMid;
						parent->midKey = current->midKey;
						parent->leftMid = new node234(current->leftKey,
								current->leftLeft, current->leftMid);
						parent->rightMid = new node234(current->rightKey,
								current->rightMid, current->rightRight);
					}
					// If current is the left child of the parent
					else
					{
						parent->rightKey = parent->midKey;
						parent->rightRight = parent->rightMid;
						parent->midKey = parent->leftKey;
						parent->rightMid = parent->leftMid;
						parent->leftKey = current->midKey;
						parent->leftLeft = new node234(current->leftKey,
								current->leftLeft, current->leftMid);
						parent->leftMid = new node234(current->rightKey,
								current->rightMid, current->rightRight);
					}
					// Continue moving down tree
					// Go down to left left child
					if (key < parent->leftKey)
					{
						current = parent->leftLeft;
					}
					// Go down to left middle child
					else if (key < parent->midKey)
					{
						current = parent->leftMid;
					}
					// Go down to right middle child
					else if (key < parent->rightKey)
					{
						current = parent->rightMid;
					}
					// Go down to right right child
					else
					{
						current = parent->rightRight;
					}
				}
				// If the 4 node is the root
				else
				{
					root = new node234(current->midKey);
					root->leftLeft = new node234(current->leftKey,
							current->leftLeft, current->leftMid);
					root->leftMid = new node234(current->rightKey,
							current->rightMid, current->rightRight);
					parent = root;
					// Continue moving down tree
					// Go down to left child
					if (key < parent->leftKey)
					{
						current = parent->leftLeft;
					}
					// Go down to right child
					else
					{
						current = parent->leftMid;
					}
				}
			}

			// If a leaf node and not a 4 node
			else
			{
				// If the leaf is a 2 node
				if (current->is2Node())
				{
					// If added key should be the left key
					if (key < current->leftKey)
					{
						current->midKey = current->leftKey;
						current->leftKey = key;
					}
					// If added key should be the right key
					else
					{
						current->midKey = key;
					}
				}
				// If the leaf is a 3 node
				else
				{
					// If added key should be the left key
					if (key < current->leftKey)
					{
						current->rightKey = current->midKey;
						current->midKey = current->leftKey;
						current->leftKey = key;
					}
					// If added key should be the middle key
					else if (key < current->midKey)
					{
						current->rightKey = current->midKey;
						current->midKey = key;
					}
					// If added key should be the right key
					else
					{
						current->rightKey = key;
					}
				}
				break;
			}
		}
	}
}

// Display the tree using in order traversal
void tree234::display(node234* node)
{
	if (node != nullptr)
	{
		// If a 2 node
		if (node->is2Node())
		{
			display(node->leftLeft);
			std::cout << node->leftKey << std::endl;
			display(node->leftMid);
		}
		// If a 3 node
		else if (node->is3Node())
		{
			display(node->leftLeft);
			std::cout << node->leftKey << std::endl;
			display(node->leftMid);
			std::cout << node->midKey << std::endl;
			display(node->rightMid);
		}
		// If a 4 node
		else
		{
			display(node->leftLeft);
			std::cout << node->leftKey << std::endl;
			display(node->leftMid);
			std::cout << node->midKey << std::endl;
			display(node->rightMid);
			std::cout << node->rightKey << std::endl;
			display(node->rightRight);
		}
	}
}

#endif /* TREE234_H_ */
