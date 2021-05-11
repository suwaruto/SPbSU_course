#include "list.h"
#include <stdlib.h>
#include <stdio.h>

List l_prepend(List l, int v)
{
    List h = (List)malloc(sizeof(struct Node));
    h->value = v;
    h->next = l;
    return h;
}

List l_remove(List l, int ind)
{
    if(!ind)
    {
        List n = l->next;
        free(l);
        return n;
    }
    else
    {
        List c = l;
        while(--ind)
            c = c->next;
        List d = c->next;
        c->next = c->next->next;
        free(d);
        return l;
    }
}

void l_print(List l)
{
    for(; l; l=l->next)
    {
        printf("\t%d", l->value);
    }
    puts("");
}

List l_append(List list, int value)
{
    List cur = list;
    if (list == EMPTY_LIST)
    {
        list = (List)malloc(sizeof(struct Node));
        list->next = NULL;
        list->value = value;
        return list;
    }
    else
        {
            while (cur->next != NULL)
                cur = cur->next;
            cur->next = (List)malloc(sizeof(struct Node));
            cur->next->next = NULL;
            cur->next->value = value;
        }
    return list;
}

List l_insert_to(List list, int position, int value)
{
    if (list == EMPTY_LIST)
    {
        list = (List)malloc(sizeof(struct Node));
        list->next = NULL;
        list->value = value;
        return list;
    }
    List prev = NULL, cur = list;
    for (int i = 0; i < position && cur != NULL; i++)
    {
        prev = cur;
        cur = cur->next;
    }
    List new = (List)malloc(sizeof(struct Node));
    new->next = cur;
    new->value = value;
    if (prev != NULL)
        prev->next = new;
    else
        return new;
    return list;
}

List l_insert_keep_sorting(List list, int value)
{
    if (list == EMPTY_LIST)
    {  
        list = (List)malloc(sizeof(struct Node));
        list->value = value;
        return list;
    }
    List prev = NULL, cur = list;
    while (value >= cur->value)
    {
        prev = cur;
        cur = cur->next;
    }
    List new = (List)malloc(sizeof(struct Node));
    new->next = cur;
    new->value = value;
    if (prev != NULL)
        prev->next = new;
    else
        return new;
    return list;
}
