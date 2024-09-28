#pragma once

#include <iostream>
#include <sstream>
using namespace std;

// Class representing an Assignee

class Assignee
{
public:

    string FirstName;
    string LastName;
    string Address;
    string Dateofbirth;
    string aID;

    // Default constructor

    Assignee() : FirstName("\0"), LastName("\0"), Address("\0"), Dateofbirth("\0"), aID("\0") 
    {
    }

    // Parameterized constructor

    Assignee(const string& fn, const string& ln, const string& a, const string& dob, const string& aid) : FirstName(fn), LastName(ln), Address(a), Dateofbirth(dob), aID(aid) 
    {
    }

    // Convert Assignee object to string

    string toString() const
    {
        stringstream ss;

        ss << "Name: " << FirstName << " " << LastName << ", Address: " << Address << ", DOB: " << Dateofbirth << ", Assignee ID: " << aID << "\n";

        return ss.str();
    }

    // Overloaded inequality operator

    friend bool operator!=(const Assignee& a1, const Assignee& a2)
    {
        if (a1.aID == a2.aID)
        {
            return false;
        }

        return true;
    }

    // Overloaded equality operator

    friend bool operator==(const Assignee& a1, const Assignee& a2)
    {
        if (a1.aID == a2.aID)
        {
            return true;
        }

        return false;
    }

    // Overloaded less than operator

    friend bool operator<(const Assignee& a1, const Assignee& a2)
    {
        if (a1.aID < a2.aID)
        {
            return true;
        }

        return false;
    }
};

// Class representing a Task

class Task 
{
public:

    long int ID;
    string Description;
    long int PriorityLevel;
    string AssID;
    bool completed;

    // Default constructor

    Task() : ID(0), Description("\0"), PriorityLevel(0), AssID("\0"), completed(false) 
    {
    }

    // Parameterized constructor

    Task(long int tid, string d, long int pl, const string& aid) : ID(tid), Description(d), PriorityLevel(pl), AssID(aid), completed(false) 
    {
    }

    // Overloaded equality operator

    friend bool operator==(const Task& t1, const Task& t2)
    {
        if (t1.ID == t2.ID)
        {
            return true;
        }

        return false;
    }

    // Overloaded less than operator

    friend bool operator<(const Task& t1, const Task& t2)
    {
        if (t1.ID < t2.ID)
        {
            return true;
        }

        return false;
    }

    // Overloaded inequality operator

    friend bool operator!=(const Task& t1, const Task& t2)
    {
        if (t1.ID != t2.ID)
        {
            return true;
        }

        return false;
    }
};

// Class representing a PriorityTask, derived from Task

class PriorityTask 
{
public:

    long int ID;
    string Description;
    long int PriorityLevel;
    string AssID;
    bool completed;
    bool deleted;

    // Default constructor

    PriorityTask() : ID(0), Description("\0"), PriorityLevel(0), AssID("\0"), completed(false), deleted(false) 
    {
    }

    // Parameterized constructor

    PriorityTask(long int tid, const string& d, long int pl, const string& aid) : ID(tid), Description(d), PriorityLevel(pl), AssID(aid), completed(false), deleted(false) 
    {
    }

    // Overloaded inequality operator

    friend bool operator!=(const PriorityTask& t1, const PriorityTask& t2)
    {
        if (t1 == t2)
        {
            return false;
        }

        return true;
    }

    // Overloaded equality operator

    friend bool operator==(const PriorityTask& t1, const PriorityTask& t2)
    {
        if (t1.ID == t2.ID)
        {
            return true;
        }

        return false;
    }

    // Overloaded less than operator

    friend bool operator<(const PriorityTask& t1, const PriorityTask& t2)
    {
        if (t1.PriorityLevel < t2.PriorityLevel)
        {
            return true;
        }

        return false;
    }
};

// Class representing a Priority Queue

class PriorityTaskQueue
{
public:

    // Node structure

    class PriorityTaskQueueNode
    {
    public:

        Task task;
        PriorityTaskQueueNode* next;

        // Default constructor

        PriorityTaskQueueNode()
        {
            next = NULL;
        }

        // Parameterized constructor

        PriorityTaskQueueNode(Task t1) : task(t1)
        {
            next = NULL;
        }
    };

    PriorityTaskQueueNode* front;

    // Default constructor

    PriorityTaskQueue()
    {
        front = NULL;
    }

    // Check if the queue is empty

    bool isempty()
    {
        if (front == NULL)
        {
            return true;
        }

        return false;
    }

    // Push a task onto the priority queue based on PriorityLevel

