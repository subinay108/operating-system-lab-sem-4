# WAP in Shell Script to swap values in two variables

echo -n "Enter value of X: "
read x
echo -n "Enter value of Y: "
read y
echo "Before swap, X = $x and Y = $y"
temp=$x
x=$y
y=$temp
echo "After swap, X = $x and Y = $y"