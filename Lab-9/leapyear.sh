# Write a shell program to check a year is leap year or not

echo "Enter the year: "
read year
r=`expr $year % 100`
if [ r -eq 0 ]
r2=`expr $year % 400`
if [ r2 -eq 0 ]
echo "$year is eap year"
else
