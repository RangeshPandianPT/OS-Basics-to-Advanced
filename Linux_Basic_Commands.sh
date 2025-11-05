A) BASIC COMMANDS

| Command      | Description                             |
| ------------ | --------------------------------------- |
| `echo SRM`   | Displays the string **SRM**             |
| `clear`      | Clears the terminal screen              |
| `date`       | Displays the current date and time      |
| `cal 2003`   | Displays the calendar for the year 2003 |
| `cal 6 2003` | Displays the calendar for **June 2003** |
| `passwd`     | Used to change the user password        |

B) WORKING WITH FILES

| Command      | Description                                                   |
| ------------ | ------------------------------------------------------------- |
| `ls`         | Lists files in the current directory                          |
| `ls -l`      | Lists files with detailed (long) information                  |
| `ls -a`      | Lists all files including hidden files                        |
| `cat > f1`   | Creates a new file **f1** (Press `Ctrl + D` to save and exit) |
| `cat f1`     | Displays the content of **f1**                                |
| `wc f1`      | Displays number of **lines, words, and characters** in **f1** |
| `wc -c f1`   | Displays **number of characters** in **f1**                   |
| `wc -w f1`   | Displays **number of words** in **f1**                        |
| `wc -l f1`   | Displays **number of lines** in **f1**                        |
| `cp f1 f2`   | Copies file **f1** into **f2**                                |
| `mv f1 f2`   | Renames **f1** to **f2**                                      |
| `rm f1`      | Deletes (removes) **f1**                                      |
| `head -5 f1` | Displays the first **5 lines** of **f1**                      |
| `tail -5 f1` | Displays the last **5 lines** of **f1**                       |

C) WORKING WITH DIRECTORIES

| Command       | Description                                     |
| ------------- | ----------------------------------------------- |
| `mkdir elias` | Creates a directory named **elias**             |
| `cd elias`    | Changes directory to **elias**                  |
| `rmdir elias` | Removes the directory **elias**                 |
| `pwd`         | Displays the **current working directory path** |
| `cd`          | Moves to the **home directory**                 |
| `cd ..`       | Moves to the **parent directory**               |
| `cd -`        | Switches to the **previous working directory**  |
| `cd /`        | Moves to the **root directory**                 |

D) FILE NAME SUBSTITUTION

| Command            | Description                                                                        |
| ------------------ | ---------------------------------------------------------------------------------- |
| `ls f?`            | Lists files starting with ‘f’ followed by any **one** character                    |
| `ls *.c`           | Lists files with extension **.c**                                                  |
| `ls [gpy]et`       | Lists files starting with **g**, **p**, or **y** and ending with **et**            |
| `ls [a-d,l-m]ring` | Lists files starting with any letter from **a–d** or **l–m**, ending with **ring** |

E) I/O REDIRECTION

| Command       | Description                                                   |
| ------------- | ------------------------------------------------------------- |
| `wc -l < ex1` | Finds the number of lines in file **ex1** (Input redirection) |
| `who > f2`    | Redirects output of `who` command to file **f2**              |
| `cat >> f1`   | Appends additional content to file **f1**                     |

F) PIPING

| Syntax      | Description |                                                      |
| ----------- | ----------- | ---------------------------------------------------- |
| `Command1   | Command2`   | Output of **Command1** becomes input of **Command2** |
| `cat f1     | more`       | Displays contents of **f1** one screen at a time     |
| `head -6 f1 | tail -2`    | Displays **5th and 6th lines** of **f1**             |

G) ENVIRONMENT VARIABLES

| Command         | Description                                               |
| --------------- | --------------------------------------------------------- |
| `echo $HOME`    | Displays path of **home directory**                       |
| `echo $PS1`     | Displays the **primary prompt string** (`$` by default)   |
| `echo $PS2`     | Displays the **secondary prompt string** (`>` by default) |
| `echo $LOGNAME` | Displays the **login name**                               |
| `echo $PATH`    | Displays list of directories searched for executables     |

H) FILE PERMISSIONS

| Command                     | Description                                          |
| --------------------------- | ---------------------------------------------------- |
| `chmod ugoa+/-rwx filename` | Changes permission for user/group/others/all         |
| Example: `chmod ug+rw f1`   | Adds **read & write** permissions for user and group |
