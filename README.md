# CS50 Guide System

An interactive CLI C++ application designed to help students manage CS50 lab tasks, track completion history, and archive study notes efficiently.

## Key Features & Data Structures

* **Lab Tasks Queue (`std::deque`):** Processes incoming lab tasks in First-In, First-Out (FIFO) order, while enabling front re-insertion for undo operations.
* **Undo Task History (`std::stack`):** Tracks completed tasks in Last-In, First-Out (LIFO) order to easily restore the most recently finished task.
* **Notes Archive (`std::vector`):** Dynamically stores study notes and terminal commands in contiguous memory.
* **Search Functionality:** Uses Linear Search to quickly locate keywords within saved notes.
* **Robust Input Handling:** Features `switch` control flow and string validation to ensure smooth execution and user interaction.
