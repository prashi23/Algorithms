/*
A C program that will find its way through a maze using DFS.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int const TRUE = 1;
int const FALSE = 0;
int debugMode = 0;

typedef struct mazeStruct
{
    char **arr;
    int xsize, ysize;
    int xstart, ystart;
    int xend, yend;
} maze;

typedef struct stackStruct
{
    int xpos, ypos;
    struct stackStruct *next;
}stack;

void IntializeStack(stack **stackHead){
    *stackHead = NULL;


}

stack* Top(stack **head){
    return(*head);
}


//free the allocated memory
/*void FreeMaze(maze **maze){
    int i;
    for(i = 0; i < maze.xsize +2; i++){
        free(maze->arr[i]);
    }free(maze->arr);
}*/

//check if empty
int CheckEmpty(stack *head){
    if(head == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void PopStack(stack **head, int debugMode){
    stack *temp = *head;
    if(debugMode == TRUE){
        printf("\nPopping From Stack: (%d,%d)\n",temp->xpos, temp->ypos );
    }
    if(*head != NULL){
        *head = (*head)->next;
        free(temp);
    }
    else{
        return;
    }
}
void resetStack(stack** head){
    stack* temp = *head;
    while(*head != NULL){
        *head = (*head)->next;
        free(temp);
    }
}

void PushStack(stack **head, int xpos, int ypos){
    stack *temp = (stack *)malloc(sizeof(stack));
    temp->xpos = xpos;
    temp->ypos = ypos;
    temp->next = *head;
    *head = temp;
}

void PrintMaze(maze *maze){
    int i;
    int j;

    for (i = 0; i < maze->xsize + 2; i++)
    {
        for (j = 0; j < maze->ysize + 2; j++)
            printf ("%c", maze->arr[i][j]);
        printf("\n");
    }
}

void DisplayStack (stack* head){
    stack *temp = head;

    /* base case */
    if ( temp == NULL ) {
        return;
    }
    /* recursive case */

    DisplayStack (temp->next);
    printf("(%d,%d)", temp->xpos, temp->ypos);
    return;


}

void debugModeInit( int argc, char **argv){

  debugMode = FALSE;
  int i;
  for ( i = 0; i < argc; i++ ){
    if (strcmp(argv[i], "-d") == 0){
      debugMode = TRUE;
    }
  }
}

int main (int argc, char **argv)
{
    debugModeInit(argc,argv);
    int xsize = 0, ysize = 0;
    int xstart = 0, ystart = 0;
    int xend = 0, yend = 0;

    int xpos, ypos;
    char **string;

    maze m1;
    int i,j;

    stack* head;

    IntializeStack(&head);
    FILE *src;
/*
    //debugMode
    for(i = 0; i < argc; i++) {
        if (strcmp(argv[i], "-d") == TRUE) {
            printf("\n Debug Mode\n");
            debugMode = TRUE;
        }
        else{
            string = &argv[i];
        }
    }
    printf("HELLOOOOO1");
    argv[1] = *string;
*/

    /* verify the proper number of command line arguments were given */
    if(argc != 2) {
        printf("Usage: %s <input file name>\n", argv[0]);
        exit(-1);
    }

    /* Try to open the input file. */
    if ( ( src = fopen( argv[1], "r" )) == NULL )
    {
        printf ( "Can't open input file: %s", argv[1] );
        exit(-1);
    }

    /* read in the size, starting and ending positions in the maze */
    fscanf (src, "%d %d", &m1.xsize, &m1.ysize);
    if (m1.xsize <= 0 || m1.ysize <= 0){
        printf("Invalid size: Enter Valid Dimesions\n");
        exit(0);
    }
    fscanf (src, "%d %d", &m1.xstart, &m1.ystart);
    if((m1.xstart > m1.xsize || m1.xstart < 0 ) || (m1.ystart > m1.ysize || m1.ystart < 0) ){
        printf("Invalid start: Enter Valid Dimesions\n");
        exit(0);
    }
    fscanf (src, "%d %d", &m1.xend, &m1.yend);
    if((m1.xend > m1.xsize || m1.xend < 0 ) || (m1.yend > m1.ysize || m1.yend < 0) ){
        printf("Invalid End: Enter Valid Dimesions\n");
        exit(0);
    }

    /* print them out to verify the input */
    printf ("size: %d, %d\n", m1.xsize, m1.ysize);
    printf ("start: %d, %d\n", m1.xstart, m1.ystart);
    printf ("end: %d, %d\n", m1.xend, m1.yend);


 printf("HELLOOOOO2");

    /* allocate the maze */
    m1.arr = (char **) malloc (sizeof(char *) * (m1.xsize + 2) );
    for (i = 0; i < m1.xsize + 2; i++)
        m1.arr[i] = (char *) malloc (sizeof(char ) * (m1.ysize + 2) );

    /* initialize the maze to empty */
    for (i = 0; i < m1.xsize+2; i++)
        for (j = 0; j < m1.ysize+2; j++)
            m1.arr[i][j] = '.';

    /* mark the borders of the maze with *'s */
    for (i=0; i < m1.xsize+2; i++)
    {
        m1.arr[i][0] = '*';
        m1.arr[i][m1.ysize+1] = '*';
    }
    for (i=0; i < m1.ysize+2; i++)
    {
        m1.arr[0][i] = '*';
        m1.arr[m1.xsize+1][i] = '*';
    }

    /* mark the starting and ending positions in the maze */
    m1.arr[m1.xstart][m1.ystart] = 's';
    m1.arr[m1.xend][m1.yend] = 'e';

    /* mark the blocked positions in the maze with *'s */
    while (fscanf (src, "%d %d", &xpos, &ypos) != EOF)
    {
        if(xpos == m1.xstart && ypos == m1.ystart){
            printf("Invalid: Blocking Postions Are Blocking Start Postion\n");
            exit(0);
        }
        else if (xpos > m1.xsize || ypos > m1.ysize){
            printf("Invalid: Blocking out Of Maze\n");
            exit(0);
        }
        else if(xpos < 1 || ypos < 1){
            printf("Invalid: Blocking out of maze\n");
            exit(0);
        }
        else if(xpos == m1.xend && ypos == m1.yend){
            printf("Invalid: Blocking Postions Are Blocking End Postion\n");
            exit(0);
        }
        m1.arr[xpos][ypos] = '*';
    }
    /* prints initial maze */
    PrintMaze(&m1);

    /* puts start position into stack*/


    PushStack(&head, m1.xstart, m1.ystart);
    xpos = m1.xstart;
    ypos = m1.ystart;


    while(!CheckEmpty(head) && head != NULL){
        if(head->xpos == m1.xend && head->ypos == m1.yend){
            break;
        }
        if(m1.arr[head->xpos +1][head->ypos] != 'v' && m1.arr[head->xpos+1][head->ypos] != '*'){
            m1.arr[head->xpos][head->ypos] = 'v';
           xpos= xpos + 1;
            PushStack(&head, xpos, ypos);
            continue;
        }
        if(m1.arr[head->xpos][head->ypos+1] != 'v' && m1.arr[head->xpos][head->ypos+1] != '*'){
            m1.arr[head->xpos][head->ypos] = 'v';
           ypos= ypos + 1;
            PushStack(&head, xpos, ypos);
            continue;
        }
        if(m1.arr[head->xpos-1][head->ypos] != 'v' && m1.arr[head->xpos-1][head->ypos] != '*'){
            m1.arr[head->xpos][head->ypos] = 'v';
           xpos= xpos -1;
            PushStack(&head, xpos, ypos);
            continue;
        }
        if(m1.arr[head->xpos][head->ypos -1] != 'v' && m1.arr[head->xpos][head->ypos -1] != '*'){
            m1.arr[head->xpos][head->ypos] = 'v';
          ypos= ypos - 1;
            PushStack(&head, xpos, ypos);
            continue;
        }
        PopStack(&head, debugMode);
    }
    if(CheckEmpty(head)){
        printf("Maze has no solution\n");
        exit(0);
    }
    else{
       // printf("%d\n",head->xpos);
        printf("\n");
        DisplayStack(head);
        printf("\n");
        PrintMaze(&m1);

    }

    int n;
    for(n = 0; n < m1.xsize +2; n++){
        free(m1.arr[n]);
    }free(m1.arr);

    //resetStack(&head);

}
