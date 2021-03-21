    void push_left(Node ** head, int value)
    {
        if(*head!=NULL)
        {
            Node *nuch = new Node;
            nuch->value = value;
            nuch->next = *head;
            *head = nuch;
        }
        else
        {
            *head = new Node;
            (*head)->value = value;
            (*head)->next = NULL;
        }
    }

    void clear_list(Node ** head)
    {
        if(*head!=NULL)
        {
            Node *a = new Node;
            a = *head;
            while(a!=NULL)
            {
                a=(*head)->next;
                delete *head;

            }
            delete a;
        }
    }

    int pop(Node ** head, int index)
    {
        Node *a = *head;
        int kol = 0;
        int znach;
        for(int i = 0; i < index-1; i++)
            a = a->next;
        Node *b = a->next;
        znach = b->value;
        Node *c = b->next;
        delete b;
        a->next = c;

        return znach;

    }

    void remove(Node ** head, int value)
    {
        Node *a = *head;
        if(a->value==value)
        {
            *head = a->next;
            delete a;
        }
        else
        {
            while((a->next)->value != value)
            {
                a=a->next;
            }
            Node *b = a->next;
            Node *c = b->next;
            delete b;
            a->next = c;
        }

    }

    void remove_all(Node ** head, int value)
    {
        Node *a = *head;
        while((a->next)!=NULL)
        {
            Node *b = a->next;
            if(b->value == value)
            {
                Node *c = b->next;
                delete b;
                a->next = c;
            }
            a=a->next;

        }
        if((*head)->value == value)
        {
            Node *a = *head;
            *head = (*head)->next;
            delete a;
        }
    }

    void replace_all(Node ** head, int old_value, int new_value)
    {
        Node *a = *head;
        while((a->next)!=NULL)
        {
            Node *b = a->next;
            if(b->value == old_value)
            {
                b->value = new_value;
            }
            a=a->next;

        }
        if((*head)->value == old_value)
        {
            (*head)->value = new_value;
        }
    }

    int unique(Node * head)
    {
        int kol = 0;
        if(head != NULL)
        {
            while(head!=NULL)
            {
                kol++;
                remove_all(&head,(head->value));
            }
        }
        return kol;
    }

    void reverse(Node ** head)
    {
        if((*head)->next!=0)
        {   Node *a = *head;
            Node *b = a->next;
            while(b->next!=NULL)
            {
                Node *c = b->next;
                b->next = a;
                a = b;
                b = c;
            }
            b->next = a;
            (*head)->next = NULL;
            head = &b;
        }
    }