    void push(Task T)
    {
        PriorityTaskQueueNode* newnode = new PriorityTaskQueueNode(T);

        if (front == NULL)
        {
            newnode->next = front;
            front = newnode;
        }
        else if (T.PriorityLevel < front->task.PriorityLevel)
        {
            newnode->next = front;
            front = newnode;
        }
        else
        {
            PriorityTaskQueueNode* currentnode = front;

            // Find the appropriate position to insert the new task

            for (; currentnode->next != NULL && currentnode->next->task.PriorityLevel <= T.PriorityLevel; currentnode = currentnode->next) {}

            newnode->next = currentnode->next;
            currentnode->next = newnode;
        }
    }

    // Pop the front task from the priority queue

    void pop()
    {
        if (front != NULL)
        {
            PriorityTaskQueueNode* temp = front->next;
            delete front;
            front = temp;
        }
    }

    // Peek at the front task without removing it

    Task peek()
    {
        if (front != NULL)
        {
            return front->task;
        }

        return Task(0, "\0", -1, "\0");
    }

    // Clear the entire priority queue

    void clear()
    {
        while (front != NULL)
        {
            pop();
        }
    }

    // Destructor

    ~PriorityTaskQueue()
    {
        clear();
    }
};

template <typename T>

// Node class for a Red-Black Tree

class Node 
{
public:

    T data;  
    char color;
    Node* left;
    Node* right;
    Node* parent;

    // Default constructor

    Node() : data(0), color('R')
    {
        left = right = parent = NULL;
    }

    // Parameterized constructor

    Node(T data)
    {
        this->data = data;
        this->color = 'R';
        left = right = parent = NULL;
    }

    // Get the uncle node of the current node
    // The uncle is the sibling of the parent node

    Node* getuncle()
    {
        if (parent == NULL || parent->parent == NULL)
        {
            return NULL;
        }

        if (parent->checkifnodeonleft())
        {
            return parent->parent->right;
        }
        else
        {
            return parent->parent->left;
        }
    }

    // Check if the current node is on the left side of its parent
    // Helps in determining the orientation of the node in relation to its parent

    bool checkifnodeonleft()
    {
        if (this == parent->left)
        {
            return true;
        }

        return false;
    }

    // Get the sibling node of the current node
    // The sibling is the other child of the parent node

    Node* getsibling()
    {
        if (parent == NULL)
        {
            return NULL;
        }

        if (checkifnodeonleft())
        {
            return parent->right;
        }

        return parent->left;
    }

    // Check if any child of the current node has a red color
    // Used in Red-Black Tree insertion to identify red-violations

    bool checkchildcolor()
    {
        if (left != NULL)
        {
            if (left->color == 'R')
            {
                return true;
            }
        }

        if (right != NULL)
        {
            if (right->color == 'R')
            {
                return true;
            }
        }

        return false;
    }
};

template <typename T>

// Red-Black Tree Implementation

class RBTree
{
public:

    Node<T>* root;

    // Default constructor initializes the root to NULL
    
    RBTree()
    {
        root = NULL;
    }

    // Perform a left rotation around the specified node
   
    void rol(Node<T>* node)
    {
        // Store the right child of the given node
      
        Node<T>* parentnode = node->right;

        // Update the root if the given node is the current root
        
        if (node == root)
        {
            root = parentnode;
        }

        // Update the parent's left or right pointer to the new node
        
        if (node->parent != NULL)
        {
            if (node->checkifnodeonleft() == true)
            {
                node->parent->left = parentnode;
            }
            else if (node->checkifnodeonleft() == false)
            {
                node->parent->right = parentnode;
            }
        }

        // Update parent pointers
        
        parentnode->parent = node->parent;
        node->parent = parentnode;

        // Update child pointers
        
        node->right = parentnode->left;

        if (parentnode->left != NULL)
        {
            parentnode->left->parent = node;
        }

        parentnode->left = node;
    }

    // Perform a right rotation around the specified node
    
    void ror(Node<T>* node)
    {
        // Store the left child of the given node
       
        Node<T>* parentnode = node->left;

        // Update the root if the given node is the current root
        
        if (node == root)
        {
            root = parentnode;
        }

        // Update the parent's left or right pointer to the new node
        
        if (node->parent != NULL)
        {
            if (node->checkifnodeonleft() == true)
            {
                node->parent->left = parentnode;
            }
            else if (node->checkifnodeonleft() == false)
            {
                node->parent->right = parentnode;
            }
        }

        // Update parent pointers
      
        parentnode->parent = node->parent;
        node->parent = parentnode;

        // Update child pointers
        node->left = parentnode->right;
        if (parentnode->right != NULL)
        {
            parentnode->right->parent = node;
        }

        parentnode->right = node;
    }

    // Fix any red-violation issues after an insertion
    
