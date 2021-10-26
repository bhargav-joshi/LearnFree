# Currency Converted using Python
# Author: Rohan Raj

from forex_python.converter import CurrencyRates
from tkinter import *
import tkinter.messagebox
from PIL import ImageTk, Image

root = Tk() 

root.title("Currency Converter")
 
root.geometry("500x500") 

 
ip1 = StringVar(root) 
ip2 = StringVar(root) 
 
ip1.set("Select") 
ip2.set("Select") 

def RealTimeCurrencyConversion(): 
    
    c=CurrencyRates()
    
    from_currency = ip1.get() 
    to_currency = ip2.get()
    
    if (value.get()==""):
        tkinter.messagebox.showerror("Error","Amount Not Entered.\n Please a valid amount.")
        
    elif (from_currency=="Select" or to_currency=="Select"):
        tkinter.messagebox.showerror("Error","Currency Not Selected.\n Please select the currencies to be converted")
        
    else:
        new_amt = c.convert(from_currency,to_currency,float(value.get()))
        new_amount = float("{:.4f}".format(new_amt))
        output.insert(0, str(new_amount)) 

def clear():
    value.delete(0, END)
    output.delete(0, END)

    
    ip1.set("Select")
    ip2.set("Select")

        
CurrencyCode_list = ["INR", "USD", "CAD", "CNY", "DKK", "EUR", "GBP", "IDR", "JPY", "BGN", "ILS", "HUF", "RON", "MYR", "SEK", "SGD", "HKD", "AUD", "CHF", "KRW", "CNY","TRY", "HRK", "NZD", "THB", "NOK", "RUB", "MXN", "CZK", "BRL", "PLN", "PHP", "ZAR"]

label1 = Label(root,font=('Helvetica', 15,'bold'), text = "Amount : ",fg = "black") 
label1.place(x=20, y=30)

label2 = Label(root,font=('Helvetica', 15,'bold'), text = "From : ",fg = "black") 
label2.place(x=20, y=120)

label3 = Label(root,font=('Helvetica', 15,'bold'), text = "To : ",fg = "black") 
label3.place(x=20, y=170)

label4 = Label(root,font=('Helvetica', 15,'bold'), text = "Converted Amount : ",fg = "black") 
label4.place(x=20, y=300)

# * is used for unpacking the container as list type here.
FromCurrency_option = OptionMenu(root, ip1, *CurrencyCode_list) 
ToCurrency_option = OptionMenu(root, ip2, *CurrencyCode_list) 

FromCurrency_option.place(x=100, y=120) 
ToCurrency_option.place(x=100, y=170) 

value = Entry(root) 
value.place(x=150, y=35)

output = Entry(root)
output.place(x=250, y=305) 

convert =Button(root, font=('arial', 15,'bold'), text="Convert",padx=2,pady=2, bg="blue",fg = "white",command=RealTimeCurrencyConversion)
convert.place(x=200, y=220)

reset =Button(root, font=('arial', 15,'bold'), text="Reset",padx=2,pady=2, bg="white",fg = "blue",command=clear)
reset.place(x=208, y=400)

root.mainloop()
