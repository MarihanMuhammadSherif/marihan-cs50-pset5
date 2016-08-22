/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "dictionary.h"






 
 
 
 //djb2 hash 
int hash (const char* word)
{
    int hash = 0;
    int n;
    for (int i = 0; word[i] != '\0'; i++)
    {
        // alphabet case
        if(isalpha(word[i]))
            n = word [i] - 'a' + 1;
        
        // comma case
        else
            n = 27;
            
        hash = ((hash << 3) + n) % HASHMAX;
    }
    return hash;    
}
 
 


/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */ 
bool load(const char* dictionary)
{
    // TODO
    
    FILE* dicpt=fopen(dictionary,"r");
    if(dicpt==NULL)
    {return false;
        
    }
    char word[LENGTH +1];
  while( fscanf(dicpt,"%s\n",word)!=EOF)  
 {   
     ++dicsize;
    node* new_node=malloc(sizeof(node));
    strcpy(new_node->stirng,word) ;
    
      int index=hash(word);
    if(hashtable[index]==NULL)
    {
        hashtable[index]=new_node;
        new_node->next=NULL;    
    }
    else
    {
        new_node->next=hashtable[index];
        hashtable[index]=new_node;
    }
    
}
fclose(dicpt);
    return true;
}


/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{



int index=has(word);
node* cursor= hashtable[index];
while(cursor!=NULL)
{
    if(strcmp(cursor->string,tolower(word))==0)
    return true;
    else
    cursor=cursor->next;
}

    // TODO
    return false;
}


/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    return dicsize;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    // TODO
    int i;
    for(i=0;i<HASMAX;)
    {
        if(hashtable[i]==NULL)
        ++i;
        
        else{
        
        while(hashtable[i]!=NULL)
        {
            node* cursor=hashtable[i];
            hashtable[i]=cursor->next;
            free(cursor);
            
        }
        }
        
    }
    
    
    return true;
}
