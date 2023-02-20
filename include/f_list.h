#ifndef list_hpp
#define list_hpp

#include <exception>
#include <iostream>
template <typename T> class f_list {
private:

    struct list_node
    {
        T data;
        list_node* next;
        list_node() {
            data = -1;
            next = NULL;
        }
    };
    list_node* First;
public:
    f_list()
    {
        First = NULL;
    }
    
    
    f_list(f_list& other)
    {
        First = new list_node();
        First->data = other.First->data;
        list_node* uk1 = other.First;
        list_node* uk2 = First;
        while (uk1->next!=NULL)
        {
            uk2->next = new list_node();
            uk2->next->data = uk1->next->data;
            uk2->next->next = uk1->next->next;
            uk2 = uk2->next;
            uk1 = uk1->next;
        }
    }
    
    
    f_list& operator = (f_list& other)
    {
        if (First == other.First)
        {
            return *this;
        }
        clear_all();
        First = new list_node();
        First->data = other.First->data;
        list_node* uk1 = other.First;
        list_node* uk2 = First;
        while (uk1->next != NULL)
        {
            uk2->next = new list_node();
            uk2->next->data = uk1->next->data;
            uk2->next->next = uk1->next->next;
            uk2 = uk2->next;
            uk1 = uk1->next;
        }
        return *this;
    }
    
    
    void push_front(T elem)
    {
        if (First==NULL)
        {
            First = new list_node();
            First->data = elem;
        }
        else
        {
            list_node* uk = new list_node();
            uk->next=First->next;
            uk->data = First->data;
            First = new list_node();
            First->data = elem;
            First->next = uk;

        }
    }
    
    
    void pop_front()
    {
        if (!First) throw std::logic_error("no element");
        list_node* uk = First;
        First = First->next;
        delete uk;
    }
    
    
    void erase_after(list_node* el)
    {
        if (el == NULL || el->next==NULL) throw std::logic_error("empty cell");
        list_node* uk = el->next->next;
        delete el->next;
        el->next = uk;
    }
    
    
    void insert_after(list_node* el, T val)
    {
        if (el==NULL)
        {
            push_front(val);
            return;
        }
        list_node* uk = el->next;
        el->next = new list_node();
        el->next->data = val;
        el->next->next = uk;
    }
    
    void clear_all()
    {
        for (list_node* it = First; it;)
        {
            list_node* uk = it->next;
            delete it;
            it = uk;
        }
        First = NULL;
    }
    bool operator ==(f_list a)
    {
        list_node* uk1 = a.First;
        list_node* uk2 = First;
        while (uk1!=NULL || uk2!=NULL)
        {
            if (uk1==NULL || uk2==NULL) return false;
            if (uk2->data != uk1->data) return false;
            uk1 = uk1->next;
            uk2 = uk2->next;
        }
        return true;
    }
    bool operator !=(f_list a)
    {
        return !(*this == a);
    }
    
    list_node* begin()
    {
        return First;
    }
    ~f_list()
    {
        clear_all();
    }
};
#endif /* list_hpp */
