import random

class UniqueId():
    def __init__(self):
        # lower case alphabets 1
        self.lower_alphabets = []
        for i in range(97, 123):
            self.lower_alphabets.append(i)
        self.lower_alphabets = tuple(self.lower_alphabets)

        # upper case alphabets 2
        self.upper_alphabets = []
        for i in range(65, 91):
            self.upper_alphabets.append(i)
        self.upper_alphabets = tuple(self.upper_alphabets)

        # alphabets 3
        self.alphabets = tuple(self.lower_alphabets + self.upper_alphabets)

        # numbers 4
        self.numbers = []
        for i in range(48, 58):
            self.numbers.append(i)
        self.numbers = tuple(self.numbers)

        # symbols 5
        self.symbols = (33, 35, 36, 37, 38, 43, 45, 61, 63, 64, 95)

        # brackets 6
        self.brackets = (40, 41, 91, 93, 123, 125)

        # hexadecimal
        self.hexadecimal = tuple(self.lower_alphabets + self.numbers)

        # alphanumeric
        self.alphanumeric = tuple(self.alphabets + self.numbers)

        # alphanumeric with symbols
        self.alphanumericsymbols = tuple(self.alphanumeric + self.symbols)

        # checking containment
        self.hasLowerAlphabet = False
        self.hasUpperAlphabet = False
        self.hasAlphabet = False
        self.hasNumber = False
        self.isAlphaNumeric = False
        self.hasSymbol = False
        self.isAlphaNumericWithSymbols = False
        self.hasBracket = False
        self.isPassword = False


    def generate_UUID(self):
        # UUID(8-4-4-4-12) -> xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx
        self.uuid = ""
        for i in range(8):
            self.uuid += chr(random.choice(self.hexadecimal))
        self.uuid += "-"
        for _ in range(3):
            for i in range(4):
                self.uuid += chr(random.choice(self.hexadecimal))
            self.uuid += "-"
        for i in range(12):
            self.uuid += chr(random.choice(self.hexadecimal))
        return self.uuid


    def generate_password(self, length = 8):
        # alphanumeric with symbols password
        self.password = ""
        for i in range(length):
            self.password += chr(random.choice(self.alphanumericsymbols))
        self.check_id(self.password)
        if not self.isPassword:  
            self.password = self.generate_password(length)
        return self.password


    def generate_alphanumeric(self, length = 8):
        self.password = ""
        for i in range(length):
            self.password += chr(random.choice(self.alphanumeric))
        self.check_id(self.password)
        if not self.isAlphaNumeric:
            self.password = self.generate_alphanumeric(length)
        return self.password


    def generate_numeric(self, length = 8):
        self.num = ""
        for i in range(length):
            self.num += chr(random.choice(self.numbers))
        self.check_id(self.num)
        return self.num
    

    def generate_alphabetical(self, length = 8):
        self.seq = ""
        for i in range(length):
            self.seq += chr(random.choice(self.alphabets))
        self.check_id(self.seq)
        return self.seq

    
    def check_id(self, id):
        self.hasLowerAlphabet = False
        self.hasUpperAlphabet = False
        self.hasAlphabet = False
        self.hasNumber = False
        self.isAlphaNumeric = False
        self.hasSymbol = False
        self.isAlphaNumericWithSymbols = False
        self.hasBracket = False
        self.isPassword = False

        for i in id:
            i = ord(i)
            if not self.hasLowerAlphabet:
                if i in self.lower_alphabets:
                    self.hasLowerAlphabet = True
            if not self.hasUpperAlphabet:
                if i in self.upper_alphabets:
                    self.hasUpperAlphabet = True
            if not self.hasAlphabet:
                if i in self.alphabets:
                    self.hasAlphabet = True
            if not self.hasNumber:
                if i in self.numbers:
                    self.hasNumber = True
            if not self.hasSymbol:
                if i in self.symbols:
                    self.hasSymbol = True
            if not self.hasBracket:
                if i in self.brackets:
                    self.hasBracket = True
        if self.hasAlphabet and self.hasNumber:
            self.isAlphaNumeric = True
        if self.isAlphaNumeric and self.hasSymbol:
            self.isAlphaNumericWithSymbols = True
        if self.isAlphaNumericWithSymbols and self.hasLowerAlphabet and self.hasUpperAlphabet:
            self.isPassword = True
            

