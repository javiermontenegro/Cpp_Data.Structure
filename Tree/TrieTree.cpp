/*********************************************************************
* Filename:   Chaining.cpp
* Author:     Javier Montenegro (javiermontenegro.github.io)
* Copyright:  @2019
* Details:    function to implement trie tree.
*********************************************************************/

#include<iostream>
#include<string.h>
#include<stdbool.h>
using namespace std;

typedef struct trie
{
    struct trie *arr[26];
    bool isEndofWord;
} trie;

trie *createNode()
{
    trie *nn = new trie();
    for (int i = 0; i < 26; i++)
        nn->arr[i] = NULL;
    nn->isEndofWord = false;
    return nn;
}

void insert(trie *root, char* str)
{
    for (int i = 0; i < strlen(str); i++)
    {
        int j = str[i] - 'a';
        if (root->arr[j])
        {
            root = root->arr[j];
        }
        else
        {
            root->arr[j] = createNode();
            root = root->arr[j];
        }//End if
    }//End for

    root->isEndofWord = true;
}//End insert

bool search(trie *root, char* str, int index)
{
    if (index == strlen(str))
    {
        if (!root->isEndofWord)
            return false;
        return true;
    }//End if

    int j = str[index] - 'a';
    if (!root->arr[j])
        return false;
    return search(root->arr[j], str, index + 1);
}//End search

bool deleteString (trie *root, char* str, int index)
{
    if (index == strlen(str))
    {
        if (!root->isEndofWord)
            return false;
        root->isEndofWord = false;
        for (int i = 0; i < 26; i++)
            return false;
        return true;
    }//End if

    int j = str[index] - 'a';
    if (!root->arr[j])
        return false;
    bool var = deleteString (root, str, index + 1);
    
    if (var)
    {
        root->arr[j] = NULL;
        if (root->isEndofWord)
            return false;
        else
        {
            int i;
            for (i = 0; i < 26; i++)
                if (root->arr[i])
                    return false;
            return true;
        }//End if
    }//End if
}//End delete

int main()
{
    printf("\nTrie Tree\n");

    trie *root = createNode();
    insert(root, "hello");
    insert(root, "world");
    
    int a = search(root, "hello", 0);
    int b = search(root, "word", 0);
    
    printf("%d %d ", a, b);
    
    return 0;
}//End main