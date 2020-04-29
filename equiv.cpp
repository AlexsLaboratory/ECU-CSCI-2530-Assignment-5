// CSCI 2530
// Assignment: 4
// Author: Alex Lowe
// File: equiv.cpp
// Tab stops: none

/*
 * This module provides an implementation of combine/equivalent equivalence relations.
*/

#include <cstdio>
#include <iostream>
#include "equiv.h"

// newER(int n) returns a new equivalence relation over 1 to n. Initially all of
// the equivalence classes are {1}, {2},..., {n}

ER newER(int n)
{
  ER R = new int[n + 1];
  for (int i = 1; i <= n; i++)
  {
    R[i] = i;
  }
  return R;
}

// showER(ER e, int n) shows the boss array r of equivalence relation r, where r
// is over {1, ..., n}. ShowER is only for debugging.

void showER(ER e, int n)
{
  if (n == 0)
  {
    return;
  }
  else
  {
    showER(e, n - 1);
    printf("E[%i] = %i\n", n, e[n]);
  }
}

// leader(ER e, int x) returns the current leader of the equivalence class that
// contains x in equivalence relation r.

int leader(ER e, int x)
{
  if (e[x] == x)
  {
    return x;
  }
  else
  {
    return leader(e, e[x]);
  }
}

// combine(ER e, int x, int y) merges the equivalence classes of x and y in
// equivalence relation r.

void combine(ER e, int x, int y)
{
  if (!equivalent(e, x, y))
  {
    e[leader(e, x)] = leader(e, y);
  }
}

// equivalent (ER e, int x, int y) returns true if x and y are currently in
// the same equivalence class in equivalence relation r and will return false
// otherwise.

bool equivalent(ER e, int x, int y)
{
  return leader(e, x) == leader(e, y);
}

// destroyER (ER e) recycles the memory occupied by r.

void destroyER(ER e)
{
  delete[] e;
}