def get_input(start, end, msg = "Input: "):
    inp = input(msg)
    try:
        inp = int(inp)
    except ValueError:
        print("Invalid input, try again! \n")
        inp = get_input(start, end, msg)
    else:
        if start <= inp <= end:
            return inp
        else:
            print(f"Can't be less than {start} and more than {end}! \n")
            inp = get_input(start, end, msg)


def generate_and_check(l, choice, required):
    output = ""
    success = 0
    while success < l and success < len(choice):
        for i in range(l):
            output += chr(random.choice(required))
        uniqueId.check_id(output)
        if 1 in choice:
            if uniqueId.hasLowerAlphabet:
                success += 1
        if 2 in choice:
            if uniqueId.hasUpperAlphabet:
                success += 1
        if 3 in choice:
            if uniqueId.hasAlphabet:
                success += 1
        if 4 in choice:
            if uniqueId.hasNumber:
                success += 1
        if 5 in choice:
            if uniqueId.hasSymbol:
                success += 1
        if 6 in choice:
            if uniqueId.hasBracket:
                success += 1
    return output




def advanced_mode():
    print("""
For variable lengths:
1. Manually choose
2. Generate Password with alphabets, numbers, symbols
3. Generate Alphabetical ID
4. Generate Alphanumeric ID
5. Generate Numeric ID
""")
    inp = get_input(1, 5)
    l = get_input(1, 1000, "Length of ID: ")
    if inp == 2:
        output =  uniqueId.generate_password(l)
    elif inp == 3:
        output = uniqueId.generate_alphabetical(l)
    elif inp == 4:
        output = uniqueId.generate_alphanumeric(l)
    elif inp == 5:
        output = uniqueId.generate_numeric(l)
    elif inp == 1:
        print("""
What all do you want in the ID?
Enter with spaces, like 2 3 4
1. Lower case alphabets
2. Upper case alphabets
3. Alphabets(output with either lower or upper or both)
4. Numbers
5. Symbols
6. Brackets""")
        choice = input("Choices: ")
        choice = choice.split()
        choice = [int(i) for i in choice]
        required = []
        if (3 in choice) or (2 in choice and 1 in choice):
            required += uniqueId.alphabets
        elif 2 in choice:
            required += uniqueId.upper_alphabets
        elif 1 in choice:
            required += uniqueId.lower_alphabets
        if 4 in choice:
            required += uniqueId.numbers
        if 5 in choice:
            required += uniqueId.symbols
        if 6 in choice:
            required += uniqueId.brackets
        choice = [i for i in choice if 1 <= i <= 6]
        choice = list(set(choice))
        output = generate_and_check(l, choice, required)
    print("\nOutput: ", output)
            

uniqueId = UniqueId()

while True:
    print("""
Note:- By default, UUID is of 32 characters and others will be generated of 8 characters. 
For better tweaking, use advanced mode!:\n
1. Advanced Mode
2. Generate UUID
3. Generate Password with alphabets, numbers, symbols
4. Generate Alphabetical ID
5. Generate Alphanumeric ID
6. Generate Numeric ID
""")
    inp = get_input(1, 6)
    if inp == 1:
        advanced_mode()
    elif inp == 2:
        print("\nOutput: ", uniqueId.generate_UUID())
    elif inp == 3:
        print("\nOutput: ", uniqueId.generate_password())
    elif inp == 4:
        print("\nOutput: ", uniqueId.generate_alphabetical())
    elif inp == 5:
        print("\nOutput: ", uniqueId.generate_alphanumeric())
    elif inp == 6:
        print("\nOutput: ", uniqueId.generate_numeric())
    
