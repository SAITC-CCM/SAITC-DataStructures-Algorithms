/**
 * @author ErnoMitrovic
 * @brief Class implementation for a hash table
 */

#include <functional>
#include <vector>
#include <sstream>
using namespace std;

#ifndef HASH_PAIR
#define HASH_PAIR
/**
 * @brief Implementation of a hash pair class
 * @tparam Key key datatype
 * @tparam Val value datataype
 */
template <typename Key, typename Val>
class HashPair{
    private:
        Key key;
        Val value;
        // This is to encapsulate the hash pair class
        template <typename P, typename Q>
        friend class HashTable;

        /**
        * @brief Simple constructor
        * @param key the pair's key
        * @param data the pair's value
        */
        HashPair(Key key, Val data){
            this->key = key;
            this->value = data;
        }

        void update(Val value){
            this->value = value;
        }

    public:
        /**
        * @brief used for comparisons
        */
        bool operator==(const Key &key){
            return this->key == key;
        }
};
#endif

#ifndef HASH_TABLE
#define HASH_TABLE
/**
 * @brief Implementation of a hash table class
 * @tparam Key key datatype
 * @tparam Val value datataype
 */
template <typename Key, typename Val>
class HashTable{
    private:
        // This value shall be initialized in the constructor, but may be automatized
        unsigned const int SIZE;
        vector<HashPair<Key, Val>> *hashTable;
        /**
        * @brief The hash function that will be used to allocate the pairs
        * @param key The pair's key
        * @return The index in which it will be allocated
        */
        int hashFunction(Key key){
            hash<Key> keyHash;
            return keyHash(key) % SIZE;
        }

    public:
        /**
        * @brief Simple constructor
        * @param size by default considering 1024 buckets
        */
        HashTable(int size = 1024) : SIZE(size){
            table = new vector<HashPair<Key, Val>>[size];
        }
        /**
        * The destructor that will dealocate the memory of the vector pointer
        */
        ~HashTable(){
            delete[] table;
        }
        void update(Key key, Val value){
            int index = fh(key);
            auto &currentBucket = hashTable[index];
            auto pair = find(currentBucket.begin(), currentBucket.end(), key);
            pair.update(value);
        }

        /**
        * @brief Inserts a unique pair to the hash table according to the key, if it exists, update it
        * @param key the key to add
        * @param value the value to add
        */
        void insert(Key key, Val value){
            int index = hashFunction(key);
            auto &currentBucket = hashTable[index];
            // Checks if the hashtable doesnt contain the value
            if (!count(currentBucket.begin(), currentBucket.end(), key))
                currentBucket.push_back(Pair(key, value));
        }

        /**
        * @brief Removes the pair with the specified key
        * @param key the key to add
        * @param value the value to add
        * @return true if it was successfully added
        * @return false otherwise
        */
        bool remove(Key key){
            int index = fh(key);
            auto &currentBucket = hashTable[index];
            auto pair = find(currentBucket.begin(), currentBucket.end(), key);
            if (pair == currentBucket.end())
                return false;
            currentBucket.erase(pair);
            return true;
        }

        /**
        * @brief Given a key, retrieve the object with that key
        * @param key the key to search
        * @return the value of that pair
        * @throw invalid argument if the key doesnt exist
        */
        Val get(Key key){
            int index = fh(key);
            auto &currentBucket = hashTable[index];
            auto pair = find(currentBucket.begin(), currentBucket.end(), key);
            if (pair == currentBucket.end())
            {
                stringstream ss;
                ss << "Key " << key << " doesn't exist";
                throw invalid_argument(ss.str());
            }
            return (pair->value);
        }
};

#endif
