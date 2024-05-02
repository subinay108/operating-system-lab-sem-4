# Write shell script to check a number is prime or not

echo -n "Enter a number: "
read n

if [ $n -lt 2 ]
then
echo "$n is not a prime number"
read m
exit 0
fi

for (( i=2; i<=$n/2; i++ ))
do
    ans=$(( n%i ))
    if [ $ans -eq 0 ]
    then
        echo "$n is not a prime number"
        read m
        exit 0
    fi
done
echo "$n is a prime number"
read m