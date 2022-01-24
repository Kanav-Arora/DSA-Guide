#include<iostream>
using namespace std;

class Event{
    public:
        string name;
        int time;
        Event* next;

        Event(string name, int time)
        {
            this->name = name;
            this->time = time;
            next = NULL;
        }
};

class Agenda{
    public:
        string name;
        Event* next;

        Agenda(string name)
        {
            this->name = name;
            next = NULL;
        }
};

class App{
    public:
        string name;
        Agenda* agenda1;
        Agenda* agenda2;

        App(string name)
        {
            this->name = name;
            agenda1 = NULL;
            agenda2 = NULL;
        }
};





// --------------------------------------------------------------------ADD EVENT--------------------------------------------------------------------------------

void search_Duplicate(Agenda* agenda, string event, int time)
{
    Event* ptr = agenda->next;
    while(ptr!=NULL)
    {
        if(ptr->name==event)
        {
            cout<<"Error: Already an event with that name"<<endl;
            return;
        }
        else if(ptr->time==time)
        {
            cout<<"Error: Already an event with that time"<<endl;
            return;
        }
        ptr = ptr->next;
    }
}

void addEvent(Agenda* agenda, string event, int time)
{
    if(agenda->next==NULL)
    {
        Event* n = new Event(event, time);
        agenda->next = n;
    }
    else if(agenda->next->time>time)
    {
        Event* n = new Event(event, time);
        n->next = agenda->next;
        agenda->next = n;
    }
    else
    {
        search_Duplicate(agenda,event,time);
        Event* ptr = agenda->next;
        while(ptr->next!=NULL)
        {
            if(ptr->next->time>=time)
                break;
            ptr = ptr->next;
        }
        Event* n = new Event(event, time);
        n->next = ptr->next;
        ptr->next = n;
    }
}

void add(App* &calendar, string agenda, string event, int time)
{
    if(calendar->agenda1==NULL && calendar->agenda2!=NULL)
    {
        if(calendar->agenda2->name==agenda)
        {
            addEvent(calendar->agenda2, event, time);
            return;
        }
        Agenda* n = new Agenda(agenda);
        calendar->agenda1 = n;
        addEvent(calendar->agenda1,event, time);
    }
    else if(calendar->agenda2==NULL && calendar->agenda1!=NULL)
    {
        if(calendar->agenda1->name==agenda)
        {
            addEvent(calendar->agenda1, event, time);
            return;
        }
        Agenda* n = new Agenda(agenda);
        calendar->agenda2 = n;
        addEvent(calendar->agenda2,event, time);
    }
    else if(calendar->agenda2==NULL && calendar->agenda1==NULL)
    {
        Agenda* n = new Agenda(agenda);
        calendar->agenda1 = n;
        addEvent(calendar->agenda1,event, time);
    }
    else if(calendar->agenda2!=NULL && calendar->agenda1!=NULL)
    {
        if(calendar->agenda1->name==agenda)
        {
            addEvent(calendar->agenda1, event, time);
            return;
        }
        else if(calendar->agenda2->name==agenda)
        {
            addEvent(calendar->agenda2, event, time);
            return;
        }
    }
    else
    {
        cout<<"ERROR: Agenda not found";
        return;
    }
}

// ----------------------------------------------------------------------------------------------------------------------------------------------------


// -----------------------------------------------------------------DELETE FUNCTION-----------------------------------------------------------------------------------

void delEvent(Agenda* &agenda, string event)
{
    if(agenda->next==NULL)
    {
        cout<<"ERROR: Event not found"<<endl;
        return;
    }
    if(agenda->next->name==event)
    {
        Event* to_delete = agenda->next;
        agenda->next = agenda->next->next;
        delete to_delete;
        return;
    }
    
    Event* ptr = agenda->next;
    while(ptr!=NULL)
    {
        if(ptr->next->name==event)
        {
            Event* to_delete = ptr->next;
            ptr->next = ptr->next->next;
            delete to_delete;
            return;
        }
        ptr = ptr->next;
    }
    cout<<"ERROR: Event not found"<<endl;

}

void del(App* &calendar, string agenda, string event)
{
    if(calendar->agenda1==NULL && calendar->agenda2!=NULL)
    {
        if(calendar->agenda2->name==agenda)
        {
            delEvent(calendar->agenda2, event);
            return;
        }
        else
        {
            cout<<"ERROR: Agenda not found";
            return;
        }
    }
    else if(calendar->agenda2==NULL && calendar->agenda1!=NULL)
    {
        if(calendar->agenda1->name==agenda)
        {
            delEvent(calendar->agenda1, event);
            return;
        }
        else
        {
            cout<<"ERROR: Agenda not found";
            return;
        }
    }
    else if(calendar->agenda2==NULL && calendar->agenda1==NULL)
    {
        cout<<"ERROR: Agenda not found";
        return;
    }
    else if(calendar->agenda2!=NULL && calendar->agenda1!=NULL)
    {
        if(calendar->agenda1->name==agenda)
        {
            delEvent(calendar->agenda1, event);
            return;
        }
        else if(calendar->agenda2->name==agenda)
        {
            delEvent(calendar->agenda2, event);
            return;
        }
        else
    {
        cout<<"ERROR: Agenda not found";
        return;
    }
    }
    
}

// ----------------------------------------------------------------------------------------------------------------------------------------------------


// ----------------------------------------------------------------------SWAP FUNCTION------------------------------------------------------------------------------

