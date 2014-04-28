#ifndef __BSTNODE_H__
#define __BSTNODE_H__
#include "CityInfo.h"

class BSTNode {
protected:
	BSTNode *right, *left, *parent;
	CityInfo *key;
public:
	BSTNode(CityInfo *k = NULL, BSTNode *r = NULL, BSTNode *l = NULL, BSTNode *p = NULL) {
		key = k; right = r; left = l; parent = p; }
	void add (CityInfo * city) {
		if ( (*city) < (*key) && left == NULL) {
			// build a left child
			left = new BSTNode(city, NULL, NULL, this);
		} else if ((*city) < (*key) && left != NULL) {
			left->add(city);
		}
		if ((*city) >= (*key) && right == NULL) {
			// build a right child
			right = new BSTNode(city, NULL, NULL, this);
		} else if ((*city) >= (*key) && right != NULL) {
			right->add(city);
		}
	}

	void inOrder(ostream &ostr) {
		if (left != NULL) {
			left->inOrder(ostr);
		}
		ostr << *key << endl;
		if (right != NULL) {
			right->inOrder(ostr);
		}
	}

	void preOrder(ostream &ostr) {
		ostr << *key << endl;
		if (left != NULL) {
			left->preOrder(ostr);
		}
		if (right != NULL) {
			right->preOrder(ostr);
		}
	}

	void postOrder(ostream &ostr) {
		if (left != NULL) {
			left->postOrder(ostr);
		}
		if (right != NULL) {
			right->postOrder(ostr);
		}
		ostr << *key << endl;
	}
};

#endif