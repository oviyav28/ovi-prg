Singly Linked List: insert, delete, traverse


SOURCE CODE:

#include<malloc.h>
typedef struct sllist
{ 
              int data;
	struct sllist *next;
}node;
node *head=NULL,*temp=NULL,*cur;
void create();
void insert();
void insert_beg();
void insert_end();
void insert_middle();
void todelete();
void display();
int main()
{
int choice=0;
	while(1)
	{
		printf("\n singly linked list operations");
		printf("\n -----------------------------");
		printf("\n 1.creations:");
		printf("\n 2.insertion:");
		printf("\n 3.Traversal:");
		printf("\n 4.deletion:");
		printf("\n 5.exit:");
		printf("\n enter your choice:");
		scanf("%d",&choice);
		switch(choice){
  			case 1:create();
			break;
			case 2: insert();
			break;
			case 3: display();
			break;
			case 4: todelete();
			break;
			case 5: printf("\n end of the list operations");
			   exit(0);
			default:printf("\n wrong choice---> try again");
			break;
}
}
}
void create()
{
	int n,i;
	node *cur;
	printf("\n how many nodes to craete");
	scanf("%d",&n);
	for(i=1;i<=n;i++){	
	temp=(node*)malloc(sizeof(node));
	printf("\n enter data:");
	scanf("%d",&temp->data);
	temp->next=NULL;
	if(head==NULL)
              {
		head=temp;
              
}
	else{
		cur=head;
		while(cur->next!=NULL){
			cur=cur->next;
			}
		cur->next=temp;}
		}
		}
void display(){	
	if(head==NULL){
		printf("\n empty List");	
}
	else{
		cur=head;
		printf("\n linked list elements");
		printf("\n -----------------------------");
		while(cur!=NULL){
			printf("\n %d", cur->data);
			cur=cur->next;	
}
		printf("\n---------------------");
}	
}
void todelete(){
	int ele;
	node *prev=head;
	if(head==NULL){
		printf("\n empty list --> deletion is not posiible ");
		return;}
	display();
	printf("\n what to delete???");
	scanf("%d",&ele);
	cur=head;
	while(cur->data!=ele&&cur->next!=NULL){
		prev=cur;
		cur=cur->next;}
	if(cur->data==ele){
		if(cur==head){
			head=cur->next;}
		else{
			prev->next=cur->next;
			free(cur);}
		if(cur->next==NULL){
printf("\n element to be deleted is not in the list");
}
}
}
void insert(){
	int option=0;
	temp=malloc(sizeof(node));
	printf("\n enter data:");
	scanf("%d",&temp->data);
	temp->next=NULL;
	printf("\n insertion menu:");
	printf("\n------------------");
	printf("\n 1.Beggining:");
	printf("\n 2. Middle:");
	printf("\n 3.end");
	printf("\n where to insert??:");
	scanf("%d",&option);
	switch(option){
		case 1: insert_beg();
		break;
		case 2: if(head==NULL){
			printf("\n insertion in middle is not possible");
			return;} 
		display();
		insert_middle();
		break;
		case 3: insert_end();
		break;
        default: printf("\n please enter the correct position");	
        }		
}
void insert_beg(){
	temp->next=head;
	head=temp;
}

void insert_end()
{
	cur=head;
	while(cur->next!=NULL)
{
		cur=cur->next;
}
	cur->next=temp;
}
void insert_middle(){
	int ele;
	printf("\n after which node???");
	scanf("%d",&ele);
	cur=head;
	while(cur ->data!=ele && cur->next!=NULL)
		cur=cur->next;
		if(cur->data==ele){
			temp->next=cur->next;
			cur->next=temp;}
		if(cur->next==NULL){
			printf("\n %d is not in the list");
            }	
}  Circular linked list ( Creation, Insertion, Traversal, Deletion)

SOURCE CODE:

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;
void create() {
    int n, value;

    if (head != NULL) {
        printf("List already created!\n");
        return;
    }

    printf("How many nodes do you want to enter? ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &value);

        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = value;

        if (head == NULL) {
            head = newNode;
            newNode->next = head;
        } else {
            struct Node *temp = head;
            while (temp->next != head)
                temp = temp->next;

            temp->next = newNode;
            newNode->next = head;
        }
    }
    printf("List created with %d nodes.\n", n);
}

