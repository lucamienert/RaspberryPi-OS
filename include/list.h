#ifndef RASPOS_LIST_H_
#define RASPOS_LIST_H_

#pragma once

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#include <kernel/process.h>

struct List
{
	struct List *next;
};

struct HeadList
{
	struct List* next;
	struct List* tail;
};

void append_list_tail(struct HeadList *list, struct List *item);
struct List* remove_list_head(struct HeadList *list);
bool is_list_empty(struct HeadList *list);
struct List* remove_list(struct HeadList *list, int wait);

#endif