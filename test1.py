# -*- coding: utf-8 -*-
"""
Created on Wed Jun  7 18:06:33 2017

@author: www
"""

from ctypes import CDLL,c_char_p
import matplotlib.pyplot as plt
from tkinter import *


#ll = ctypes.cdll.LoadLibrary 
#lib = ll("libsize.so")
lib = CDLL("libsize.so")
charP = c_char_p(b'sdafsadfsadf')
lib.test(charP)
pa=charP.value
pa=pa.decode('utf-8')
print("hah")

a=str(pa)
print (len(pa))
print (type(pa))
print(a)




#k="120 1,1 1,2 1,3 2,3 2,2 2,1 1,1\n134 1,1 1,2 1,3 2,3 3,3 3,2 2,2 2,1 1,1"
k=str(pa)
a=k.split('\n')
color=['red','yellow','red','yellow','red','yellow','red','yellow','red']
for i in a[0:-1]:
    xck=Tk()
    k=i
    y=k.split(" ",1)
    z=y[1]
    b=z.split(" ")
    x=[]
    y=[]
    for i in b[0:-1]:
        c=i.split(",")
        x.append(c[0])
        y.append(c[1])
        Label(xck,bg='red').grid(row=int(c[0])-1,column=(int(c[1])-1)*5)
        
    xck.mainloop()    
'''        
    x1=[int(i) for i in x]
    y1=[int(i) for i in y]
    y2=[]
    x2=[]
    for i in x1:
        b=-i
        x2.append(b)
    for i in y1:
        a=-i
        y2.append(a)
    print (x1)
    print (y1)
    plt.xlim([0,5])
    plt.ylim([-5,0])
    plt.plot(y1,x2,'ko--')
    plt.show()
'''  
