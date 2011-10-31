/**
* @file
* @brief the head file of the Index module
* @author elf@ZJU
* @version 1.0
*/

#ifndef _Index_H
#define _Index_H

#include "miniSQL.h"

/**
* @class Address
* @brief the address of a record
*/
class Address{
	int blockId;	///< the block ID
	int offset;		///< the offset in the block
};

/**
* @class BaseNode
* @brief the base class of the B+ tree nodes
*/
class BaseNode{
public:
	int blockId;
	bool isRoot;
	bool isLeaf;
	char type;
	int parent;
	int next;
	int capacity;	///< the capcity of children, 4000/size - 1
	int num;		///< the number of children

	bool dirty;
	bool lock;
	int time;

	char data[4000];
};

/*
* @brief drop the index of indexId
* @param indexId the index ID
* @return void
*/
void DropIndex(int indexId);

/*
* @brief find a key in the index tree
* @param indexId the index ID
* @param key the index key to be found in the index.
*		The type may be int, string, float
* @return Address the address to store the record
*/
template <class Type>
Address FindIndex(int indexId, Type key);

/*
* @brief insert a key into index tree
* @param indexId the index ID
* @param key the index key to be inserted into the index.
*		The type may be int, string, float
* @return Address the address to store the record
*/
template <class Type>
Address InsertIndex(int indexId, Type key);

/*
* @brief delete a key from the index tree
* @param indexId the index ID
* @param key the index key to be deleted from the index.
*		The type may be int, string, float
* @return void
*/
template <class Type>
void DeleteIndex(int indexId, Type key);

#endif // _Index_H