    void fixredviolation(Node<T>* node)
    {
        // Check if the node is not the root
      
        if (node != root)
        {
            Node<T>* parent = node->parent;
            Node<T>* grandparent = parent->parent;
            Node<T>* uncle = node->getuncle();

            // Check if the parent is black
        
            if (parent->color == 'B')
            {
                // No violation, return

                return; 
            }
            else
            {
                // Check if uncle is present and red
              
                if (uncle != NULL)
                {
                    if (uncle->color == 'R')
                    {
                        // Case: Parent and uncle are red
                        // Resolve violation and recursively fix upwards
                
                        parent->color = 'B';
                        uncle->color = 'B';
                        grandparent->color = 'R';

                        fixredviolation(grandparent);
                    }
                }
                else
                {
                    // Case: Uncle is black or NULL
                  
                    if (parent->checkifnodeonleft() == false)
                    {
                        if (node->checkifnodeonleft() == false)
                        {
                            // Case: Right child of right child
                            // Single left rotation
                    
                            char temp = parent->color;
                            parent->color = grandparent->color;
                            grandparent->color = temp;
                        }
                        else
                        {
                            // Case: Left child of right child
                            // Right-Left rotation
                         
                            ror(parent);

                            char temp = node->color;
                            node->color = grandparent->color;
                            grandparent->color = temp;
                        }

                        // Single left rotation
                      
                        rol(grandparent);
                    }
                    else
                    {
                        if (node->checkifnodeonleft() == false)
                        {
                            // Case: Right child of left child
                            // Left-Right rotation
                          
                            rol(parent);

                            char temp = node->color;
                            node->color = grandparent->color;
                            grandparent->color = temp;
                        }
                        else
                        {
                            // Case: Left child of left child
                            // Single right rotation
                           
                            char temp = parent->color;
                            parent->color = grandparent->color;
                            grandparent->color = temp;
                        }

                        // Single right rotation
                       
                        ror(grandparent);
                    }
                }
            }
        }
        else
        {
            // Case: Node is the root, set color to black
          
            node->color = 'B';
        }
    }

    // Fix any black-violation issues after a deletion
    
    void fixblackviolation(Node<T>* node)
    {
        // Check if the node is not the root
      
        if (node != root)
        {
            Node<T>* sibling = node->getsibling();
            Node<T>* parent = node->parent;

            // Check if sibling is present
           
            if (sibling != NULL)
            {
                // Case: Sibling is red
            
                if (sibling->color == 'R')
                {
                    // Set parent to red and sibling to black
                
                    parent->color = 'R';
                    sibling->color = 'B';

                    // Perform rotation based on the sibling's position
                    
                    if (sibling->checkifnodeonleft() == false)
                    {
                        rol(parent);
                    }
                    else
                    {
                        ror(parent);
                    }

                    // Continue fixing violations
                   
                    fixblackviolation(node);
                }
                else
                {
                    // Case: Sibling is black
                   
                    if (sibling->checkchildcolor() == true)
                    {
                        // Case: At least one red child
                       
                        if (sibling->left != NULL)
                        {
                            if (sibling->left->color == 'R')
                            {
                                // Case: Left red child
                        
                                if (sibling->checkifnodeonleft())
                                {
                                    sibling->left->color = sibling->color;
                                    sibling->color = parent->color;
                                    ror(parent);
                                }
                                else
                                {
                                    sibling->left->color = parent->color;
                                    ror(sibling);
                                    rol(parent);
                                }
                            }
                        }
                        else
                        {
                            if (sibling->checkifnodeonleft() == false)
                            {
                                // Case: Right red child
                              
                                sibling->right->color = sibling->color;
                                sibling->color = parent->color;
                                rol(parent);
                            }
                            else
                            {
                                // Case: Left red child
                                
                                sibling->right->color = parent->color;
                                rol(sibling);
                                ror(parent);
                            }

                            // Set parent to black
                            
                            parent->color = 'B';
                        }
                    }
                    else
                    {
                        // Case: Both children are black
                       
                        sibling->color = 'R';

                        // If parent is red, set it to black; otherwise, fix violations upwards
                        
                        if (parent->color == 'R')
                        {
                            parent->color = 'B';
                        }
                        else
                        {
                            fixblackviolation(parent);
                        }
                    }
                }
            }
            else
            {
                // Case: No sibling, continue fixing violations upwards
               
                fixblackviolation(parent);
            }
        }
    }

    // Replace a node in the tree during deletion
   
