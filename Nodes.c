// The functions contained in this file are pretty dummy
// and are included only as a placeholder. Nevertheless,
// they *will* get included in the static library if you
// don't remove them :)
//
// Obviously, you 'll have to write yourself the super-duper
// functions to include in the resulting library...
// Also, it's not necessary to write every function in this file.
// Feel free to add more files in this project. They will be
// included in the resulting library.

// A function adding two integers and returning the result
#include <stdlib.h>
#include <stdio.h>

#include "Nodes.h"

uint8_t nodenodedebugsw = 0;

struct node* InsertNodeAtPos(struct node **anchor_ptr, int pos){

    if(nodedebugsw == 1)
        printf("Checking if adding node to pos:%d is possible. ", pos);

    if((*anchor_ptr) == 0){
            if(pos == 0){
                struct node *newnode_ptr;
                newnode_ptr = malloc(sizeof(struct node));
                if(newnode_ptr == 0){
                    printf("Cannot allocate memory for newnode_ptr\n");
                        return 0;
                }
                newnode_ptr->nextobject_ptr = 0;
                newnode_ptr->pos = pos;
                newnode_ptr->id = 0;
                (*anchor_ptr) = newnode_ptr;
                if(nodedebugsw == 1)
                    printf("List is empty. Adding node to the beginning of the list with attributes: id:%d, pos:%d\n", (*anchor_ptr)->id, (*anchor_ptr)->pos);
                return newnode_ptr;

            }
            else{
                if(nodedebugsw == 1)
                    printf("Couldn't add node to pos:%d because the list is empty\n", pos);
                return 0;
            }
    }
    else{
        struct node *cnt_ptr;
        cnt_ptr = (*anchor_ptr);
        struct node *newnode_ptr;
        while(cnt_ptr->nextobject_ptr != 0){
            cnt_ptr = cnt_ptr->nextobject_ptr;
        }
        while(cnt_ptr->nextobject_ptr != 0 && cnt_ptr->nextobject_ptr->pos != pos ){
            cnt_ptr = cnt_ptr->nextobject_ptr;
            if(nodedebugsw == 1)
                printf(". ");
        }
        if(cnt_ptr->nextobject_ptr->pos == pos && cnt_ptr->nextobject_ptr == 0){
            newnode_ptr = malloc(sizeof(struct node));
            if(newnode_ptr == 0){
                if(nodedebugsw == 1)
                    printf("Cannot allocate memory for newnode_ptr\n");
                return 0;
            }
            newnode_ptr->nextobject_ptr = 0;
            newnode_ptr->pos = pos;
            cnt_ptr->nextobject_ptr=newnode_ptr;
            SortNodes((*anchor_ptr));
            if(nodedebugsw == 1)
                printf("Added node at pos:%d at the end of the list\n", pos);
            return newnode_ptr;
        }
        if(cnt_ptr->nextobject_ptr->pos == pos && cnt_ptr->nextobject_ptr != 0){
            newnode_ptr = malloc(sizeof(struct node));
            if(newnode_ptr == 0){
                if(nodedebugsw == 1)
                    printf("Cannot allocate memory for newnode_ptr\n");
                return 0;
            }
            newnode_ptr->nextobject_ptr = cnt_ptr->nextobject_ptr;
            cnt_ptr->nextobject_ptr = newnode_ptr;
            SortNodes((*anchor_ptr));
            if(nodedebugsw == 1)
                printf("Added node at pos:%d on the list\n", pos);
            return newnode_ptr;

        }
        return 0;
    }
}

