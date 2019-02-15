/*
 * HashMap.h
 *
 *  Created on: 15 February. 2019 year.
 *      Author: D
 */

#ifndef HASHMAP_HASHMAP_H_
#define HASHMAP_HASHMAP_H_

struct node {
  uint8_t key;
  uint8_t val;
    struct node *next;
};

struct table {
  uint8_t size;
    struct node **list;
};

/**************************************************************************//**
* Function prototype
*****************************************************************************/
void newHashMap(uint8_t hashMapSize);
void putHashMap(uint8_t K, uint8_t V);
uint8_t getHashMap(uint8_t key);

#endif /* HASHMAP_HASHMAP_H_ */
