#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdlib.h>
#include <stdint.h> 
#include <string.h>
#include <stdio.h>

#define DELIMITER ":"

#define DEFAULT_SIZE 200

/**
 * @brief - This struct is the item that goes in the buckets
 *  
 * @param key - The key the vaule is indexed at
 * @param value - The data being stored 
 */
typedef struct hashtable_item {
    char* key;
    void* value;
} ht_item;

/**
 * @brief - This struct is the hashtable data structure
 *  
 * @param ht_item - A pointer to the hashtables buckets
 * @param size - The total amount of allocated buckets
 * @param length - The total numbers of buckets actively used
 */
typedef struct hashtable {
    ht_item* items;
    size_t size;
    size_t length;
} ht;

/**
 * @brief - This Function creates and allocates a new hashtable pointer 
 *  
 * @return - Returns a pointer to the newly created hashtable if successful,
 *  or a NULL pointer if an error occured
 */
ht* create_ht();

/**
 * @brief - This Function frees a hashtable and all items within it
 *  
 * @param table - A pointer to the hashtable being destroyed
 * 
 * @return - Returns nothing to error check check if the pointer is NULL
 */
void destroy_ht(ht* table);

/**
 * @brief - This Function is the public insert call, it checks if the 
 * hashtable needs to be expanded, then inserts the key on the hashtable. 
 *  
 * @param table - A pointer to the hashtable being inserted into
 * @param key - the key to be hashed and inserted
 * @param value - The vaule being stored on the hashtable
 * @param overwrite - A flag that if the key already exists on the table 
 * for it to be overwritten
 * 
 * @return - Returns an int to error check with, if -1 an error occurred
 */
int insert_key(ht* table, char* key, void* value, int overwrite);

/**
 * @brief - This is the private inertion functyion that actually handles
 * the insertion onto the table after its been expanded, if need be
 *  
 * @param table - A pointer to the hashtable being inserted into
 * @param key - the key to be hashed and inserted
 * @param value - The vaule being stored on the hashtable
 * @param overwrite - A flag that if the key already exists on the table 
 * for it to be overwritten
 * 
 * @return - Returns an int to error check with, if -1 an error occurred
 */
int insert_key_helper(ht* table, char* key, void* value, int overwrite);

/**
 * @brief - This Function retrieves the vaule associated with a key 
 *  
 * @param table - A pointer to the hashtable being searched
 * @param key - The key that is being searched 
 * 
 * @return - Returns the vaule pointer if successful or returns a 
 * NULL pointer on a error
 */
void* get_value(ht* table, char* key);

/**
 * @brief - This Function deletes the vaule associated with a key 
 *  
 * @param table - A pointer to the hashtable being searched
 * @param key - The key that is being deleted 
 * 
 * @return - Returns an int to error check with, if -1 an error occurred
 */
int delete_key(ht* table, char* key);

//Credit: Dan Bernstein, djb2
//http://www.cse.yorku.ca/~oz/hash.html
/**
 * @brief - This Function hashes the key to allow it to be stored
 *  
 * @param key - The key that is being hashed 
 * 
 * @return - Returns the uint32 hash or a -1 to error check with
 */
uint32_t hash(char* key);

/**
 * @brief - This Function expands the capacity of the hashtable
 *  
 * @param table - The hashtable that is being expanded
 * 
 * @return - Returns an int to error check with, if -1 an error occurred
 */
int expand_size(ht* table);

#endif
