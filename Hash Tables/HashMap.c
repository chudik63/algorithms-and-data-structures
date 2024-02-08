#include <stdio.h>
#include <string.h>
#include <malloc.h>
#define INITIAL_CAPACITY 32
#define FILL_FACTOR 75

typedef struct {
    char* key;
    int value;
} item_t;

typedef struct {
    item_t* elements;
    int capacity;
    int count;
} Hashmap;

void init(Hashmap*);
int getHash(Hashmap*,char*);
void resize(Hashmap*);
void add(Hashmap*,char*,int);
void delete(Hashmap*,char*);
int get(Hashmap*,char*);

int main()
{
    Hashmap hashmap;
    init(&hashmap);
    add(&hashmap, "ten", 10);
    add(&hashmap, "eleven", 11);
    add(&hashmap, "twelve", 12);
    delete(&hashmap, "twelve");
    printf("%d\n%d\n%d", get(&hashmap, "ten"), get(&hashmap, "eleven"), get(&hashmap, "twelve"));
}

void init(Hashmap* this)
{   
    this->capacity = INITIAL_CAPACITY;
    this->count = 0;
    this->elements = (item_t*)malloc(this->capacity * sizeof(item_t));

    for (int i = 0; i < this->capacity; i++)
    {
        this->elements[i].key = NULL;
    }
}

int getHash(Hashmap* this, char* key)
{
    long sum = 0;
    int length = strlen(key);
    for (int i = 0; i < length; i++)
    {
        sum += key[i] * (i + 1);
    }
    
    return sum % this->capacity;
}

void resize(Hashmap* this)
{
    if (this->count * 100 / this->capacity >= FILL_FACTOR)
    {   
        this->elements = (item_t*)realloc(this->elements, this->capacity * 2 * sizeof(item_t));
        this->capacity *= 2;

        for (int i = this->capacity / 2; i < this->capacity; i++)
        {
            this->elements[i].key = NULL;
        }

        for (int i = this->capacity / 2 - 1; i >= 0; i--)
        {
            if (this->elements[i].key != NULL && getHash(this, this->elements[i].key) != i)
            {   
                add(this, this->elements[i].key, this->elements[i].value);
                this->elements[i].key = NULL;
            }
        }
    }
}

void add(Hashmap* this, char* _key, int _value)
{      
    resize(this);
    int hash = getHash(this, _key);
    if (this->elements[hash].key != NULL && this->elements[hash].key != _key)
    {   
        while (this->elements[hash % this->capacity].key != NULL)
        {   
            hash++;
        }
        hash %= this->capacity;
    }
    this->elements[hash].key = _key;
    this->elements[hash].value = _value;
    this->count++;
}

void delete(Hashmap* this, char* _key)
{
    int hash = getHash(this, _key);
    if (this->elements[hash].key == _key) 
    {
        this->elements[hash].key = NULL;
    } else {
        for (int i = hash + 1; i < hash + this->capacity; i++)
        {
            if (this->elements[i % this->capacity].key == _key)
            {
                this->elements[i % this->capacity].key = NULL;
            }
        }   
    }
}

int get(Hashmap* this, char* _key)
{
    int hash = getHash(this, _key);
    if (this->elements[hash].key == _key) 
    {
        return this->elements[hash].value;
    } else {
        for (int i = hash + 1; i < hash + this->capacity; i++)
        {
            if (this->elements[i % this->capacity].key == _key)
            {
                return this->elements[i % this->capacity].value;
            }
        }   
    }
    return -1;
}
