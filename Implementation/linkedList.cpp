#include <iostream>

struct Node
{
    Node *next = NULL;
    Node *prev = NULL;
    int data;
    unsigned int index;
};

void deleteNode(int index, Node *head)
{
    std::cout << "delNode!\n";
    Node *delNode = head;
    while(delNode->index != index)
    {
        std::cout << "data: " << delNode->data << '\n';
        delNode = delNode->next;
    }
    Node *currentNode = delNode->next;
    Node *prev = delNode->prev;
    if(index == 0)
    {
        head = currentNode;
        head->prev = NULL;
    }
    else
    {
        prev->next = currentNode;
        currentNode->prev = prev;
    }
    delete delNode;
    std::cout << "Hi\n";
    while(currentNode->next != NULL)
    {
        std::cout << "index: " << currentNode->index << '\n';
        currentNode->index -= 1;
        currentNode = currentNode->next;
    }
    std::cout << "finished\n";
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    Node *prev = NULL;
    int readData;
    int i = 0;
    while(true)
    {
        std::cout << "input Num(0 is quit): ";
        std::cin >> readData;
        if(readData == 0)
        {
            break;
        }
        Node *newNode = new Node();
        newNode->data = readData;
        newNode->index = i;
        i += 1;
        if(head==NULL)
        {
            head = newNode;
        }
        else
        {
            tail->next = newNode;
        }
        prev = tail;
        tail = newNode;
        tail->next = NULL;
        tail->prev = prev;
    }
    deleteNode(2, head);

    std::cout << "print all input\n";
    Node *currentNode;
    if(head == NULL)
    {
        std::cout << "x\n";
    }
    else
    {
        currentNode = head;
        std::cout << currentNode->data << '\n';
        while(currentNode->next != NULL)
        {
            currentNode = currentNode->next;
            std::cout << currentNode->data << '\n';
        }
    }
    
    std::cout << "reversed print\n";
    if(head == NULL)
    {
        std::cout << "x\n";
    }
    else
    {
        currentNode = tail;
        std::cout << currentNode->data << '\n';
        while(currentNode->prev != NULL)
        {
            currentNode = currentNode->prev;
            std::cout << currentNode->data << '\n';
        }
    }
    

    if(head != NULL)
    {
        Node *delNode = head;
        Node *nextDelNode = delNode->next;
        while(delNode->next != NULL)
        {
            free(delNode);
            delNode = nextDelNode;
            nextDelNode = delNode->next;
        }
    }
    return 0;
}