    Node<T>* replacetree(Node<T>* node)
    {
        // Find the maximum node in the left subtree
       
        if (node->left != NULL)
        {
            Node<T>* temp;

            for (temp = node->left; temp->right != NULL; temp = temp->right)
            {
            }

            return temp;
        }

        // Find the minimum node in the right subtree
        
        if (node->right != NULL)
        {
            return node->right;
        }

        // No child, return NULL
       
        return NULL;
    }

    // Delete a node from the Red-Black Tree
    
    void deletion(Node<T>* node)
    {
        // Find the replacement node
    
        Node<T>* nodeafterdeletion = replacetree(node);

        bool blackcheck;

        // Check if both the replacement node and the original node are black
        
        if ((nodeafterdeletion == NULL || nodeafterdeletion->color == 'B') && (node->color == 'B'))
        {
            blackcheck = true;
        }
        else
        {
            blackcheck = false;
        }

        Node<T>* parent = node->parent;

        // Handle the case where the replacement node is NULL
       
        if (nodeafterdeletion == NULL)
        {
            // If the node to be deleted is the root
        
            if (node == root)
            {
                root = NULL;
            }
            else
            {
                // If the original node and replacement node are both black, fix violations
               
                if (blackcheck == true)
                {
                    fixblackviolation(node);
                }
                else
                {
                    // If sibling exists, set it to red
                   
                    if (node->getsibling() != NULL)
                    {
                        node->getsibling()->color = 'R';
                    }
                }

                // Update parent's left or right pointer to NULL
               
                if (node->checkifnodeonleft())
                {
                    parent->left = NULL;
                }
                else
                {
                    parent->right = NULL;
                }
            }

            // Delete the node and return
           
            delete node;
            return;
        }

        // Handle the case where the node to be deleted has one child
       
        if (node->left == NULL || node->right == NULL)
        {
            // If the node to be deleted is the root
         
            if (node == root)
            {
                // Copy data from replacement node to the root
              
                node->data = nodeafterdeletion->data;
                node->left = node->right = NULL;

                // Delete the replacement node
              
                delete nodeafterdeletion;
            }
            else
            {
                // Update parent's left or right pointer to the replacement node
             
                if (node->checkifnodeonleft())
                {
                    parent->left = nodeafterdeletion;
                }
                else
                {
                    parent->right = nodeafterdeletion;
                }

                // Delete the original node
               
                delete node;

                // Update replacement node's parent pointer
               
                nodeafterdeletion->parent = parent;

                // If both the original and replacement nodes are black, fix violations
               
                if (blackcheck)
                {
                    fixblackviolation(nodeafterdeletion);
                }
                else
                {
                    // Set replacement node to black
                   
                    nodeafterdeletion->color = 'B';
                }
            }

            return;
        }

        // Handle the case where the node to be deleted has two children
      
        T temp = nodeafterdeletion->data;
        nodeafterdeletion->data = node->data;
        node->data = temp;

        // Recursively delete the replacement node
     
        deletion(nodeafterdeletion);
    }

    // Search for a node with a specific data value
   
    Node<T>* nodesearch(T searchdata)
    {
        // Start from the root
    
        Node<T>* temp;

        // Traverse the tree until a match is found or the end is reached
        
        for (temp = root; temp != NULL;)
        {
            if (searchdata < temp->data)
            {
                if (temp->left == NULL)
                {
                    break;
                }
                else
                {
                    temp = temp->left;
                }
            }
            else if (searchdata == temp->data)
            {
                break;
            }
            else
            {
                if (temp->right == NULL)
                {
                    break;
                }
                else
                {
                    temp = temp->right;
                }
            }
        }

        // Return the node containing the search data (or NULL if not found)
        
        return temp;
    }

    // Insert a new node with the specified data value
    
    void insertion(T insertdata)
    {
        // Check if the tree is empty
       
        if (root == NULL)
        {
            // Create a new node, set color to black, and make it the root
           
            Node<T>* newnode = new Node<T>(insertdata);
            newnode->color = 'B';
            root = newnode;
        }
        else
        {
            // Create a new node with the given data
           
            Node<T>* newnode = new Node<T>(insertdata);

            // Find the appropriate position for the new node
            
            Node<T>* temp = nodesearch(insertdata);

            // Check if the data already exists in the tree
            
            if (temp->data != insertdata)
            {
                // Set the parent of the new node to the found node
            
                newnode->parent = temp;

                // Update the left or right pointer of the parent based on the data comparison
                
                if (insertdata < temp->data)
                {
                    temp->left = newnode;
                }
                else
                {
                    temp->right = newnode;
                }

                // Fix any red-violation issues after insertion
               
                fixredviolation(newnode);
            }
        }
    }

    // Delete a node with the specified data value
    
