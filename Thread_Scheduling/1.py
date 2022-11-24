from matplotlib import pyplot as plt
import numpy as np

f=open("Thread_Scheduling_Data.txt","r")
# Creating dataset
D1=f.readline()
A1=f.readline()
A2=f.readline()
A3=f.readline()
A4=f.readline()
D2=f.readline()
B1=f.readline()
B2=f.readline()
B3=f.readline()
B4=f.readline()
D3=f.readline()
C1=f.readline()
C2=f.readline()
C3=f.readline()
C4=f.readline()

DATA={ "Default_1":D1,
"PRIORITY_A1":A1,
"PRIORITY_A2":A2,
"PRIORITY_A3":A3,
"PRIORITY_A4":A4,
"Default_2":D2,
"PRIORITY_B1":B1,
"PRIORITY_B2":B2,
"PRIORITY_B3":B3,
"PRIORITY_B4":B4,
"Default_3":D3,
"PRIORITY_C1":C1,
"PRIORITY_C2":C2,
"PRIORITY_C3":C3,
"PRIORITY_C4":C4,
}

x=list(DATA.keys())
y=list(DATA.values())

plot=plt.figure(figsize=(100,100))
plt.bar(x,y,color="black",width=0.7)

plt.xlabel("PRIORITIES")
plt.ylabel("TIME TAKEN")
plt.title("For Thread: ")
plt.show()
  

# Creating histogram
# Show plot
plt.show()