void insert() {
    int choice, value, pos;

    if (head == NULL) {
        printf("List empty. First create the list.\n");
        return;
    }

    printf("\nInsert Menu:\n");
    printf("1. Beginning\n2. End\n3. Middle (after position)\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    printf("Enter data: ");
    scanf("%d", &value);

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

  
    if (choice == 1) {
        struct Node *temp = head;
        while (temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;
        head = newNode;

        printf("Inserted at beginning.\n");
    }
  
    else if (choice == 2) {
        struct Node *temp = head;
        while (temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;

        printf("Inserted at end.\n");
    }
    
    else if (choice == 3) {
        printf("Insert after which position? ");
        scanf("%d", &pos);

        struct Node *temp = head;
        for (int i = 1; i < pos; i++) {
            temp = temp->next;
            if (temp == head) {
                printf("Position out of range.\n");
                free(newNode);
                return;
            }
        }

        newNode->next = temp->next;
        temp->next = newNode;

        printf("Inserted after position %d.\n", pos);
    }
    else {
        printf("Invalid choice.\n");
        free(newNode);
    }
}


void traversal() {
    if (head == NULL) {
        printf("List empty.\n");
        return;
    }

    struct Node *temp = head;
    printf("Circular Linked List: ");

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("\n");
}

/* -------- DELETE BY VALUE ---------- */
void deletion() {
    int value;

    if (head == NULL) {
        printf("List empty.\n");
        return;
    }

    printf("Enter value to delete: ");
    scanf("%d", &value);

    struct Node *temp = head, *prev = NULL;

    /* Delete head node */
    if (head->data == value) {
        struct Node *last = head;
        while (last->next != head)
            last = last->next;

        if (head->next == head) {
            free(head);
            head = NULL;
        } else {
            last->next = head->next;
            temp = head;
            head = head->next;
            free(temp);
        }

        printf("Value %d deleted.\n", value);
        return;
    }

    
    do {
        prev = temp;
        temp = temp->next;

        if (temp->data == value) {
            prev->next = temp->next;
            free(temp);
            printf("Value %d deleted.\n", value);
            return;
        }
    } while (temp != head);

    printf("Value not found.\n");
}


int main() {
    int choice;

    while (1) {
        printf("\n--- Circular Linked List Menu ---\n");
        printf("1. Create\n");
        printf("2. Insert\n");
        printf("3. Traversal\n");
        printf("4. Delete\n");
        printf("5. Exit\n");
        printf("----------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: create(); break;
            case 2: insert(); break;
            case 3: traversal(); break;
            case 4: deletion(); break;
            case 5: exit(0);
            default: printf("Invalid choice!\n");
        }
    }

    return 0;
}
stack operations using pointers (push, pop, process )

SOURCE CODE:

#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
typedef struct stack {
    int data;
    struct stack *next;
} node;

node *top = NULL, *temp;

/* Function declarations */
void push(int item);
int pop();
void display();

int main() {
    int choice = 0, item, i, n, ele[100];

    while (1) {
        printf("\nStack Operations");
        printf("\n------------------");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("\nEnter the number of items to push: ");
                scanf("%d", &n);

                printf("Enter the elements:\n");
                for (i = 0; i < n; i++) {
                    scanf("%d", &ele[i]);
                    push(ele[i]);
                }
                break;

            case 2:
                if (top == NULL)
                    printf("\nEmpty Stack");
                else
                    printf("\nPopped item = %d", pop());
                break;

            case 3:
                display();
                break;

            case 4:
                printf("\nEnding stack operations");
                getch();
                exit(0);

            default:
                printf("\nInvalid choice");
        }
    }

    return 0;
}


void push(int item) {
    temp = (node *)malloc(sizeof(node));

    if (temp == NULL) {
        printf("\nStack Overflow (Memory Allocation Failed)");
        return;
    }

    temp->data = item;
    temp->next = top;
    top = temp;
}


int pop() {
    int data;
    temp = top;
    data = temp->data;
    top = temp->next;
    free(temp);
    return data;
}

/* Display stack */
void display() {
    if (top == NULL) {
        printf("\nEmpty Stack");
    } else {
        printf("\nStack elements:");
        printf("\n------------------");
        temp = top;
        while (temp != NULL) {
            printf("\n%d", temp->data);
            temp = temp->next;
        }
        printf("\n------------------");
    }
} 
                  infix expression to its postfix form


SOURCE CODE:

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct opstack
{
    char data;
    struct opstack *next;
} node;

node *TOP = NULL;

/* Function prototypes */
void push(char);
char pop();
int stackpriority(char);
int infixpriority(char);

int main()
{
    char infix[50], postfix[50], ch, ch1;
    int i = 0, j = 0;

    printf("\n Conversion of infix expression to postfix expression");
    printf("\n ------------------------------------------------------");
    printf("\n Enter an infix expression with only +, -, *, /, (, ) and single operand:\n");

    fgets(infix, sizeof(infix), stdin);
    infix[strcspn(infix, "\n")] = '\0';   // remove newline

    while (infix[i] != '\0')
    {
        ch = infix[i];

        /* Operand */
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
        {
            postfix[j++] = ch;
        }
        /* Left parenthesis */
        else if (ch == '(')
        {
            push(ch);
        }
        /* Right parenthesis */
        else if (ch == ')')
        {
            ch1 = pop();
            while (ch1 != '(' && ch1 != '\0')
            {
                postfix[j++] = ch1;
                ch1 = pop();
            }
        }
        
        else
        {
            while (TOP != NULL &&
                   stackpriority(TOP->data) >= infixpriority(ch))
            {
                postfix[j++] = pop();
            }
            push(ch);
        }
        i++;
    }

    
    while (TOP != NULL)
    {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("\n The postfix expression is: %s\n", postfix);

    return 0;
}


void push(char ch)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = ch;
    temp->next = TOP;
    TOP = temp;
}


char pop()
{
    node *temp;
    char x;

    if (TOP == NULL)
        return '\0';   // stack underflow protection

    temp = TOP;
    x = temp->data;
    TOP = TOP->next;
    free(temp);

    return x;
}


int infixpriority(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '(')
        return 3;
    else
        return 0;
}


int stackpriority(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '(')
        return 0;   // lowest priority in stack
    else
        return 100;
}
evaluation of postfix expression