struct node* InsertNodeWithId(struct node **anchor_ptr, int id){
    if(nodedebugsw == 1)
        printf("Checking if node with id: %d is already in the list. ", id);
    if((*anchor_ptr) == 0){
        struct node *newnode_ptr;
        newnode_ptr = malloc(sizeof(struct node));
        if(newnode_ptr == 0){
            if(nodedebugsw == 1)
                printf("Cannot allocate memory for newnode_ptr\n");
            return 0;
        }
        newnode_ptr->nextobject_ptr = 0;
        newnode_ptr->pos = 0;
        newnode_ptr->id = id;
        (*anchor_ptr) = newnode_ptr;
        if(nodedebugsw == 1)
            printf("Not in list\n. Adding node to the beginning of the list with attributes: id:%d, pos:%d\n", (*anchor_ptr)->id, (*anchor_ptr)->pos);
        return newnode_ptr;
    }
    else{

        struct node *cnt_ptr = (*anchor_ptr);

        while(cnt_ptr->id != id && cnt_ptr->nextobject_ptr != 0){
            cnt_ptr = cnt_ptr->nextobject_ptr;
            if(nodedebugsw == 1)
                printf(". ");
        }
        if(cnt_ptr->id != id && cnt_ptr->nextobject_ptr == 0){
            struct node *newnode_ptr;
            newnode_ptr = malloc(sizeof(struct node));
            if(newnode_ptr == 0){
                if(nodedebugsw == 1)
                    printf("Cannot allocate memory for newnode_ptr\n");
                return 0;
            }
            else{
                newnode_ptr->nextobject_ptr = 0;
                newnode_ptr->id = id;
                cnt_ptr->nextobject_ptr=newnode_ptr;
                SortNodes((*anchor_ptr));
                if(nodedebugsw == 1)
                    printf("Adding node with id:%d to the end of the list with attributes: id:%d, pos:%d\n", cnt_ptr->nextobject_ptr->id, \
                           cnt_ptr->nextobject_ptr->id, cnt_ptr->nextobject_ptr->pos);
                return newnode_ptr;
            }
        }
        if(cnt_ptr->id == id){
            if(nodedebugsw == 1)
                printf("Found node with id:%d. No need to add new node\n",id);
            return cnt_ptr;
        }
        return 0;
    }
}

int DeleteNodeByPos(struct node **anchor_ptr, int nmbr){

    if((*anchor_ptr) == 0){
        if(nodedebugsw == 1)
            printf("Couldn't delete node at pos:%d. list is empty\n", nmbr);
        return 0;
    }
    if((*anchor_ptr)->pos == 0){
        struct node *del_ptr;
        del_ptr = (*anchor_ptr);
        (*anchor_ptr) = (*anchor_ptr)->nextobject_ptr;
        free(del_ptr);
        SortNodes((*anchor_ptr));
        if(nodedebugsw == 1)
            printf("Deleted node at pos:%d\n", nmbr);
        return 1;
        }
    else{
        struct node *cnt_ptr = (*anchor_ptr);
        while(cnt_ptr->nextobject_ptr != 0 && cnt_ptr->nextobject_ptr->pos != nmbr)
            cnt_ptr = cnt_ptr->nextobject_ptr;
        if(cnt_ptr->nextobject_ptr == 0){
            if(nodedebugsw == 1)
                printf("Couldn't delete node at pos:%d. Wanted node is not in list\n", nmbr);
            return 0;
        }
        else{
            struct node *del_ptr;
            del_ptr = cnt_ptr->nextobject_ptr;
            cnt_ptr->nextobject_ptr = cnt_ptr->nextobject_ptr->nextobject_ptr;
            free(del_ptr);
            SortNodes((*anchor_ptr));
            if(nodedebugsw == 1)
                printf("Deleted node at pos:%d\n", nmbr);
            return 1;
        }

    }
}