Event* searchEvent(Agenda* agenda, string event)
{
    Event* ptr = agenda->next;
    while(ptr!=NULL)
    {
        if(ptr->name==event)
        {
            return ptr;
        }
        ptr = ptr->next;
    }
    return NULL;
}

void swapEvent(Agenda* agenda, string event1, string event2)
{
    Event* ptr1 = searchEvent(agenda,event1);
    Event* ptr2 = searchEvent(agenda,event2);
    if(ptr1!=NULL && ptr2!=NULL)
    {
        string temp = ptr1->name;
        ptr1->name = ptr2->name;
        ptr2->name = temp;
    }
    else
    {
        cout<<"ERROR: Event not found";
        return;
    }

}

void swap(App* &calendar, string agenda, string event1, string event2)
{
    if(calendar->agenda1==NULL && calendar->agenda2!=NULL)
    {
        if(calendar->agenda2->name==agenda)
        {
            swapEvent(calendar->agenda2, event1, event2);
            return;
        }
        else
        {
            cout<<"ERROR: Agenda not found";
            return;
        }
    }
    else if(calendar->agenda2==NULL && calendar->agenda1!=NULL)
    {
        if(calendar->agenda1->name==agenda)
        {
            swapEvent(calendar->agenda1, event1, event2);
            return;
        }
        else
        {
            cout<<"ERROR: Agenda not found";
            return;
        }
    }
    else if(calendar->agenda2==NULL && calendar->agenda1==NULL)
    {
        cout<<"ERROR: Agenda not found";
        return;
    }
    else if(calendar->agenda2!=NULL && calendar->agenda1!=NULL)
    {
        if(calendar->agenda1->name==agenda)
        {
            swapEvent(calendar->agenda1, event1, event2);
            return;
        }
        else if(calendar->agenda2->name==agenda)
        {
            swapEvent(calendar->agenda2, event1, event2);
            return;
        }
        else
    {
        cout<<"ERROR: Agenda not found";
        return;
    }
    }
}
// ----------------------------------------------------------------------------------------------------------------------------------------------------



// -----------------------------------------------------------------DISPLAY FUNCTION-----------------------------------------------------------------------------------


void print(Agenda* agenda)
{
    Event* ptr = agenda->next;
    cout<<"========="<<agenda->name<<"========="<<endl;
    while(ptr!=NULL)
    {
        cout<<ptr->time<<"  "<<ptr->name<<endl;
        ptr= ptr->next;
    }
    cout<<"========= End of"<<agenda->name<<"========="<<endl;
}

void display(App* &calendar, string agenda)
{
    if(calendar->agenda1->name==agenda)
    {
        print(calendar->agenda1);
    }
    else if(calendar->agenda2->name==agenda)
    {
        print(calendar->agenda2);
    }
    else
    {
        cout<<"ERROR: Agenda not found";
        return;
    }
}


// ----------------------------------------------------------------------------------------------------------------------------------------------------

// ------------------------------------------------------------------MERGE FUNCTION----------------------------------------------------------------------------------

int search_Duplicate_Event(Agenda* agenda, string event, int time)
{
    Event* ptr = agenda->next;
    while(ptr!=NULL)
    {
        if(ptr->name==event || ptr->time==time)
        {
            return 1;
        }
        ptr = ptr->next;
    }
    return 0;
}

void merge(App* &calendar, string agenda1, string agenda2)
{
    if(agenda1==agenda2)
    {
        cout<<"ERROR: Cannot merge same agenda"<<endl;
        return;
    }
    if((calendar->agenda1->name==agenda1 && calendar->agenda2->name==agenda2) || (calendar->agenda1->name==agenda2 && calendar->agenda2->name==agenda1))
    {
        Agenda* mergedAgenda = new Agenda(agenda1);
        Event* ptr = NULL;
        mergedAgenda->next = ptr;
        Event* ptr1 = calendar->agenda1->next;
        Event* ptr2 = calendar->agenda2->next;
        while(ptr1->next!=NULL && ptr2->next!=NULL)
        {
            if(ptr1->time<ptr2->time && search_Duplicate_Event(calendar->agenda1, ptr1->name, ptr1->time)+search_Duplicate_Event(calendar->agenda2,ptr1->name,ptr1->time)<2)
            {
                ptr->next = ptr1;
                ptr = ptr->next;
                ptr1 = ptr1->next;
            }
            else if(ptr2->time<ptr1->time && search_Duplicate_Event(calendar->agenda1, ptr2->name, ptr2->time)+search_Duplicate_Event(calendar->agenda2,ptr2->name,ptr2->time)<2)
            {
                ptr->next = ptr2;
                ptr = ptr->next;
                ptr2 = ptr2->next;
            }
            else
            {
                cout<<"ERROR: Cannot merge: Conflict found"<<endl;
                return;
            }
        }
        calendar->agenda1 = mergedAgenda;
        calendar->agenda2 = NULL;
    }
    else
        cout<<"ERROR: Agenda not found"<<endl;
}

// ----------------------------------------------------------------------------------------------------------------------------------------------------

int main()
{
    App* calendar = new App("calendar");
    add(calendar,"Agenda","Introduction talk",9);
    add(calendar,"Agenda","Introduction plans",10);
    display(calendar,"Agenda");
    add(calendar,"others","coffee",5);
    add(calendar,"others","tea",4);
    add(calendar,"others","milk",6);
    display(calendar,"others");
    swap(calendar,"others","coffee","milk");
    display(calendar,"others");
    // cout<<search_Duplicate_Event(calendar->agenda2,"coffee",5);
    merge(calendar,"Agenda","others");
    display(calendar,"Agenda");
    return 0;
}