/* A Fibonacci heap datatype.
   Copyright 1998, 1999, 2000, 2001 Free Software Foundation, Inc.
   Contributed by Daniel Berlin (dan@cgsoftware.com).

_________________________________________________________
Modified by Marin Kobilarov (mkobilar@robotics.usc.edu)
to work with externally defined key of arbitrary size (dimension)
and externally defined abstract key comparator
_________________________________________________________

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify it
under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.

You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING.  If not, write to
the Free Software Foundation, 59 Temple Place - Suite 330,
Boston, MA 02111-1307, USA.  */

/* Fibonacci heaps are somewhat complex, but, there's an article in
   DDJ that explains them pretty well:

   http://www.ddj.com/articles/1997/9701/9701o/9701o.htm?topic=algoritms

   Introduction to algorithms by Corman and Rivest also goes over them.

   The original paper that introduced them is "Fibonacci heaps and their
   uses in improved network optimization algorithms" by Tarjan and
   Fredman (JACM 34(3), July 1987).

   Amortized and real worst case time for operations:

   ExtractMin: O(lg n) amortized. O(n) worst case.
   DecreaseKey: O(1) amortized.  O(lg n) worst case.
   Insert: O(2) amortized. O(1) actual.
   Union: O(1) amortized. O(1) actual.  */

#ifndef _FIBHEAP_H_
#define _FIBHEAP_H_

#include "stdlib.h"
#include "ansidecl.h"

#ifdef __cplusplus
extern "C" {
#endif

// the size, minimum, and comparator are provided externally
typedef void* fibheapkey_t;

typedef struct fibheap {
  size_t nodes;
  struct fibnode* min;
  struct fibnode* root;
} * fibheap_t;

typedef struct fibnode {
  struct fibnode* parent;
  struct fibnode* child;
  struct fibnode* left;
  struct fibnode* right;
  fibheapkey_t key;
  void* data;
  unsigned int degree : 31;
  unsigned int mark : 1;
} * fibnode_t;

fibheap_t fibheap_new PARAMS((void));
fibnode_t fibheap_insert PARAMS((fibheap_t, fibheapkey_t, void*));
int fibheap_empty PARAMS((fibheap_t));
fibheapkey_t fibheap_min_key PARAMS((fibheap_t));
void fibheap_replace_key PARAMS((fibheap_t, fibnode_t, fibheapkey_t));
void* fibheap_replace_key_data
    PARAMS((fibheap_t, fibnode_t, fibheapkey_t, void*));
void* fibheap_extract_min PARAMS((fibheap_t));
void* fibheap_min PARAMS((fibheap_t));
void* fibheap_replace_data PARAMS((fibheap_t, fibnode_t, void*));
void* fibheap_delete_node PARAMS((fibheap_t, fibnode_t));
void fibheap_delete PARAMS((fibheap_t));
fibheap_t fibheap_union PARAMS((fibheap_t, fibheap_t));

void fibheap_clear PARAMS((fibheap_t heap));

#ifdef __cplusplus
}
#endif

#endif /* _FIBHEAP_H_ */
