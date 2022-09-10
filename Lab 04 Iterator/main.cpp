//
//  main.cpp
//  Lab 04 Iterator
//
//  Created by C/R
//

#include <iostream>
#include <fstream>
#include <string>
#include "LinkedList.h"

int main(int argc, const char * argv[]) {
    //Checking for correct number of arguments
    if (argc < 3)
    {
        std::cerr << "Please provide the name of input and output files, thanks\n";
        return 1;
    }
       
    //Checking if input file opens
    std::ifstream in(argv[1]);
    if (!in)
    {
        std::cerr << "Failure to open input file: " << argv[1] << std::endl;
        return 2;
    }
       
    //Checking if output file opens
    std::ofstream out(argv[2]);
    if (!out)
    {
        in.close();
        std::cerr << "Failure to open output file: " << argv[1] << std::endl;
        return 3;
    }
    
    
    LinkedList<std::string> linkedList;
    /*LinkedList<std::string>::Iterator iter = linkedList.begin();
    linkedList.push_front("Ten");
    linkedList.push_front("Nine");
    linkedList.push_front("Eight");
    linkedList.push_front("Seven");
    linkedList.push_front("Six");
    linkedList.push_front("Five");
    
    
    while (iter != linkedList.end())
    {
        std::cout << "[" << *iter << "]" << std::endl;
        ++iter;
    }
     std::cout << *linkedList.find(linkedList.begin(), linkedList.end(), "Seven") << std::endl;*/
    
    std::string command = " ";
    for (std::string line; getline(in, line);)
     {
         std::istringstream iss(line);
         try
         {
             //getting the command
             iss >> command;
             out << command;
             
             
             if (command == "Insert")
             {
                 std::string value = " ";
                 while (iss >> value)
                 {
                     out << " " << value;
                     linkedList.push_front(value);
                 }
             }
             else if (command == "Iterate")
             {
                 try {
                     {
                         if (linkedList.empty()) throw std::string( " Empty!");
                         LinkedList<std::string>::Iterator iter = linkedList.begin();
                         while (iter != linkedList.end())
                          {
                              out << std::endl << " [" << *iter << "]";
                             ++iter;
                          }
                     }
                 } catch (std::string errorString) {
                     out << errorString;
                 }
             }
             else if (command == "Clear")
             {
                 try
                 {
                     if (linkedList.empty())
                     {
                         throw std::string(" Empty!");
                     }
                     else
                     {
                         linkedList.clear();
                        if (linkedList.empty())
                         {
                             out << " OK";
                         }
                     }
                 } catch (std::string errorString)
                 {
                     out << " Empty!";
                 }
             }
             else if (command == "Empty")
             {
                 if (linkedList.empty())
                 {
                     out << " true";
                 }
                 else
                 {
                     out << " false";
                 }
             }
             else if (command == "PrintList")
             {
                 try
                 {
                     if (linkedList.empty())
                     {
                         throw std::string(" Empty!");
                     }
                     else
                     {
                         out << " " << linkedList;
                     }
                 } catch (std::string errorString)
                 {
                     out << " Empty!";
                 }
             }
             else if (command == "Delete")
             {
                 try
                 {
                     if (linkedList.empty())
                     {
                         throw std::string(" Empty!");
                     }
                     else
                     {
                         std::string temp = linkedList.front();
                         linkedList.pop_front();
                         if (linkedList.front() != temp) out << " OK";
                     }
                 } catch (std::string errorString)
                 {
                     out << " Empty!";
                 }
             }
             else if (command == "First")
             {
                 try
                    {
                        if (linkedList.empty())
                        {
                            throw std::string(" Empty!");
                        }
                        else
                        {
                            out << " " << linkedList.front();
                        }
                } catch (std::string errorString)
                 {
                     out << " Empty!";
                 }
        }
             else if (command == "Remove")
             {
                 try
                 {
                     if (linkedList.empty())
                     {
                         throw std::string(" Empty!");
                     }
                     else
                     {
                         std::string value = " ";
                         iss >> value;
                         out << " " << value;
                         linkedList.remove(value);
                     }
                 } catch (std::string errorString)
                 {
                     out << " Empty!";
                 }
             }
             else if (command == "Reverse")
             {
                 try
                 {
                     linkedList.reverse();
                     if (linkedList.empty())
                     {
                         throw std::string(" Empty!");
                     }
                     else
                     {
                         out << " OK";
                     }
                 } catch (std::string errorString)
                 {
                     out << " Empty!";
                 }
             }
             else if (command == "Find")
             {
                 std::string value = " ";
                 iss >> value;
                 out << " " << value;
                 try
                 {
                     linkedList.find(linkedList.begin(), linkedList.end(), value);
                     if (linkedList.empty()) throw std::string(" Empty!");
                     if (linkedList.find(linkedList.begin(), linkedList.end(), value) != linkedList.end()) out << " OK";
                     //std::cout << *linkedList.find(linkedList.begin(), linkedList.end(), value) << std::endl;
                 } catch (std::string errorString)
                 {
                     out << errorString;
                 }
             }
             else if (command == "Erase")
             {
                 std::string value = " ";
                 iss >> value;
                 out << " " << value;
                 try
                 {
                     LinkedList<std::string>::Iterator position = linkedList.begin();
                     position = linkedList.find(linkedList.begin(), linkedList.end(), value);
                     linkedList.erase(position);
                 } catch (std::string errorString)
                 {
                     out << errorString;
                 }
             }
             else if (command == "InsertAfter")
             {
                 try
                 {
                     std::string findValue = " ";
                     iss >> findValue;
                     out << " " << findValue;
                     std::string afterVal = " ";
                     iss >> afterVal;
                     out << " " << afterVal;
                     LinkedList<std::string>::Iterator position = linkedList.begin();
                     position = linkedList.find(linkedList.begin(), linkedList.end(), afterVal);
                     if (linkedList.insert_after(position, findValue) != linkedList.end())
                     {
                         out << " OK";
                     }
                     else
                     {
                         out << " Not Found";
                     }
                     if (linkedList.empty()) throw std::string(" Empty!");
                 } catch (std::string errorString)
                 {
                     out << errorString;
                 }
             }
             else if (command == "InsertBefore")
             {
                 try {
                     {
                         std::string insertValue = " ";
                         iss >> insertValue;
                         out << " " << insertValue;
                         std::string beforeVal = " ";
                         iss >> beforeVal;
                         out << " " << beforeVal;
                         LinkedList<std::string>::Iterator position = linkedList.begin();
                         position = linkedList.find(linkedList.begin(), linkedList.end(), beforeVal);
                         if (linkedList.insert(position, insertValue) != linkedList.end())
                         {
                             out << " OK";
                         }
                         else
                         {
                             out << " Not Found";
                         }
                         if (linkedList.empty()) throw std::string(" Empty!");
                     }
                 } catch (std::string errorString)
                 {
                     out << errorString;
                 }
             }
             else if (command == "Replace")
             {
                 try {
                     {
                         std::string oldVal = " ";
                         iss >> oldVal;
                         out << " " << oldVal;
                         std::string newVal = " ";
                         iss >> newVal;
                         out << " " << newVal;
                         linkedList.replace(linkedList.begin(), linkedList.end(), oldVal, newVal);
                         out << " OK";
                         if (linkedList.empty()) throw std::string(" Empty!");
                     }
                 } catch (std::string errorString)
                 {
                     out << errorString;
                 }
             }
             else {
                 throw std::string(line);
             }
         }  catch(std::string errorString)
             {
                 out << "**Error: " << line << std::endl;
             }
         out << std::endl;
     }
    return 0;
}
