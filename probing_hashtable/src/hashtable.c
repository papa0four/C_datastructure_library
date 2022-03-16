#include "../include/hashtable.h"

/**
 * @brief - This Function creates and allocates a new hashtable pointer 
 *  
 * @return - Returns a pointer to the newly created hashtable if successful,
 *  or a NULL pointer if an error occured
 */
ht* create_ht()
{
    ht* table = (ht *) malloc(sizeof(ht));
    if (table == NULL)
    {
        goto table_error;
    }
    table->length = 0;
    table->size = DEFAULT_SIZE;
    table->items = calloc(table->size, sizeof(ht_item));
    if (table->items == NULL)
    {
        goto item_error;
    }
    return table;
    item_error:
    free(table);
    table_error:
    return NULL;
}

/**
 * @brief - This Function frees a hashtable and all items within it
 *  
 * @param table - A pointer to the hashtable being destroyed
 * 
 * @return - Returns nothing to error check check if the pointer is NULL
 */
void destroy_ht(ht* table)
{
    if (table != NULL)
    {
        if (table->items != NULL)
        {
            if(table->length>0)
            {
                for (size_t i = 0; i < table->size; i++)
                {
                    if (table->items[i].key)
                    {
                        free(table->items[i].key);
                    }
                    if (table->items[i].value)
                    {
                        free(table->items[i].value);
                    }
                }
            }
            free (table->items);
        }
        free(table);
    }
}

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
int insert_key(ht* table, char* key, void* value, int overwrite)
{
    int return_val = -1;
    if(table != NULL && key != NULL && value != NULL)
    {
        if(table->length >= (table->size / 2))
        {
            if(expand_size(table) == -1)
            {
                goto set_error;
            }
        }
        return_val = insert_key(table, key, value, overwrite);
    }
    set_error:
    return return_val;
}

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
int insert_key_helper(ht* table, char* key, void* value, int overwrite)
{
    int return_val = -1;
    if(table != NULL && key != NULL && value != NULL)
    {
        uint32_t hashed_key = hash(key);
        uint32_t index = hashed_key & (uint32_t)(table->size - 1);
        while ( table->items[index].key != NULL )
        {
            if(strncmp(key, table->items[index].key, strlen(key)) == 0 && 
                strlen(key) == strlen(table->items[index].key) &&
                overwrite == 1)
            {
                table->items[index].value = value;
                table->length++;
                return_val = 1;
            }
            index++;
            if(index >= table->size)
            {
                index = 0;
            }
        }
        if( table->items[index].key == NULL )
        {
            table->items[index].key = calloc(strlen(key) + 1, sizeof(char));
            if(table->items[index].key  == NULL)
            {
            goto insert_error;
            }
            if(memcpy(table->items[index].key, key, strlen(key)) == NULL)
            {
                if(table->items[index].key )
                {
                    free(table->items[index].key );
                }
                goto insert_error;
            }
            table->items[index].value = value;
            table->length++;
            return_val = 1;
        }
    }
    insert_error:
    return return_val;
}
    
/**
 * @brief - This Function retrieves the vaule associated with a key 
 *  
 * @param table - A pointer to the hashtable being searched
 * @param key - The key that is being searched 
 * 
 * @return - Returns the vaule pointer if successful or returns a 
 * NULL pointer on a error
 */
void* get_value(ht* table, char* key)
{
    void* return_val = NULL;
    if(table != NULL && key != NULL)
    {
        uint32_t hashed_key = hash(key);
        uint32_t index = hashed_key & (uint32_t)(table->size - 1);
        while ( table->items[index].key != NULL )
        {
            if(strncmp(key, table->items[index].key, strlen(key)) == 0 && 
                strlen(key) == strlen(table->items[index].key))
            {
                return_val = table->items[index].value;
            }
            index++;
            if (index >= table->size)
            {
                index = 0;
            }
        }
    }
    return return_val;

}

/**
 * @brief - This Function deletes the vaule associated with a key 
 *  
 * @param table - A pointer to the hashtable being searched
 * @param key - The key that is being deleted 
 * 
 * @return - Returns an int to error check with, if -1 an error occurred
 */
int delete_key(ht* table, char* key)
{
    int return_val = -1;
    if(table != NULL && key != NULL)
    {
        uint32_t hashed_key = hash(key);
        uint32_t index = hashed_key & (uint32_t)(table->size - 1);
        while ( table->items[index].key != NULL )
        {
            if(strncmp(key, table->items[index].key, strlen(key)) == 0 && 
                strlen(key) == strlen(table->items[index].key))
            {
                if(table->items[index].key)
                {
                    free(table->items[index].key);
                }
                if(table->items[index].value)
                {
                    free(table->items[index].value);
                }
                table->items[index].key = NULL;
                table->items[index].value = NULL;
                table->length--;
                return_val = 1;
            }
            index++;
            if (index >= table->size)
            {
                index = 0;
            }
        }
    }
    return return_val;
}

//Credit: Dan Bernstein, djb2
//http://www.cse.yorku.ca/~oz/hash.html
/**
 * @brief - This Function hashes the key to allow it to be stored
 *  
 * @param key - The key that is being hashed 
 * 
 * @return - Returns the uint32 hash or a -1 to error check with
 */
uint32_t hash(char* key)
{
    uint32_t return_val = -1;
    if (key != NULL)
    {
        uint32_t hash = 5381;
        int c;

        while ((c = *key++))
        {
            hash = ((hash << 5) + hash) + c; 
        }
        return_val = hash;
    }
    return return_val;
}

/**
 * @brief - This Function expands the capacity of the hashtable
 *  
 * @param table - The hashtable that is being expanded
 * 
 * @return - Returns an int to error check with, if -1 an error occurred
 */
int expand_size(ht* table)
{
    int return_val = -1;
    if(table != NULL)
    {
        size_t new_size = table->size * 2;
        if (new_size < table->size)
        {
            goto expand_error;
        }
        ht_item* new_items = calloc(new_size, sizeof(ht_item));
        if (new_items == NULL)
        {
            goto expand_error;
        }
        ht_item* old_items = table->items;
        table->items = new_items;
        for (size_t i = 0; i < table->size ; i++)
        {
            if ( old_items[i].key != NULL )
            {
                if ( insert_key(table, old_items[i].key, old_items[i].value, 0) == -1 )
                {
                    goto expand_error;
                }
            }
        }
        table->size = new_size;
        if (old_items != NULL)
        {
            free(old_items);
        }
        return_val = 1;
    }
    expand_error:
    return return_val;
}