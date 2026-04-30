# Challenge: Code Review

## Task

Assume you are given the (incomplete and possibly faulty) code snippet on the following page
for a code review. The target architecture is a Cortex-M microcontroller running a realtime
operating system, e.g. FreeRTOS.

Please analyze the code and look for errors, bugs or architectural problems. Create comments
in the code indicating and describing the problems you have found.

Ask yourself the following questions to get an idea what you should be looking for:

1. In which parts of the memory are the different variables allocated?
2. When are variables allocated and initialized / deinitialized and deallocated?
3. Is there a need for synchronization in the code, including the send/receive_event api? If
so, suggest and evaluate different mechanisms.

Please send in the commented code and any textual answers you find relevant. To make the
found problems clearer you can send in an improved version of the code containing a rationale
for the changes you propose.

**Please prepare yourself to answer questions to the code and contained problems in discussion with the colleagues directly following the formal second interview.**
