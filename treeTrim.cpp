/*
 * @file    TreeTrim.cpp
 * @brief   Drive class to test a threaded binary search tree and its inorder
 *          iterator. An integer, n > 0, is read from the command line and the
 *          integers from 1 to n are inserted into an empty TBST in random
 *          order. That tree is copied uses the assignment operator for its
 *          class. The copy of the tree then has all even integer elements
 *          deleted. An inorder iterator is called on the original tree and its
 *          elements are printed to cout as they are encountered. Then, the
 *          same is done for the copy tree.
 * @author  Brendan Sweeney, SID 1161836
 * @date    December 8, 2011
 */

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>

#include "ThreadedBST.h"

using namespace std;


/*
 * 
 */
int main(int argc, char** argv)
{
    ThreadedBST oak, spruce;    // test trees
    int n = atoi(argv[1]);      // number of items in trees
    int foliage[n];             // array for input items
    srand(time(NULL));

    // populate array with integers from 1 to n
    for (int i = 0; i < n; ++i)
    {
        foliage[i] = i + 1;
    } // end for (int i = 0; i < n; ++i)

    // shuffle elements in array
    for (int i = 0; i < n; ++i)
    {
        int temp, jump;

        jump = rand() % n;
        temp = foliage[i];
        foliage[i] = foliage[jump];
        foliage[jump] = temp;
    } // end for (int i = 0; i < n; ++i)

    try
    {
        // create first tree
        for (int i = 0; i < n; ++i)
        {
            oak.searchTreeInsert(foliage[i]);
        }
    }
    catch (TreeException e)
    {
        cerr << "TreeException: main cannot add items to tree" << endl;
    } // end try

    try
    {
        // create copy tree
        spruce = oak;
    }
    catch (TreeException e)
    {
        cerr << "TreeException: main cannot copy tree" << endl;
    } // end try

    try
    {
        // delete all even elements from copy
        for (int i = 2; i <= n; i += 2)
        {
            spruce.searchTreeDelete(i);
        } // end for (int i = 2; i <= n; i += 2)
    }
    catch (TreeException e)
    {
        cerr << "TreeException: main cannot delete items from tree" << endl;
    } // end try

    // inorder iterators for each tree
    ThreadedBST::Inorder squirrel(oak.begin());
    ThreadedBST::Inorder chipmunk(spruce.begin());

    // traverse original tree inorder and display items
    while(squirrel != oak.end())
    {
        cout << (*squirrel).getKey() << ' ';
        ++squirrel;
    } // end while(squirrel != oak.end())
    cout << (*squirrel).getKey() << endl;

    // traverse copy tree inorder and display items
    while(chipmunk != spruce.end())
    {
        cout << (*chipmunk).getKey() << ' ';
        ++chipmunk;
    } // end while(chipmunk != spruce.end())
    cout << (*chipmunk).getKey() << endl;

    return (EXIT_SUCCESS);
}
