#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

//Hashmap implementation using seperate chaining.

template <typename V>
class MapNode {
public:
    string key;
    V value;
    MapNode * next;
    
    MapNode(string key, V value) {
        this->key = key;
        this->value = value;
        next = NULL;
    }
    
    ~MapNode() {
        delete next;
    }
};

template <typename V>
class ourmap {

    MapNode<V> ** buckets;
    int count;
    int numBuckets;
    
public:
    ourmap()  {
        count = 0;
        numBuckets = 5;
        buckets = new MapNode<V> * [numBuckets];
        for (int i = 0; i < numBuckets; i++) {
            buckets[i] = NULL;
        }
    }
    
    ~ourmap() {
        for (int i = 0; i < numBuckets; i++) {
            delete buckets[i];
        }
        delete [] buckets;
    }
    
    int size() {
        return count;
    }
    
private:
    int gethashcode(string key){
        int coefficient = 1;
        int hashcode = 0;
        for (int i = key.length() - 1; i >= 0 ; i--) {
            hashcode += key[i] * coefficient;
            hashcode = hashcode % numBuckets;
            coefficient *= 37;
            coefficient = coefficient % numBuckets;
        }
        return hashcode % numBuckets;
    }
    
    void rehash() {
        MapNode<V> ** temp = buckets;
        buckets = new MapNode<V> * [2 * numBuckets];
        for (int i = 0; i < (2 * numBuckets); i++) {
            buckets[i] = NULL;
        }
        int oldBucketCount = numBuckets;
        numBuckets *= 2;
        count = 0;
        
        for (int i = 0; i < oldBucketCount; i++) {
            MapNode<V> * head = temp[i];
            while (head != NULL) {
                string key = head->key;
                string value =head->value;
                insert(key, value);
                head = head->next;
            }
        }
        
        for (int i = 0; i < oldBucketCount; i++) {
            MapNode<V> * head = temp[i];
            delete head;
        }
        delete [] temp;
    }
    
public:
    void insert(string key, V value) {
        int bucketIndex = gethashcode(key);
        MapNode<V> * head = buckets[bucketIndex];
        while (head != NULL) {
            if (key == head->key) {
                head->value = value;
                return;
            }
            head = head->next;
        }
        head = buckets[bucketIndex];
        MapNode<V> * node = new MapNode<V>(key, value);
        node->next = head;
        buckets[bucketIndex] = node;
        count++;
        
        double loadFactor = (double) count/ (double) numBuckets;
        if (loadFactor > 0.7) {
            rehash();
        }
    }
    
    V remove(string key) {
        int bucketIndex = gethashcode(key);
        MapNode<V> * head = buckets[bucketIndex];
        MapNode<V> * prev = NULL;
        while (head != NULL) {
            if (head->key == key) {
                if (prev == NULL) {
                    buckets[bucketIndex] = head->next;
                }
                else {
                    prev->next = head->next;
                }
                V value = head->value;
                head->next = NULL;
                delete head;
                count--;
                return value;
            }
            prev = head;
            head = head->next;
        }
        return 0;
    }
    
    V getvalue(string key) {
        int bucketIndex = gethashcode(key);
        MapNode<V> * head = buckets[bucketIndex];
        while (head != NULL) {
            if (key == head->key) {
                return head->value;
            }
            head = head->next;
        }
        return 0;
    }
};

int main() {
    return 0;
}

