// CSCI 2530
// Assignment: 4
// Author:     Alex Lowe
// File:       equiv.h
// Tab stops:  None

// These #ifndef and #define lines make it so that, if this file is
// read more than once by the compiler, its body is skipped on all
// but the first time it is read.

#ifndef EQUIV_H
#define EQUIV_H

// An equivalence relation is an array of integers.
// So ER abbreviates int*.

typedef int* ER;

// Public functions

ER   newER      (int n);
void destroyER  (ER e);
bool equivalent (ER e, int x, int y);
void combine    (ER e, int x, int y);

// The following are advertised here solely for debugging.  These must
// only be used for debugging.

void showER(ER e, int n);
int leader(ER e, int x);


#endif
