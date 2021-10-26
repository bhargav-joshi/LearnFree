import random

r = 'ROCK'
p = 'PAPER'
s = 'SCISSOR'
inputs = [r, p, s]
usr_points = 0
com_points = 0
quit = False
print('''
Get ready to play the famous game of Rock, Paper, Scissor
''')
winning = [[r, s],
           [s, p],
           [p, r],     #playerwin
           [s, r],
           [p, s],
           [r, p]]    #computer win


def get_input_index(cmbnd_inp):
    if cmbnd_inp in winning:
        ind = winning.index(cmbnd_inp)
    else:
        ind = -1
    return ind


def get_usr_input():
    user_input = check_usr_input(input('Rock or Paper or Scissor: ').upper())
    return user_input


def check_usr_input(raw_user_input):
    try:
        if raw_user_input[0] == 'R':
            raw_user_input = r
        elif raw_user_input[0] == 'P':
            raw_user_input = p
        elif raw_user_input[0] == 'S':
            raw_user_input = s
        else:
            print('Invalid input')
            print(' ')
            raw_user_input = get_usr_input()
    except IndexError:
        print('Invalid input')
        print(' ')
        raw_user_input = get_usr_input()
    return raw_user_input


def wanna_quit():
    q = input('Would you like to play again?(y/n) ').lower()

    if q == 'y':
        qt = False
    elif q == 'n':
        qt = True
    else:
        print('Invalid Input')
        qt = wanna_quit()
    return qt


while not quit:
    usr_input = get_usr_input()
    computer_input = inputs[random.randint(0, 2)]
    print(f'Computer: {computer_input}')
    combined_input = [usr_input, computer_input]
    index = get_input_index(combined_input)

    if 0 <= index <= 2:
        usr_points += 1
    elif 3 <= index <= 5:
        com_points += 1
    else:
        pass
    print(f'''
Your points: {usr_points}     Computer points: {com_points}
''')

    if usr_points == 10 or com_points == 10:
        if usr_points == 10:
            print('Hurray, You Won the game.')
        if com_points == 10:
            print('You lost from the computer')
        quit = wanna_quit()
        usr_points = 0
        com_points = 0
