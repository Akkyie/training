//
//  list.c
//  List
//
//  Created by Akio Yasui on 4/20/15.
//  Copyright (c) 2015 Akio Yasui. All rights reserved.
//

#include "akkyie-list.h"

typedef struct _ListElement {
	struct _ListElement * previous;
	struct _ListElement * next;
	elem_t value;
} ListElement;

struct _List {
	struct _ListElement * first;
	struct _ListElement * last;
};

List * list_create() {
	List * list = (List *)malloc(sizeof(List));
	return list;
}

void list_delete(List * list) {
	if (list->first) {
		ListElement * element = list->first;
		do {
			ListElement * next = element->next;
			free(element);
		} while (next);
	}
	free(list);
}

bool list_push(List * list, elem_t value) {
	if (!list) {
		return false;
	}

	ListElement * element = (ListElement *)malloc(sizeof(ListElement));
	element->value = value;
	element->previous = list->last;
	element->next = NULL;

	if (list->last)
		list->last->next = element;
	else
		list->first = element;

	list->last = element;

	return true;
}

bool list_pop(List * list, elem_t * ptr) {
	if (!list || !list->last) {
		return false;
	}

	elem_t value = list->last->value;
	ListElement * newLast = list->last->previous;
	free(list->last);
	if (newLast)
		newLast->next = NULL;
	else
		list->first = NULL;
	list->last = newLast;
	*ptr = value;

	return true;
}

bool list_unshift(List * list, elem_t value) {
	if (!list) {
		return false;
	}

	ListElement * element = (ListElement *)malloc(sizeof(ListElement));
	element->value = value;
	element->previous = NULL;
	element->next = list->first;

	if (list->first)
		list->first->previous = element;
	else
		list->last = element;

	list->first = element;

	return true;
}

bool list_shift(List * list, elem_t * ptr) {
	if (!list || !list->first) {
		return false;
	}

	elem_t value = list->first->value;
	ListElement * newFirst = list->first->next;
	free(list->first);
	if (newFirst)
		newFirst->previous = NULL;
	else
		list->last = NULL;
	list->first = newFirst;
	*ptr = value;

	return true;
}