    void valuedeletion(T deletedata)
    {
        // Check if the tree is not empty
        
        if (root != NULL)
        {
            // Find the node with the specified data value
            
            Node<T>* node = nodesearch(deletedata);

            // Check if the data exists in the tree
          
            if (node->data != deletedata)
            {
                // Data not found, return

                return;
            }

           
            // Perform the deletion operation
            deletion(node);
        }
    }

    // Display nodes with a specific name using recursive traversal
    
    void displaybynamerecursive(Node<T>* node, ostream& out, const string& fn, const string& ln)
    {
        // Recursive in-order traversal
        
        if (node != NULL)
        {
            // Traverse left subtree
            
            displaybynamerecursive(node->left, out, fn, ln);
            
            // Process the current node
          
            if (typeid(T) == typeid(Assignee))
            {
                Assignee& ass = node->data;

                // Check if the first and last names match the specified values
                
                if (ass.FirstName == fn && ass.LastName == ln)
                {
                    // Output the information of the matching node
            
                    out << ass.toString();
                }
            }

            // Traverse right subtree
    
            displaybynamerecursive(node->right, out, fn, ln);
        }
    }

    // Display nodes with a specific name
    
    void displaybyname(ostream& out, const string& fn, const string& ln)
    {
        // Start the recursive traversal from the root
      
        displaybynamerecursive(root, out, fn, ln);
    }
};

// Class for Task Management System

class taskManagementSystem
{
public:

    RBTree<Assignee> assigneetree;
    RBTree<Task> tasktree;
    RBTree<PriorityTask> taskprioritytree;
    long int assigneeidcount = 1;

    // Add a new assignee to the system
   
    void addAssignee(const string& fn, const string& ln, const string& add, const string& dob)
    {
        // Generate a unique assignee ID
    
        string assid = "A00" + to_string(assigneeidcount);
        assigneeidcount++;

        // Create a new Assignee object
       
        Assignee newassignee;
        newassignee.FirstName = fn;
        newassignee.LastName = ln;
        newassignee.Address = add;
        newassignee.Dateofbirth = dob;
        newassignee.aID = assid;

        // Insert the new assignee into the assignee tree
        
        assigneetree.insertion(newassignee);
    }

    // Add a new task to the system
   
    void addTask(int id, string des, int pl, const string& assid)
    {
        // Create a new Task object
    
        Task newtask;
        newtask.ID = id;
        newtask.Description = des;
        newtask.PriorityLevel = pl;
        newtask.AssID = assid;

        // Insert the new task into both task trees
        
        tasktree.insertion(newtask);

        PriorityTask pnewtask;
        pnewtask.ID = id;
        pnewtask.Description = des;
        pnewtask.PriorityLevel = pl;
        pnewtask.AssID = assid;

        taskprioritytree.insertion(pnewtask);
    }

    // Display information about an assignee based on their ID
   
    void displaybyID(ostream& out, const string& id)
    {
        // Create a temporary Assignee with the provided ID for searching
      
        Assignee node("\0", "\0", "\0", "\0", id);

        // Search for the assignee in the assignee tree
       
        Node<Assignee>* actualnode = assigneetree.nodesearch(node);

        if (actualnode != NULL)
        {
            // Check if the found node has the expected ID and print information
            
            if (actualnode->data.aID == id)
            {
                out << actualnode->data.toString();
            }
        }
    }

    // Display information about assignees based on their first and last names
   
    void displaybyname(ostream& out, const string& fn, const string& ln)
    {
        assigneetree.displaybyname(out, fn, ln);
    }

    // Check if a task is assigned to a given assignee
    
    bool lookfortask(Node<Task>* node, const string& assid)
    {
        if (node == NULL)
        {
            return false;
        }

        // Check if the task is assigned to the given assignee ID
       
        if (node->data.AssID == assid)
        {
            return true;
        }

        // Recursively search in the left and right subtrees
      
        return lookfortask(node->left, assid) || lookfortask(node->right, assid);
    }

    // Check and print assignees with no tasks
   
    void checkassigneewithnotaskrecursive(Node<Assignee>* node, ostream& out)
    {
        if (node != NULL)
        {
            // Recursively check left subtree
            
            checkassigneewithnotaskrecursive(node->left, out);

            // Check if the assignee has no tasks and print information
           
            if (lookfortask(tasktree.root, node->data.aID) == false)
            {
                out << node->data.toString();
            }

            // Recursively check right subtree
           
            checkassigneewithnotaskrecursive(node->right, out);
        }
    }

    // Display assignees with no tasks
   
    void AssigneeWithNoTask(ostream& out)
    {
        checkassigneewithnotaskrecursive(assigneetree.root, out);
    }

    // Shift tasks from one assignee to another
    
