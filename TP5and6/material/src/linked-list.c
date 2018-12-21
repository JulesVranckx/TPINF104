#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "link-types.h"
#include "linked-list.h"


extern int number_of_students;

/********************   read_file_content   ********************
* read file and extract information to store it in array
**************************************************************/

void read_file_content(Student_t * array, FILE * file){

  int i = 0;
  int ret = 0;

  do {
    ret = fscanf(file, "%s %s %d", array[i].lastname, array[i].firstname, &array[i].group);
    i++;
    number_of_students++;
    }
  while (ret != EOF);

  number_of_students--;

}

/********************    new_link   *******************
* Create a new link of type Link_t: the field next is initialized to NULL
* Returns the adress of the new link.
********************************************************/
Link_t * new_link(Student_t student){
  Link_t * Ptr = (Link_t*)malloc(sizeof(Link_t));
  Ptr->student = student;
  Ptr->next = NULL;
  return Ptr;
}

/********************    chain   *******************
* Add a new link (new_link) at the beginning of an existing
* linked list (beginning).
* Returns the address of the first element of the list.
********************************************************/
Link_t * chain(Link_t * beginning, Link_t * new_link){
  Link_t * Ptr;
  Ptr = new_link;
  Ptr->next = beginning;
  return Ptr;
}

/********************   display_linked_list   *******************
* Display (using printf) the information contained in the
* linked list.
********************************************************/
void display_linked_list(Link_t * list){

  Link_t * current = list;

  while (current != NULL)
  {
    printf("%s %s, GRP %d\n", current->student.lastname, current->student.firstname, current->student.group);
    current = current->next;
  }
}

/********************   search   *******************
* Search for a link corresponding to a student last
* name
* beginning: first link of the list used for searching
* name_to_search: last name of the student to search
* returns the firts link for which the name equals
* name_to_search
********************************************************/
Link_t * search (Link_t * beginning, char * name_to_search)
{
  Link_t * found_link = beginning;

  while (found_link != NULL)
  {
    if (strcmp(found_link->student.lastname, name_to_search) == 0 )
      break;
    found_link  = found_link->next;
  }

  return found_link;
}


/********************   insert   *******************
* Insert a link in a linked list
* beginning: first link of the original list
* new_link: link to insert
* returns the firts link of the list after insertion
********************************************************/
Link_t * insert (Link_t * beginning, Link_t * new_link)
{
  Link_t * list_after_insertion;
  Link_t * avant = beginning;
  Link_t * apres = beginning->next;

  char * lastname = new_link->student.lastname;

  if (beginning == NULL ||  strcmp(lastname, beginning->student.lastname) <= 0)
  {
    return chain(beginning, new_link);
  }
  else
  {
    list_after_insertion = beginning;
    while (apres != NULL && strcmp(lastname, apres->student.lastname) > 0)
    {
      avant = apres;
      apres = apres->next;
    }
    avant->next = chain(apres, new_link);

  }

  return list_after_insertion;
}

/********************   sort   *******************
* Sort the content of the linked list.
********************************************************/
Link_t * sort (Link_t * beginning)
{
  Link_t * sorted_list = (Link_t * )malloc(sizeof(Link_t));

  printf("Youon");
  Link_t * iter = beginning;
  Link_t * new;

  while (iter != NULL)
  {
    new = iter;
    iter = iter->next;
    sorted_list = insert(sorted_list, new);

  }

  return sorted_list;
}

/********************   free_list   *******************
* Free the memory used by the linked list.
********************************************************/
void free_list(Link_t * list){

  Link_t * iter = list;
  Link_t * current;

  while (iter != NULL)
  {
    current = iter;
    iter = iter->next;
    free(current);
  }

}
