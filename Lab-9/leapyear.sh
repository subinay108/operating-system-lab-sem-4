# Write a shell program to check a year is leap year or not

echo -n "Enter the year: "
read year
r=`expr $year % 100`

if [ $r -eq 0 ]
then 
r2=`expr $year % 400`
if [ $r2 -eq 0 ]
then
echo "$year is leap year"
else
echo "$year is not leap year"
fi
else
r3=`expr $year % 4`
if [ $r3 -eq 0 ]
then
echo "$year is leap year"
else 
echo "$year is not leap year"
fi
fi

read m