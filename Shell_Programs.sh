Shell Programs
Procedure
How to Run a Shell Script

Edit and save your program using any text editor (e.g., vi, nano, or Notepad++ if using WSL).

Add execute permission using the chmod command:

chmod +x program-name.sh


Run the program using:

./program-name.sh

Important Hints

No spaces before or after the assignment operator
Example:

sum=0


Quotes meaning:

'single quotes' → ignore all special characters

"double quotes" → interpret $, `, and \

`back quotes` → used for command substitution

\backslash → removes special meaning of a character

Arithmetic operations can be written as:

i=$((i + 1))
# or
i=$(expr $i + 1)


Command line arguments inside program:

$1, $2, ... → first, second arguments

$# → number of arguments

$* → all arguments

Read input from user:

read a b

1. Conditional Statements (if, elif, else)
Syntax – 1: Simple if
if [ condition ]
then
   # commands to execute if condition is true
fi


Example:

if [ $age -ge 18 ]
then
   echo "You are eligible to vote."
fi

Syntax – 2: if-else
if [ condition ]
then
   # commands if condition is true
else
   # commands if condition is false
fi


Example:

if [ $num -eq 0 ]
then
   echo "Zero"
else
   echo "Non-zero"
fi

Syntax – 3: if-elif-else
if [ condition1 ]
then
   # commands for condition1
elif [ condition2 ]
then
   # commands for condition2
else
   # commands if no conditions are true
fi


Example:

if [ $marks -ge 90 ]
then
   echo "Grade A"
elif [ $marks -ge 75 ]
then
   echo "Grade B"
else
   echo "Grade C"
fi

2. Case Structure
Syntax:
case expression in
pattern1)
   # commands to execute if expression matches pattern1
   ;;
pattern2)
   # commands to execute if expression matches pattern2
   ;;
*)
   # default commands (if no pattern matches)
   ;;
esac


Example:

echo "Enter a number between 1 and 3:"
read num

case $num in
1)
   echo "You selected One"
   ;;
2)
   echo "You selected Two"
   ;;
3)
   echo "You selected Three"
   ;;
*)
   echo "Invalid choice"
   ;;
esac

3. Looping Structures
For Loop

Syntax:

for var in value1 value2 value3
do
   # commands using $var
done


Example:

for color in red green blue
do
   echo "Color is $color"
done

While Loop

Syntax:

while [ condition ]
do
   # commands to execute while condition is true
done


Example:

count=1
while [ $count -le 5 ]
do
   echo "Count is $count"
   count=$((count + 1))
done

4. Printf Statement

Syntax:

printf "format-string" [arguments...]


Example:

printf "Name: %s\nAge: %d\n" "Vikaasni" 19

5. Control and Comparison Operators
Break and Continue

Work the same as in C language

Used to control loop execution

Relational Operators
| Operator | Meaning               | Example         |
| -------- | --------------------- | --------------- |
| `-lt`    | Less than             | `[ $a -lt $b ]` |
| `-le`    | Less than or equal    | `[ $a -le $b ]` |
| `-gt`    | Greater than          | `[ $a -gt $b ]` |
| `-ge`    | Greater than or equal | `[ $a -ge 10 ]` |
| `-eq`    | Equal to              | `[ $a -eq $b ]` |
| `-ne`    | Not equal to          | `[ $a -ne $b ]` |

Logical Operators
| Operator | Meaning | Example                      |
| -------- | ------- | ---------------------------- |
| `-a`     | AND     | `[ $a -gt $b -a $a -gt $c ]` |
| `-o`     | OR      | `[ $a -eq 10 -o $b -eq 20 ]` |
| `!`      | NOT     | `[ ! $a -eq $b ]`            |

String Comparison
| Operator | Meaning               | Example              |
| -------- | --------------------- | -------------------- |
| `=`      | Strings are equal     | `[ $str1 = $str2 ]`  |
| `!=`     | Strings are not equal | `[ $str1 != $str2 ]` |

Result:

The shell programs were successfully executed in the Linux environment, demonstrating the use of conditional, looping, case, and I/O statements.