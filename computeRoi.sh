#!/bin/bash

# Explanation on how to use the script
explanation="Please enter the source's values one after the other.
Date in the following format - yymmdd, activity in MBq and volume in ml as follows: 
computeRoi.sh 200516 94 10867"

if [ $# -eq 0 ]; then 
	# Default values of source
	activity=94
	volume=10867
	manufacture_date=$(date +%s -d 200516)
	printf "No values entered. \nUsing default values for computing ROI.\n\nManufacturing date is 16/05/2020\n"

elif [ $# -gt 0 ] && [ -z "$3" ]; then 
	# If not enough values entered for calculation 
	printf "Some values are missing for calculation of ROI.\n"
	echo $explanation
	exit

elif [ $# -gt 3 ]; then 
	# In case too many values are entered
	printf "Too many values have been entered.\n"
	echo $explanation
	exit
else
	# When all values are entered
	activity=$2
	volume=$3
fi


# Today's date in seconds
current_date=$(date +%s -d $(date "+%y%m%d"))

# Source manufacturing date in seconds
#manufacture_date=$(date +%s -d $1)

# Number of days between today and the source's manufacturing day
day_diff=$(( $(( current_date - manufacture_date )) / 86400 )) 

# The computed ROI 
computed_roi=$(echo "( e(-$day_diff / 390.7 ) * 1000 * $activity ) / $volume" | bc -l)

echo "Number of days between today and the source's manufacturing date = $day_diff days"
echo "The activity used = $activity MBq"
echo "The volume used = $volume ml"
printf "\nThe computed ROI is $computed_roi MBq\n"