int DeleteNodeById(struct node **anchor_ptr, int id){


    if((*anchor_ptr) == 0){
        if(nodedebugsw == 1)
            printf("Couldn't delete node with id:%d. list is empty\n", id);
        return 0;
    }
    if((*anchor_ptr)->id == id){
        struct node *del_ptr;
        del_ptr = (*anchor_ptr);
        (*anchor_ptr) = (*anchor_ptr)->nextobject_ptr;
        free(del_ptr);
        SortNodes((*anchor_ptr));
        if(nodedebugsw == 1)
            printf("Deleted node with id:%d on pos 0\n", id);
        return 1;
    }
    else{
        struct node *cnt_ptr;
        cnt_ptr = (*anchor_ptr);
        while(cnt_ptr->nextobject_ptr != 0 && cnt_ptr->nextobject_ptr->id != id)
            cnt_ptr = cnt_ptr->nextobject_ptr;
        if(cnt_ptr->nextobject_ptr == 0){
            if(nodedebugsw == 1)
                printf("Couldn't delete node with id:%d. Wanted node is not in list\n", id);
            return 0;
        }
        else{
            struct node *del_ptr;
            del_ptr = cnt_ptr->nextobject_ptr;
            cnt_ptr->nextobject_ptr = cnt_ptr->nextobject_ptr->nextobject_ptr;
            free(del_ptr);
            SortNodes((*anchor_ptr));
            if(nodedebugsw == 1)
                printf("Deleted node with id:%d\n", id);
            return 1;
        }

    }
}

void SortNodes(struct node *cnt_ptr){

    int i = 0;
    if(nodedebugsw == 1)
        printf("Sorting & counting nodes ");
    if(cnt_ptr == 0){
        if(nodedebugsw == 1)
            printf(". . . no nodes to sort\n");
    }
    else{
        while(cnt_ptr->nextobject_ptr!= 0){
            cnt_ptr->pos = i++;
            cnt_ptr = cnt_ptr->nextobject_ptr;
            if(nodedebugsw == 1)
                printf(". ");
        }
    }
    //if(cnt_ptr != 0 && cnt_ptr->next_ptr == 0){
      //  cnt_ptr->nmbr = i;

    if(nodedebugsw == 1)
        printf("done!\n there is/are %d node(s)\n", i++);

}

struct node *GetNodeById(struct node *cnt_ptr, int id){
    if(nodedebugsw == 1)
        printf("Entered \"struct node *GetNodeById()\"\n");

    if(cnt_ptr == 0){
        if(nodedebugsw == 1){
            printf("if cnt_ptr == 0\n");
            printf("Couldn't find node with id: %d. List is empty.\n", id);
        }
        cnt_ptr = 0;
        return cnt_ptr;
    }
    else{
        if(nodedebugsw == 1)
            printf("searching the whole list");
        while(cnt_ptr->nextobject_ptr != 0 && cnt_ptr->id != id){
            if(nodedebugsw == 1)
                printf(". ");
            cnt_ptr = cnt_ptr->nextobject_ptr;
        }
        if(nodedebugsw == 1)
            printf("\n");
        if(cnt_ptr->id == id){
            if(nodedebugsw == 1)
                printf("Found node with id: %d\n", id);
            return cnt_ptr;
        }
        else{
            if(nodedebugsw == 1)
                printf("Couldn't find node with id: %d\n", id);
            cnt_ptr = 0;
            return cnt_ptr;
        }
    }
}

struct node *GetNodeByPos(struct node *cnt_ptr, int pos){

    if(cnt_ptr == 0){
        if(nodedebugsw == 1)
            printf("Couldn't find node at pos: %d. List is empty.\n", pos);
        cnt_ptr = 0;
        return cnt_ptr;
    }

    if(cnt_ptr != 0 && cnt_ptr->pos == pos){
        if(nodedebugsw == 1)
            printf("Found node at pos: %d\n", pos);
        return cnt_ptr;
    }
    else{
        while(cnt_ptr->nextobject_ptr != 0 && cnt_ptr->pos != pos)
            cnt_ptr = cnt_ptr->nextobject_ptr;
        if(cnt_ptr->pos == pos){
            if(nodedebugsw == 1)
                printf("Found node at pos: %d\n", pos);
            return cnt_ptr;
        }
        else{
            if(nodedebugsw == 1)
                printf("Couldn't find node at pos: %d\n", pos);
            cnt_ptr = 0;
            return cnt_ptr;
        }
    }
}
