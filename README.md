# Task Management System

## Overview

The **Task Management System** is an efficient solution designed for managing tasks, assignees, and priorities using **Red-Black Trees**. This system enables organizations or teams to manage and track tasks, prioritize them, assign tasks to individuals, and perform various operations such as task shifting, updating priorities, and deleting tasks. It supports the functionality of assigning tasks based on priorities and assignee and ensures a structured order by using **RB Trees** for task and assignee management.

## Features

- **Add Assignees & Tasks:** Assign tasks to team members and prioritize them efficiently.
- **Task Prioritization:** Organize tasks based on priority using a custom priority queue.
- **Assignee Management:** View, add, and remove assignees. Identify assignees with no tasks assigned.
- **Task Shifting:** Shift tasks from one assignee to another.
- **Task Completion Tracking:** Mark tasks as completed and display completed tasks.
- **Priority Range Search:** Search and display tasks within a specific priority range.
- **Task Deletion:** Safely delete tasks when needed and update task priority efficiently.

## Data Structures Used

1. **Red-Black Trees:** 
   - The system uses red-black trees for storing assignees, tasks, and priority tasks. This ensures balanced, fast search, insertion, and deletion operations, making the system efficient in handling large data sets.
  
2. **Priority Queue:** 
   - A custom priority queue is used to handle incomplete tasks, allowing the system to identify and manage the highest priority tasks efficiently.

## Key Functionalities

1. **Add Assignee:**
   - Add a new assignee to the system with a unique assignee ID.
   - Syntax: `addAssignee(firstName, lastName, address, dateOfBirth)`

2. **Add Task:**
   - Add tasks to the system with a unique task ID, description, priority level, and assignee ID.
   - Syntax: `addTask(taskID, description, priorityLevel, assigneeID)`

3. **Display Assignee Info by ID or Name:**
   - Retrieve and display information about a specific assignee by ID or name.
   - Syntax: `displaybyID(outputStream, assigneeID)`
   - Syntax: `displaybyname(outputStream, firstName, lastName)`

4. **Check for Tasks Without Assignees:**
   - Identify assignees who do not have any tasks assigned to them.
   - Syntax: `AssigneeWithNoTask(outputStream)`

5. **Shift Task Between Assignees:**
   - Shift all tasks from one assignee to another.
   - Syntax: `ShiftTask(assigneeID1, assigneeID2)`

6. **Display Task Queue:**
   - Print tasks in order of priority and the assigned assignee.
   - Syntax: `printTaskQueue(outputStream)`

7. **Task Completion:**
   - Mark tasks as completed using their task ID.
   - Syntax: `completeTask(taskID)`

8. **Update Task Priority:**
   - Update the priority of an existing task.
   - Syntax: `updateTaskPriority(taskID, newPriorityLevel)`

9. **Find Highest Priority Task:**
   - Identify and display the highest priority task in the system.
   - Syntax: `findHighestPriorityTask(outputStream)`

10. **Task Deletion:**
    - Delete a task from the system.
    - Syntax: `deleteTask(taskID)`

11. **Count Total Tasks:**
    - Count and display the total number of tasks in the system.
    - Syntax: `countTotalTasks(outputStream)`

12. **Search Tasks by Priority Range:**
    - Search for tasks within a specified priority range and display them.
    - Syntax: `searchTasksByPriorityRange(priorityLow, priorityHigh, outputStream)`

13. **Display Completed Tasks:**
    - Show a list of tasks that have been marked as completed.
    - Syntax: `displayCompletedTasks(outputStream)`

## License

This project is open-source and available under the MIT License. Feel free to contribute, use, and modify it as needed.
