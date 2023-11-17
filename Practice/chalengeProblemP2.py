gradeN = int(input())
grade = 'F'
if(gradeN == 5):
    grade = 'A'
elif(gradeN == 4):
    grade = 'B'
elif(gradeN == 3):
    grade = 'C'
elif(gradeN == 2):
    grade = 'D'
else:
    grade = 'F'

print(grade)