    void taskshifter(Node<Task>* node, const string& id1, const string& id2)
    {
        if (node != NULL)
        {
            // Recursively traverse the tree
           
            taskshifter(node->left, id1, id2);
            taskshifter(node->right, id1, id2);

            // Check if the task is assigned to the first assignee
           
            if (node->data.AssID == id1)
            {
                // Create a new task with the same details but assigned to the second assignee
               
                Task newtask = node->data;
                newtask.AssID = id2;

                // Delete the original task and insert the new task
               
                tasktree.deletion(node);
                tasktree.insertion(newtask);
            }
        }
    }

    // Shift tasks from one assignee to another
   
    void ShiftTask(const string& id1, const string& id2)
    {
        taskshifter(tasktree.root, id1, id2);
    }

    // Fill priority queue with incomplete tasks
   
    void fillvaluesintoqueue(Node<Task>* node, PriorityTaskQueue& tpq)
    {
        if (node != NULL)
        {
            // Check if the task is incomplete and push it onto the priority queue
            
            if (node->data.completed == false)
            {
                tpq.push(node->data);
            }

            // Recursively traverse the left and right subtrees
            
            fillvaluesintoqueue(node->left, tpq);
            fillvaluesintoqueue(node->right, tpq);
        }
    }

    // Return the name of an assignee given their ID
    
    string returnassigneename(const string& assid)
    {
        // Search for the assignee in the assignee tree
        
        Node<Assignee>* assnode = assigneetree.nodesearch(Assignee("\0", "\0", "\0", "\0", assid));

        if (assnode != NULL)
        {
            // Check if the found node has the expected ID and construct the assignee name
        
            if (assnode->data.aID == assid)
            {
                string returnstring = assnode->data.FirstName + " (" + assid + ")";
                return returnstring;
            }
        }
    }

    // Print tasks in priority order
   
    void printTaskQueue(ostream& out)
    {
        PriorityTaskQueue priorityqueue;

        // Fill the priority queue with incomplete tasks
    
        fillvaluesintoqueue(tasktree.root, priorityqueue);

        // Process each task in the priority queue
        
        for (; priorityqueue.isempty() == false; priorityqueue.pop())
        {
            Task currenttask = priorityqueue.peek();

            // Get the name of the assignee

            string assignee = returnassigneename(currenttask.AssID);

            // Print task information

            out << "Task ID: " << currenttask.ID << ", Description: " << currenttask.Description << ", Priority: " << currenttask.PriorityLevel << ", Assignee: " << assignee << "\n";
        }
    }

    // Check if an assignee has tasks recursively
    
    bool checkassigneetasksrecursive(Node<Task>* node, const string& assid)
    {
        if (node == NULL)
        {
            return false;
        }
        else if (node->data.AssID == assid)
        {
            return true;
        }

        // Recursively search in the left and right subtrees
      
        return checkassigneetasksrecursive(node->left, assid) || checkassigneetasksrecursive(node->right, assid);
    }

    // Delete an assignee if they have no tasks
   
    void DeleteAssignee(const string& assid)
    {
        // Check if the assignee has no tasks and delete them
        
        if (checkassigneetasksrecursive(tasktree.root, assid) == false)
        {
            Assignee deleted("\0", "\0", "\0", "\0", assid);
            assigneetree.valuedeletion(deleted);
        }
    }

    // Display assignees in an in-order traversal
   
    void displayassigneeinorder(Node<Assignee>* node, ostream& out)
    {
        if (node != NULL)
        {
            // Recursively traverse the left subtree
           
            displayassigneeinorder(node->left, out);

            // Print assignee information
           
            out << "Name: " << node->data.FirstName << " " << node->data.LastName << ", Address: " << node->data.Address << ", DOB: " << node->data.Dateofbirth << ", Assignee ID: " << node->data.aID << "\n";

            // Recursively traverse the right subtree
           
            displayassigneeinorder(node->right, out);
        }
    }

    // Display all assignees in the system
    
    void DisplayAssignee(ostream& out)
    {
        displayassigneeinorder(assigneetree.root, out);
    }

    // Display assignees and their node color in an in-order traversal
    
    void printassigneeinorder(Node<Assignee>* node, ostream& out)
    {
        if (node != NULL)
        {
            // Recursively traverse the left subtree
           
            printassigneeinorder(node->left, out);

            // Print assignee ID and color information
           
            out << node->data.aID << " (";

            if (node->color == 'R')
            {
                out << "red";
            }
            else
            {
                out << "black";
            }

            out << ")\n";

            // Recursively traverse the right subtree
           
            printassigneeinorder(node->right, out);
        }
    }

    // Display assignees and their node color in an in-order traversal
   
    void AssigneeInOrder(ostream& out)
    {
        printassigneeinorder(assigneetree.root, out);
    }

