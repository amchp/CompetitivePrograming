hours = int(input())
hourlyRate = int(input())
totalWage = 0
if hours <= 40:
    totalWage = hours * hourlyRate
else:
    totalWage = hourlyRate*40 + (3/2)*(hours - 40)*hourlyRate
print(totalWage)