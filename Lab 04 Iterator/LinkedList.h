//
//  LinkedList.hpp
//  Lab 03 Linked List
//
//  Created by C/R
//

#include <sstream>
#include <iostream>
#include <string>
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

/** Linked List */
template<typename T>
class LinkedList
{
private:
   struct Node
   {
      T data;
      Node* next;
      Node(const T& d) : data(d), next(NULL) {}
      Node(const T& d, Node* n) : data(d), next(n) {}
   };
   Node* head;

public:
   LinkedList() { this->head = NULL; }
   ~LinkedList() { clear(); }
    
    class Iterator
    {
    private:
        Node* iNode;
    public:
        Iterator(Node* head) : iNode(head) { }
        ~Iterator() {}

        bool operator!=(const Iterator& rhs) const
        {
            return rhs.iNode != iNode;
        }

        Iterator& operator++()
        {
            iNode = iNode->next;
            return *this;
        }

        T& operator*() const
        {
            return iNode->data;
        }
    };
    
    Iterator begin(void) { return LinkedList<T>::Iterator(head); }
    Iterator end(void) { return LinkedList<T>::Iterator(NULL); }
    
   //fiinds the first occurance of a value
    Iterator find(Iterator first, Iterator last, const T& value)
    {
        Iterator found = first;
        while (found != last)
        {
            if (*found == value) return found;
            ++found;
        }
        throw std::string( " Not Found");
        return found;
    }
    
   //iinserts a node wiith a specific value before a certaiin postioon
    Iterator insert(Iterator position, const T& value)
    {
       Node* ptr = head;
       if (ptr->data == *position)
       {
          push_front(value);
          return position;
       }
       while (ptr->next != NULL)
       {
          if (ptr->next->data == *position) break;
          ptr = ptr->next;
       }
       if ((ptr->next == NULL) && (ptr->data == *position))
       {
          Node* valTemp = new Node(value, ptr->next);
          return position;
       }
       Node* pos;
       Node* before;
       Node* insVal = new Node(value, ptr->next);
       before = ptr;
       pos = before->next;
       before->next = insVal;
       insVal->next = pos;
       return position;
    }
    
   //inserts a node with the specified value after a certaiin position
    Iterator insert_after(Iterator position, const T& value)
    {
       Node* ptr = head;
       Node* newVal = head;
       while (newVal->next != NULL)
       {
          if (newVal->next->data == *position) break;
          newVal = newVal->next;
       }
       if ((newVal->next == NULL) && (newVal->data == *position))
       {
          Node* valTemp = new Node(value, newVal->next);
          return position;
       }
       while (ptr != NULL)
       {
          if (ptr->data == *position)
          {
             Node* valTemp = new Node(value, newVal->next);
             valTemp->next = ptr->next;
             ptr->next = valTemp;
             break;
          }
          ptr = ptr->next;
       }
       if (ptr == NULL)
       {
          return end();
       }
       else
       {
          return position;
       }
    }
    
   //erases data at giiven posiitiiion
    Iterator erase(Iterator position)
    {
        Node* ptr = head;
        Node* temp = head;
        while (ptr->next != NULL)
        {
          if (head->data == *position)
          {
             head = ptr->next;
             delete ptr;
             ptr = head;
             throw std::string(" OK");
             return position;
          }
           else if (ptr->next->data == *position)
           {
              temp = ptr->next;
              ptr->next = temp->next;
              delete temp;
              throw std::string(" OK");
              return position;
           }
           if (ptr->next == NULL) continue;
           ptr = ptr->next;
        }
       if (ptr == NULL) throw std::string(" Not Found");
       if (head->data == *position)
       {
         head = ptr->next;
         delete ptr;
         throw std::string(" OK");
         return position;
      }
       else
       {
          return position;
       }
   }
 
   //replaces first occurance of value with a new value
    void replace(Iterator first, Iterator last, const T& old_value, const T& new_value)
    {
       Node* ptr = head;
       Node* temp = head;
       while (ptr->next != NULL)
       {
         if (head->data == old_value)
         {
            ptr->data = new_value;
            continue;
         }
          else if (ptr->next->data == old_value)
          {
             ptr->next->data = new_value;
          }
          if (ptr->next == NULL) continue;
          ptr = ptr->next;
       }
    }
   
   // Insert Node at beginning of list
   void push_front(const T& d)
   {
      if (head == NULL)
      {
         head = new Node(d);
         return;
      }
      Node* temp = head;
      head = new Node(d);
      head->next = temp;
      return;
   }
    
   // Remove Node at beginning of linked list
   void pop_front(void)
   {
      if (head != NULL)
      {
         if (head->next == NULL)
         {
            Node* temp = head;
            delete temp;
            head = NULL;
         }
         else
         {
            Node* ptr = head;
            Node* temp = head->next;
            head = temp;
            if (ptr == NULL) return;
            delete ptr;
         }
      }
      else
      {
         throw std::string("Empty!");
      }
   }
   
    // Return reference to value of Node at beginning of linked list
   T& front() { return head->data; }

    // Return true if linked list size == 0
   bool empty() const
   {
      if (head == NULL)
      {
         return true;
      }
      else
      {
         return false;
      }
   }

   //Remove all Nodes with a certain value
   void remove(const T& value)
   {
      Node* ptr = head;
      Node* temp = head;
      while (ptr->next != NULL)
      {
        if (head->data == value)
        {
           head = ptr->next;
           delete ptr;
           ptr = head;
           continue;
        }
         else if (ptr->next->data == value)
         {
            temp = ptr->next;
            ptr->next = temp->next;
            delete temp;
         }
         if (ptr->next == NULL) continue;
         ptr = ptr->next;
      }
      if (head->data == value)
      {
          head = ptr->next;
          delete ptr;
      }
   }
    
    // Remove all Nodes from linked list
   void clear(void)
   {
      Node* ptr = head;
      Node* temp = head;
      while (ptr != NULL)
      {
         temp = ptr;
         ptr = ptr->next;
         delete temp;
      }
      head = NULL;
   }
 
    // Reverse Nodes in linked list
   void reverse()
   {
      Node* ptr = head;
      Node* next;
      Node* prev = NULL;
      while (ptr != NULL)
      {
         next = ptr->next;
         ptr->next = prev;
         prev = ptr;
         ptr = next;
      }
      head = prev;
   }

    // Return the number of nodes in the linked list
   size_t size(void) const
   {
      if (empty()) return 0;
      int numItems = 0;
      Node* temp = head;
      while (temp != NULL)
      {
         temp = temp->next;
         ++numItems;
      }
      return numItems;
   }
   
   // Overrides the extraction operator
   friend std::ostream& operator<<(std::ostream& os, const LinkedList& myClass)
   {
      return os << myClass.toString();
   }

   // Return contents of Linked List as a string
   std::string toString(void) const
   {
      try
      {
         if (empty()) throw std::string(" Empty!");
         std::ostringstream os;
         Node* ptr = head;
         while (ptr != NULL)
         {
            os << ptr->data;
            if (ptr->next != NULL) os << " ";
            ptr = ptr->next;
         }
         return os.str();
      } catch (std::string& errorString)
      {
         return errorString;
      }
   }
};

#endif   // LINKED_LIST_H



