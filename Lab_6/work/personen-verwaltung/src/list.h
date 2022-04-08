#ifndef _MODEL_H_
#define _MODEL_H_

#define NAME_LEN 20

typedef struct {
  char         name[NAME_LEN];
  char         first_name[NAME_LEN];
  unsigned int age;
} person_t;


/**
 * @brief Inserts the struct person_t in the sorted List
 * @param[IN] personToInsert  The specified structure person_t which needs to be inserted in the list.
 */
void insert (person_t personToInsert);

/**
 * @brief Removes the given struct person_t from the sorted List
 * @param[INOUT] personToInsert  The specified structure person_t which needs to be inserted in the list.
 */
void insert (person_t personToInsert);
// Needs methods declaration for insert, remove and clear

#endif // _MODEL_H_
