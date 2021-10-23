import json           # imported json module or file 
from difflib import get_close_matches     # imported get_close_matches function from difflib--> which matches the accuracy of two words
data = json.load(open("data.json"))         # reading data from json file

def translate(w):      # defined function
    w = w.lower()       # used lower() method for the input of user
    if w in data:
        return data[w]    # returning wordfrom the json module
    elif w.title() in data:
        return(data[w.title()])
    elif w.upper() in data:
        return(data[w.upper()])
    elif len(get_close_matches(w, data.keys())) > 0:
        yn = input(f"Did you mean {get_close_matches(w, data.keys())[0]} instead? Enter Y if Yes, or N if No: " )
        if yn == "Y":
            return data[get_close_matches(w, data.keys())[0]]
        elif yn =="N":
            return "The word doesn't exist. Please check again!"
        else:
            return "We didn't understand your query"
    else:
        return "This word doesn't exist.Please check again!"

word = input("Enter a word: ")
result = translate(word)
if type(result) == list:
    for item in result:
        print(result) 
else:
    print(result,end=" ")