from tkinter import*
import tkinter.font as font
import random
root=Tk()
root.title("TIC TAC TOE")
e=Entry(root, width=80,borderwidth=10)
e.grid(row=0,column=0,columnspan=3,padx=20,pady=20)

myFont = font.Font(family='Helvetica', size=50, weight='bold')


b_1=Button(root,text="   ",font=myFont,padx=30,pady=20)
b_2=Button(root,text="   ",font=myFont,padx=30,pady=20)
b_3=Button(root,text="   ",font=myFont,padx=30,pady=20)
b_4=Button(root,text="   ",font=myFont,padx=30,pady=20)
b_5=Button(root,text="   ",font=myFont,padx=30,pady=20)
b_6=Button(root,text="   ",font=myFont,padx=30,pady=20)
b_7=Button(root,text="   ",font=myFont,padx=30,pady=20)
b_8=Button(root,text="   ",font=myFont,padx=30,pady=20)
b_9=Button(root,text="   ",font=myFont,padx=30,pady=20)

""" O ✕ """

t=[]
pos=['1','2','3','4','5','6','7','8','9']
b=[b_1,b_2,b_3,b_4,b_5,b_6,b_7,b_8,b_9]
mwin=0;cwin=0;draw=0
while(1):
    m=input("Choose your player: X or O\n")
    if(m=='X'): 
        c='O'
        break
    elif(m=='O'): 
        c='X'
        break
    else: 
        print("Select a valid choice")
def game_board(n,pl):
    for i in range(3):
        for j in range(3):
            if(t[i][j]==n): t[i][j]=pl;break
    b[int(n)-1]['text']=pl
    b_1.grid(row=1,column=0)
    b_2.grid(row=1,column=1)
    b_3.grid(row=1,column=2)
    b_4.grid(row=2,column=0)
    b_5.grid(row=2,column=1)
    b_6.grid(row=2,column=2)
    b_7.grid(row=3,column=0)
    b_8.grid(row=3,column=1)
    b_9.grid(row=3,column=2)
    
def game_executer():
    game=0
    for k in range(3):
        if((t[k][0]==t[k][1] and t[k][1]==t[k][2]) or
           (t[0][k]==t[1][k] and t[1][k]==t[2][k])):
            game=1
            break
    if(game==0):
        if((t[0][0]==t[1][1] and t[1][1]==t[2][2]) or 
           (t[0][2]==t[1][1] and t[1][1]==t[2][0])):
            game=1
    if(game==0):
        game=-1
        for i in t:
            for j in i:
                if j in pos:
                    game=0
                    break
    return game
def computer_turn():
    turn=0
    """searching winning scope"""
    for k in range(3):
        hor=sorted(t[k])
        ver=sorted([t[0][k],t[1][k],t[2][k]])
        if(hor[0] in pos and hor[1]==c and hor[2]==c):
            turn=hor[0]
            break
        if(ver[0] in pos and ver[1]==c and ver[2]==c):
            turn=ver[0]
            break
    if(turn==0):
        d1=sorted([t[0][0],t[1][1],t[2][2]])
        d2=sorted([t[0][2],t[1][1],t[2][0]])
        if(d1[0] in pos and d1[1]==c and d1[2]==c):
            turn=d1[0]
        elif(d2[0] in pos and d2[1]==c and d2[2]==c):
            turn=d2[0]
    """defensive"""
    if(turn==0):
        for k in range(3):
            hor=sorted(t[k])
            ver=sorted([t[0][k],t[1][k],t[2][k]])
            if(hor[0] in pos and hor[1]==m and hor[2]==m):
                turn=hor[0]
                break
            if(ver[0] in pos and ver[1]==m and ver[2]==m):
                turn=ver[0]
                break
        if(turn==0):
            d1=sorted([t[0][0],t[1][1],t[2][2]])
            d2=sorted([t[0][2],t[1][1],t[2][0]])
            if(d1[0] in pos and d1[1]==m and d1[2]==m):
                turn=d1[0]
            elif(d2[0] in pos and d2[1]==m and d2[2]==m):
                turn=d2[0]
    """offensive"""
    if(turn==0):
        for k in range(3):
            hor=sorted(t[k])
            ver=sorted([t[0][k],t[1][k],t[2][k]])
            if(hor[0] in pos and hor[1] in pos and hor[2]==m):
                turn=random.choice([hor[0],hor[1]])
                break
            if(ver[0] in pos and ver[1] in pos and ver[2]==m):
                turn=random.choice([ver[0],ver[1]])
                break
        if(turn==0):
            d1=sorted([t[0][0],t[1][1],t[2][2]])
            d2=sorted([t[0][2],t[1][1],t[2][0]])
            if(d1[0] in pos and d1[1] in pos and d1[2]==m):
                turn=random.choice([d1[0],d1[1]])
            elif(d2[0] in pos and d2[1] in pos and d2[2]==m):
                turn=random.choice([d2[0],d2[1]])
    """random"""
    if(turn==0):
        while(1):
            i=random.randint(0,2)
            j=random.randint(0,2)
            if t[i][j] in pos:
                turn=t[i][j]
                break
    return turn
while(1):
    t=[['1','2','3'],['4','5','6'],['7','8','9']]
    game_board(0,0)
    while(1):
        mturn=input("\n\n\nYour turn. Enter position:- ")
        game_board(mturn,m)
        root.mainloop()
        if(game_executer()==1):
            print("You Won!!!")
            mwin+=1
            break
        elif(game_executer()==-1):
            print("Game Drawn")
            draw+=1
            break
        cturn=computer_turn()
        game_board(cturn,c)
        root.mainloop()
        if(game_executer()==1):
            print("Computer Won.")
            cwin+=1
            break
    print("You:> %d\t\tComputer:> %d\t\tDrawn:> %d"%(mwin,cwin,draw))
    yn=input("Do you want to play again?: if yes press y, else press any key\n")
    if(yn!='y'):
        break


  


    


    

