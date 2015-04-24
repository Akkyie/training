//
//  list.h
//  List
//
//  Created by Akio Yasui on 4/20/15.
//  Copyright (c) 2015 Akio Yasui. All rights reserved.
//

#ifndef __LIST_DEFINED__
#define __LIST_DEFINED__

#include <stdlib.h>
#include <stdbool.h>

typedef int elem_t;

typedef struct _List List;

List * list_create();
void list_delete(List * list);

bool list_push(List * list, elem_t value);
bool list_pop(List * list, elem_t  * ptr);
bool list_unshift(List * list, elem_t value);
bool list_shift(List * list, elem_t * ptr);

#endif
