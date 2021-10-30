r=int(input("Enter upper limit: ")) #takes upperlimit from the user.
for a in range(2,r+1):
    count=0              # count variable is initialized to zero.
    for i in range(2,a//2+1):  
        if(a%i==0):
            count = count + 1
    if(count<=0):        #if count <= 0 then the number is prime.
        print(a)     #prints prime number within a given range.