    // Mark a task as completed given its ID
    
    void completeTask(int id)
    {
        // Search for the task in the task tree
       
        Task nodetofind(id, "\0", 0, "\0");
        Node<Task>* node = tasktree.nodesearch(nodetofind);

        if (node != NULL)
        {
            // Check if the found node has the expected ID and mark the task as completed
           
            if (node->data.ID == id)
            {
                node->data.completed = true;
            }
        }
    }

    // Update the priority level of a task given its ID
    
    void updateTaskPriority(int id, int num)
    {
        // Search for the task in the task tree
       
        Task nodetofind(id, "\0", 0, "\0");
        Node<Task>* node = tasktree.nodesearch(nodetofind);

        if (node != NULL)
        {
            // Check if the found node has the expected ID
          
            if (node->data.ID == id)
            {
                // Get the current priority level of the task
               
                long int current = node->data.PriorityLevel;

                // Create a PriorityTask node to search in the priority task tree
               
                PriorityTask nodetoget(id, "\0", current, "\0");
                Node<PriorityTask>* foundnode = taskprioritytree.nodesearch(nodetoget);

                if (foundnode != NULL)
                {
                    // Check if the found node has the expected priority level
                   
                    if (foundnode->data.PriorityLevel == current)
                    {
                        // Update the priority level of the task
                       
                        node->data.PriorityLevel = num;

                        // Create a new PriorityTask node with the updated priority level
                       
                        PriorityTask newtask = foundnode->data;
                        newtask.PriorityLevel = num;

                        // Delete the original node and insert the new node into the priority task tree
                        
                        taskprioritytree.valuedeletion(foundnode->data);
                        taskprioritytree.insertion(newtask);
                    }
                }
            }
        }
    }

    // Find and print the highest priority task
    
    void findHighestPriorityTask(ostream& out)
    {
        if (tasktree.root != NULL)
        {
            // Create a priority queue to store incomplete tasks
            
            PriorityTaskQueue tpq;

            // Fill the priority queue with incomplete tasks
            
            fillvaluesintoqueue(tasktree.root, tpq);

            if (tpq.isempty() == true)
            {
                return;
            }
            else
            {
                // Process tasks with the highest priority level
              
                for (int prioritytask = tpq.peek().PriorityLevel; tpq.isempty() == false && tpq.peek().PriorityLevel == prioritytask; tpq.pop())
                {
                    Task toptask = tpq.peek();

                    // Get the name of the assignee
                  
                    string assignee = returnassigneename(toptask.AssID);

                    // Print information about the highest priority task

                    out << "Highest Priority Task: Task ID: " << toptask.ID << ", Description: " << toptask.Description << ", Priority: " << toptask.PriorityLevel << ", Assignee: " << assignee << "\n";
                }
            }
        }
    }

    // Find and add tasks assigned to a specific assignee to the priority task queue
    
    void findtasksbyass(Node<Task>* node, const string& id, PriorityTaskQueue& tpq)
    {
        if (node != NULL)
        {
            // Recursively traverse the left subtree
            
            findtasksbyass(node->left, id, tpq);

            // Check if the task is assigned to the given assignee and push it onto the queue
            
            if (node->data.AssID == id)
            {
                tpq.push(node->data);
            }

            // Recursively traverse the right subtree
           
            findtasksbyass(node->right, id, tpq);
        }
    }

    // Find and print tasks assigned to a specific assignee
    
    void findTasksByAssignee(const string& id, ostream& out)
    {
        if (tasktree.root != NULL)
        {
            // Get the name of the assignee
           
            string assignee = returnassigneename(id);

            // Create a priority task queue
            
            PriorityTaskQueue tpq;

            // Find tasks assigned to the given assignee and add them to the queue
            
            findtasksbyass(tasktree.root, id, tpq);

            // Print tasks assigned to the assignee
            
            if (tpq.isempty() != true)
            {
                out << "Tasks Assigned to \"" << assignee << "\":\n";

                for (; tpq.isempty() == false; tpq.pop())
                {
                    Task T = tpq.peek();

                    // Print task information
                 
                    out << "Task ID: " << T.ID << ", Description: " << T.Description << ", Priority: " << T.PriorityLevel << ", Assignee: " << assignee << "\n";
                }
            }
        }
    }

    // Count the total number of tasks in the system recursively
    
    int counttasksrecursive(Node<Task>* node)
    {
        if (node == NULL)
        {
            return 0;
        }

        // Return the count of tasks in the left subtree, right subtree, and the current node
    
        return 1 + counttasksrecursive(node->left) + counttasksrecursive(node->right);
    }

    // Count and print the total number of tasks in the system
   
