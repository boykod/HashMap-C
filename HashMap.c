/*
 * HashMap.c
 *
 *  Created on: 15 February. 2019 year.
 *      Author: D
 */

/**************************************************************************//**
* Includes
*****************************************************************************/
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "HashMap.h"

/**************************************************************************//**
* Global Variables
*****************************************************************************/
struct table *table;

struct table *createTable(uint8_t size) {
    uint8_t i;
    struct table *t = (struct table*)malloc(sizeof(struct table));
    t->size = size;
    t->list = (struct node**)malloc(sizeof(struct node*)*size);
    for(i=0; i<size; i++)
        t->list[i] = NULL;
    return t;
}

uint8_t hashCode(struct table *t, uint8_t key) {
    if(key<0)
        return -(key%t->size);
    return key%t->size;
}

void insert(struct table *t, uint8_t key, uint8_t val) {
  uint8_t pos = hashCode(t, key);
    struct node *list = t->list[pos];
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    struct node *temp = list;
    while(temp){
        if(temp->key == key){
            temp->val = val;
            return;
        }
        temp = temp->next;
    }
    newNode->key = key;
    newNode->val = val;
    newNode->next = list;
    t->list[pos] = newNode;
}
/**************************************************************************//**
* newHashMap
*
* @param hashMapSize -> size of Map array
*****************************************************************************/
void newHashMap(uint8_t hashMapSize) {
    table = createTable(hashMapSize);
}
/**************************************************************************//**
* getHashMap
*
* @param K -> key
* @return val -> value which was set for K
*****************************************************************************/
uint8_t getHashMap(uint8_t key) {
  uint8_t pos = hashCode(table, key);
    struct node *list = table->list[pos];
    struct node *temp = list;
    while(temp){
        if(temp->key == key){
            return temp->val;
        }
        temp = temp->next;
    }
    return -1;
}
/**************************************************************************//**
* putHashMap
*
* @param K -> key
* @param V -> value
*****************************************************************************/
void putHashMap(uint8_t K, uint8_t V) {
  insert(table, K, V);
}
