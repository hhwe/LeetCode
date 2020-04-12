typedef struct
{
    List *head;
    fun hashFun;
    int *elem;
} HashTable;

int HashFunc(int key)
{
    return key % 16;
}

void HashInsert(HashTable *hb, int key)
{
    int index = HashFunc(key);
}