SOURCE CODE:

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


typedef struct opstack
{
    int data;
    struct opstack *next;
} node;

node *top = NULL;

/* Function declarations */
void push(int);
int pop();

int main()
{
    char postfix[50], ch;
    int chval, res, v1, v2, i = 0;

    printf("\nEvaluation of Postfix Expression");
    printf("\n-------------------------------------");
    printf("\nEnter the postfix expression: ");

    fgets(postfix, sizeof(postfix), stdin);
    postfix[strcspn(postfix, "\n")] = '\0';   // remove newline

    while (postfix[i] != '\0')
    {
        ch = postfix[i];

        /* If operand (alphabet) */
        if (isalpha(ch))
        {
            printf("Enter value of %c: ", ch);
            scanf("%d", &chval);
            push(chval);
        }
        /* If operator */
        else
        {
            v2 = pop();
            v1 = pop();

            switch (ch)
            {
                case '+':
                    res = v1 + v2;
                    break;
                case '-':
                    res = v1 - v2;
                    break;
                case '*':
                    res = v1 * v2;
                    break;
                case '/':
                    res = v1 / v2;
                    break;
                default:
                    printf("Invalid operator\n");
                    return 1;
            }
            push(res);
        }
        i++;
    }

    printf("\nEvaluated value of postfix expression = %d\n", pop());
    return 0;
}

/* Push operation */
void push(int item)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = item;
    temp->next = top;
    top = temp;
}

/* Pop operation */
int pop()
{
    node *temp;
    int value;

    if (top == NULL)
    {
        printf("Stack Underflow\n");
        return 0;
    }

    temp = top;
    value = temp->data;
    top = temp->next;
    free(temp);

    return value;
} on queue using pointers (Insertion, Deletion, Process the Queue)


SOURCE CODE:

#include <stdio.h>
#include <stdlib.h>
/* Function declarations */
void qinsert();
void qdelete();
void qdisplay();

/* Queue node structure */
typedef struct queue
{
    int data;
    struct queue *next;
} node;

node *front = NULL, *rear = NULL, *temp;

int main()
{
    int choice;

    while (1)
    {
        printf("\nQueue Operation");
        printf("\n----------------");
        printf("\n1. Insertion");
        printf("\n2. Deletion");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\n-----------------");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                qinsert();
                break;

            case 2:
                qdelete();
                break;

            case 3:
                qdisplay();
                break;

            case 4:
                printf("\nEnd of the operation\n");
                exit(0);

            default:
                printf("\nWrong choice\n");
        }
    }

    return 0;
}

/* Insert operation */
void qinsert()
{
    int n, i;

    printf("\nEnter the number of nodes to insert: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        temp = (node *)malloc(sizeof(node));

        printf("Enter data: ");
        scanf("%d", &temp->data);

        temp->next = NULL;

        if (rear == NULL)
        {
            front = rear = temp;
        }
        else
        {
            rear->next = temp;
            rear = temp;
        }
    }
}

/* Delete operation */
void qdelete()
{
    if (front == NULL)
    {
        printf("\nEmpty queue -> Deletion not possible\n");
    }
    else
    {
        temp = front;
        printf("\nDeleted item is %d\n", front->data);
        front = front->next;
        free(temp);

        if (front == NULL)
        {
            rear = NULL;
        }
    }
}

