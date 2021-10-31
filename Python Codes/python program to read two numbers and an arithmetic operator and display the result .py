num1 = float(input("Enter first number :"))
num2 = float(input("Enter second number :"))
oper = input("Enter operator [+,-,*,/]:")
result = 0
if oper == '+':
  result = num1 + num2
elif oper == '-':
  result = num1 - num2
elif oper == '*':
  result = num1 * num2
elif oper == '/':
  result = num1 / num2  
else:
  print("invalid operator")
print("the required result between two nunber is :",result) 