    void countTotalTasks(ostream& out)
    {
        int totaltasks = counttasksrecursive(tasktree.root);

        // Print the total number of tasks
       
        out << "Total Tasks in the System: " << totaltasks << "\n";
    }

    // Find and add tasks within a specified priority range to the priority task queue
    
    void lookfortasksbypriority(Node<Task>* node, int num1, int num2, PriorityTaskQueue& tpq)
    {
        if (node != NULL)
        {
            // Recursively traverse the left subtree
           
            lookfortasksbypriority(node->left, num1, num2, tpq);

            // Check if the task priority is within the specified range and push it onto the queue
            
            if (node->data.PriorityLevel >= num1 && node->data.PriorityLevel <= num2)
            {
                tpq.push(node->data);
            }

            // Recursively traverse the right subtree
           
            lookfortasksbypriority(node->right, num1, num2, tpq);
        }
    }

    // Find and print tasks within a specified priority range
    
    void searchTasksByPriorityRange(int num1, int num2, ostream& out)
    {
        // Create a priority task queue
       
        PriorityTaskQueue tpq;

        // Find tasks within the specified priority range and add them to the queue
       
        lookfortasksbypriority(tasktree.root, num1, num2, tpq);

        // Print tasks within the priority range
       
        if (tpq.isempty() == false)
        {
            out << "Tasks within Priority Range (" << num1 << " to " << num2 << "):\n";

            for (; tpq.isempty() == false; tpq.pop())
            {
                Task T = tpq.peek();
                string assignee = returnassigneename(T.AssID);

                // Print task information
                
                out << "Task ID: " << T.ID << ", Description: " << T.Description << ", Priority: " << T.PriorityLevel << ", Assignee: " << assignee << "\n";
            }
        }
    }

    // Find and print completed tasks
   
    void showdonetasks(Node<Task>* node, ostream& out)
    {
        if (node != NULL)
        {
            // Recursively traverse the left subtree
            
            showdonetasks(node->left, out);

            // Check if the task is completed and print information
            
            if (node->data.completed == false)
            {
                // Do nothing for incomplete tasks
            }
            else
            {
                string assignee = returnassigneename(node->data.AssID);

                // Print information about completed tasks
                
                out << "Task ID: " << node->data.ID << ", Description: " << node->data.Description << ", Priority: " << node->data.PriorityLevel << ", Assignee: " << assignee << "\n";
            }

            // Recursively traverse the right subtree
            
            showdonetasks(node->right, out);
        }
    }

    // Display completed tasks
   
    void displayCompletedTasks(ostream& out)
    {
        out << "Completed Tasks:\n";

        // Print information about completed tasks
       
        showdonetasks(tasktree.root, out);
    }

    // Display the priority task tree in an in-order traversal
    
    void inordertreeprint(Node<PriorityTask>* node, ostream& out)
    {
        if (node != NULL)
        {
            // Recursively traverse the left subtree
           
            inordertreeprint(node->left, out);

            // Check if the node is marked as deleted and print information
            
            if (node->data.deleted == true)
            {
                // Do nothing for deleted nodes
            }
            else
            {
                // Print task ID and color information
                
                out << node->data.ID << " (";

                if (node->color == 'R')
                {
                    out << "red";
                }
                else
                {
                    out << "black";
                }

                out << ")\n";
            }

            // Recursively traverse the right subtree
            
            inordertreeprint(node->right, out);
        }
    }

    // Print the priority task tree in an in-order traversal
   
    void PrintTreeInorder(ostream& out)
    {
        inordertreeprint(taskprioritytree.root, out);
    }

    // Delete a task given its ID
   
    void deleteTask(int id)
    {
        // Search for the task in the task tree
      
        Task nodetofind(id, "\0", 0, "\0");
        Node<Task>* node = tasktree.nodesearch(nodetofind);

        if (node != NULL)
        {
            // Check if the found node has the expected ID
          
            if (node->data.ID == id)
            {
                // Get the current priority level of the task
               
                long int current = node->data.PriorityLevel;

                // Create a PriorityTask node to search in the priority task tree
               
                PriorityTask nodetoget(id, "\0", current, "\0");
                Node<PriorityTask>* newfound = taskprioritytree.nodesearch(nodetoget);

                if (newfound != NULL)
                {
                    // Check if the found node has the expected priority level
                  
                    if (newfound->data.PriorityLevel == current)
                    {
                        // Mark the node as deleted and delete it from the priority task tree and task tree
                      
                        newfound->data.deleted = true;
                        taskprioritytree.valuedeletion(newfound->data);
                        tasktree.valuedeletion(node->data);
                    }
                }
            }
        }
    }
};