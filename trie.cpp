#include<stdio.h>o
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])
#define ALPHABET_SIZE (26)
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
using namespace std;
struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
    bool isLeaf;
};

struct TrieNode *getNode(void)
{
    struct TrieNode *pNode=NULL;
    pNode=(struct TrieNode *)malloc(sizeof(struct TrieNode));
    if (pNode)
    {
        int i;
        pNode->isLeaf=false;

        for(i=0;i< ALPHABET_SIZE;i++)
            pNode->children[i]=NULL;
    }
    return pNode;
}

void insert(struct TrieNode *root,const char *key)
{
    int level;
    int length=strlen(key);
    int index;
    struct TrieNode *pCrawl=root;
    for(level=0;level<length;level++)
    {
        index=CHAR_TO_INDEX(key[level]);
        if(!pCrawl->children[index])
            pCrawl->children[index]=getNode();

        pCrawl=pCrawl->children[index];
    }
    pCrawl->isLeaf=true;
}

bool search(struct TrieNode *root,const char *key)
{
    int level,cnt=0;
    int length=strlen(key);
    int index;
    struct TrieNode *pCrawl=root;
    for(level=0;level<length;level++)
    {
        index=CHAR_TO_INDEX(key[level]);
        if(!pCrawl->children[index])
            return false;
        ++cnt;
        pCrawl=pCrawl->children[index];
        if(cnt==length)
            return true;
    }
    return (pCrawl !=NULL && pCrawl->isLeaf);
}

int main()
{
    char keys[][10]={"alphonse","gideon"};
    char output[][32]={"Not present","present"};
    struct TrieNode *root=getNode();
    int i;
    for(i=0;i< ARRAY_SIZE(keys);i++)
        insert(root,keys[i]);
    printf("%s----%s\n", "alphonse",output[search(root,"alo")]);
    printf("%s----%s\n", "gideon",output[search(root,"gide")]);
    return 0;
}



