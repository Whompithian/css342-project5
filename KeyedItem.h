/*
 * @file    KeyedItem.h
 *          Addapted from:
 *          Carrano, F. M. (2007). Trees. In M. Hirsch (Ed.) "Data Abstraction
 *              & Problem Solving with C++: Walls and Mirrors" (5th ed.) p.
 *              555. Boston, MA: Pearson Education, Inc.
 * @brief   KeyedItem class for the threaded binary search tree. Only contains
 *          the search key value. Needs to be changed or subclassed to add
 *          other data elements.
 * @author  Brendan Sweeney, SID 1161836
 * @date    December 8, 2011
 */

#ifndef _KEYEDITEM_H
#define	_KEYEDITEM_H

typedef int KeyType;


class KeyedItem
{
public:

    KeyedItem();

    KeyedItem(const KeyType& keyValue);

    /** Gets the key of this item.
     * @pre This item was constructed with a key value.
     * @post None.
     * @return A (presumably) unique key value to identify this item.
     */
    KeyType getKey() const;

private:

    KeyType searchKey;  // searchable key for this item

}; // end KeyedItem


#endif	/* _KEYEDITEM_H */
