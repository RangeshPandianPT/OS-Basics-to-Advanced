Filters and Admin Commands:
Procedure:

A. FILTERS
1. cut

Used to cut characters or fields from a file or input.

Syntax:

cut -c<chars> filename
cut -f<fieldnos> filename

Examples:

cut -c 5 file.txt            → cuts the 5th character from each line  
cut -c 5-10 file.txt         → cuts characters from 5th to 10th  
cut -c 5,7,9 file.txt        → cuts characters at positions 5, 7, and 9

Example:

cut -d',' -f2 students.csv

2. grep

Used to search one or more files for a specific pattern.

Syntax:

grep pattern filename(s)


Description:

Displays all lines containing the pattern.
Supports regular expressions.
Can search multiple files at once.

| Option | Description                                        |
| ------ | -------------------------------------------------- |
| `-v`   | Displays lines that **do not** contain the pattern |
| `-l`   | Lists **only filenames** containing the pattern    |
| `-n`   | Displays **line numbers** along with matched lines |

Examples:
grep "SRM" students.txt
grep -n "error" logfile.txt
grep -v "pass" result.txt

3. sort

Used to sort lines of text files in a particular order.

Syntax:

sort filename

Description:
Sorts text data by default (alphabetically).
Sorts by the first field unless specified.

Options:
| Option        | Description                                          |
| ------------- | ---------------------------------------------------- |
| `-r`          | Sorts in **descending** order                        |
| `-u`          | Removes **duplicate** lines                          |
| `-o filename` | Saves sorted data into another file                  |
| `-t dchar`    | Specifies a **delimiter** character                  |
| `-n`          | Sorts numerically                                    |
| `+1n`         | Skips first field, sorts by second field numerically |

Examples:

sort names.txt
sort -r marks.txt
sort -u city.txt
sort -t"," -k2,2n students.csv

4. uniq

Used to display unique lines from a sorted file.

Syntax:

uniq filename


Options:
| Option | Description                                      |
| ------ | ------------------------------------------------ |
| `-d`   | Displays only **duplicate** lines                |
| `-c`   | Displays **unique lines** along with their count |

Examples:

sort names.txt | uniq
sort names.txt | uniq -d
sort names.txt | uniq -c

5. diff

Used to compare two files and show the differences.

Syntax:

diff f1 f2

Description:

Compares files f1 and f2 line by line.
Displays the lines that differ between the two.

Example:
diff old_version.txt new_version.txt

B. ADMIN COMMANDS

1. who
Displays information about users currently logged in.

Syntax:

who

Example:
who

2. whoami
Displays the current logged-in user name.

Syntax:
whoami

3. ps
Displays information about active processes.

Syntax:

ps

Example:
ps -ef     → shows all processes with full details

4. top
Displays real-time information about CPU, memory, and running processes.

Syntax:

top


5. kill

Used to terminate a running process.

Syntax:

kill <process_id>


Example:
kill 1234


6. df

Displays disk space usage for mounted filesystems.

Syntax:

df


Example:
df -h     → human-readable format


7. du

Displays disk usage of files and directories.

Syntax:
du


Example:
du -sh *  → shows size of all files/directories in readable form

8. uptime

Displays how long the system has been running.

Syntax:
uptime

9. uname

Displays system information.

Syntax:
uname -a

10. shutdown / reboot
Used to shutdown or restart the system.

Syntax:

shutdown -h now     → shutdown immediately
reboot              → restart the system
