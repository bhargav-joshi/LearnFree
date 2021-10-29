line = input("enter line : ")
lowercount = uppercount = digitcount = alphacount = 0      #initializing all the count variables.
for a in line :      #traversing through the string.
  if a.islower() :
    lowercount+=1
  elif a.isupper(): 
    uppercount+=1
  elif a.isdigit():
    digitcount+=1
  if a.isalpha():
    alphacount+=1
print("Number of uppercase letters :", uppercount)
print("Number of lowercase letters :", lowercount)
print("Number of digits :", digitcount)
print("Number of alphabets :", alphacount) 


  

    
