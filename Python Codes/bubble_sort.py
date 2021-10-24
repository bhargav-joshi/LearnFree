def countSwaps(a):
    count=0
    for x in range(len(a)):
        for y in range(len(a)-1):
            if(a[y]>a[y+1]):
                count=count+1
                temp=a[y]
                a[y]=a[y+1]
                a[y+1]=temp
    print("Array is sorted in "+str(count)+" swaps.")
    print("First Element: "+str(a[0]))
    print("Last Element: "+str(a[-1]))
