#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

struct node{
    void *object_ptr;
    int pos, id;
    struct node *nextobject_ptr;
    char string[50];
};

struct node* InsertNodeWithId(struct node **anchor_ptr, int id);
struct node* InsertNodeAtPos(struct node **anchor_ptr, int pos);
void SortNodes(struct node *cnt_ptr);
int DeleteNodeByPos(struct node **achor_ptr, int nmbr);
int DeleteNodeById(struct node **anchor_ptr, int id);
struct node *GetNodeById(struct node *cnt_ptr, int id);
struct node *GetNodeByPos(struct node *cnt_ptr, int cnt);

uint8_t nodedebugsw;

#endif // MAIN_H_INCLUDED