/* Display operation */
void qdisplay()
{
    if (front == NULL)
    {
        printf("\nEmpty queue\n");
    }
    else
    {
        temp = front;
        printf("\nQueue elements");
        printf("\n------------------\n");

        while (temp != NULL)
        {
            printf("%d\n", temp->data);
            temp = temp->next;
        }}
double-ended queue (Dequeue) with the following operations: (a) insert in the Beginning (b) insert in the end (c) delete from beginning (d) delete from end


SOURCE CODE:

#include <stdio.h>

#define MAX 5

int deque[MAX];
int front = -1, rear = -1;

/* Function prototypes */
void insertFront(int);
void insertRear(int);
void deleteFront();
void deleteRear();
void display();

int main()
{
    int choice, item;

    do
    {
        printf("\n\n--- DOUBLE ENDED QUEUE (DEQUE) ---");
        printf("\n1. Insert at Front");
        printf("\n2. Insert at Rear");
        printf("\n3. Delete from Front");
        printf("\n4. Delete from Rear");
        printf("\n5. Display");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter element to insert at front: ");
                scanf("%d", &item);
                insertFront(item);
                break;

            case 2:
                printf("Enter element to insert at rear: ");
                scanf("%d", &item);
                insertRear(item);
                break;

            case 3:
                deleteFront();
                break;

            case 4:
                deleteRear();
                break;

            case 5:
                display();
                break;

            case 6:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 6);

    return 0;
}

/* Insert at front */
void insertFront(int item)
{
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
    {
        printf("Deque Overflow!\n");
        return;
    }

    if (front == -1)
    {
        front = rear = 0;
    }
    else if (front == 0)
    {
        front = MAX - 1;
    }
    else
    {
        front--;
    }

    deque[front] = item;
}

/* Insert at rear */
void insertRear(int item)
{
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
    {
        printf("Deque Overflow!\n");
        return;
    }

    if (rear == -1)
    {
        front = rear = 0;
    }
    else if (rear == MAX - 1)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }

    deque[rear] = item;
}

/* Delete from front */
void deleteFront()
{
    if (front == -1)
    {
        printf("Deque Underflow!\n");
        return;
    }

    printf("Deleted element: %d\n", deque[front]);

    if (front == rear)
    {
        front = rear = -1;
    }
    else if (front == MAX - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }
}

/* Delete from rear */
void deleteRear()
{
    if (rear == -1)
    {
        printf("Deque Underflow!\n");
        return;
    }

    printf("Deleted element: %d\n", deque[rear]);

    if (front == rear)
    {
        front = rear = -1;
    }
    else if (rear == 0)
    {
        rear = MAX - 1;
    }
    else
    {
        rear--;
    }
}

/* Display deque */
void display()
{
    int i;

    if (front == -1)
    {
        printf("Deque is empty.\n");
        return;
    }

    printf("Deque elements: ");

    i = front;
    while (1)
    {
        printf("%d ", deque[i]);

        if (i == rear)
            break;

        i = (i + 1) % MAX;
    }
    printf("\n");
}



SOURCE CODE:
#include <stdio.h>

/* Function for Linear Search */
int linearSearch(int a[], int n, int key) {
    int i;
    for (i = 0; i < n; i++) {
        if (a[i] == key) {
            return i;
        }
    }
    return -1;
}

/* Function for Binary Search */
int binarySearch(int a[], int n, int key) {
    int low = 0, high = n - 1, mid;

    while (low <= high) {
        mid = (low + high) / 2;

        if (a[mid] == key) {
            return mid;
        } 
        else if (key < a[mid]) {
            high = mid - 1;
        } 
        else {
            low = mid + 1;
        }
    }
    return -1;
}

int main() {
    int a[50], n, key, choice, result = -1, i;

    do {
        printf("\n----- SEARCH MENU -----");
        printf("\n1. Linear Search");
        printf("\n2. Binary Search");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 1 || choice == 2) {
            printf("\nEnter number of elements: ");
            scanf("%d", &n);
        }

        switch (choice) {

        case 1:
            printf("\nEnter elements:\n");
            for (i = 0; i < n; i++) {
                scanf("%d", &a[i]);
            }

            printf("\nEnter element to search: ");
            scanf("%d", &key);

            result = linearSearch(a, n, key);
            break;

        case 2:
            printf("\nEnter elements in sorted order:\n");
            scanf("%d", &a[0]);

            for (i = 1; i < n; i++) {
                while (1) {
                    scanf("%d", &a[i]);
                    if (a[i] > a[i - 1]) {
                        break;
                    } 
                    else {
                        printf("Enter a number greater than %d: ", a[i - 1]);
                    }
                }
            }

            printf("\nEnter element to search: ");
            scanf("%d", &key);

            result = binarySearch(a, n, key);
            break;

        case 3:
            printf("\nProgram Exiting......");
            break;

        default:
            printf("\nInvalid Choice!");
        }

        if (choice == 1 || choice == 2) {
            if (result != -1) {
                printf("\nElement found at position %d\n", result + 1);
            } 
            else {
                printf("\nElement not found\n");
            }
        }

    } while (choice != 3);

    return 0;
}



