# OS-ManagementScripts
Developing scripts that aid an operating system to manage processes, threads and Inter-process communications.

## 1. Create a script using C that:
- Reads any data from a standard input device.
- Writes it on the screen.
- Data should be of any length.

## 2. Create a script using C that:
- Prints the day of the week
- Forks to print the date.

## 3. Create three scripts using C:
- Script A should be the server which:
    - Print the msg received from scripts B & C
    - Reply with the msg received from script B or C.
- Script B should be a client which:
    - Send the following msg to the server: “This is Client B.”
    - Print the reply received from Script A.
- Script C should be a client which:
    - Send the following msg to the server: “I am Client C.”
    - Print the reply received from Script A.

## 4. Create a script using C that:
- Creates two threads (Thread A, Thread B).
- Threads should alternate using Mutex to print the following:
    - Thread A should print numbers from 1 to 7.
    - Thread B should print numbers even numbers from 2 to 14
- The output should be in the following sequence:
1 ➔ 2 ➔ 2 ➔ 4 ➔ 3 ➔ 6 ➔ 4➔ 8➔ 5➔ 10➔ 6➔ 12➔ 7➔ 14

