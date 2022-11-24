from matplotlib import pyplot as plt
import numpy as np

f=open("Process_Scheduling_Data.txt","r")
# Creating dataset
P1=f.readline()
P2=f.readline()
P3=f.readline()


DATA={ "PROCESS-1":P1,
"PROCESS-2":P2,
"PROCESS-3":P3}
DAAT={"PRIORITY_A3":A3,
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
plt.bar(x,y,color="red",width=0.7)

plt.xlabel("PROCESS")
plt.ylabel("TIME TAKEN")
plt.title("For PROCESS: ")
plt.show()
  

# Creating histogram
# Show plot
plt.show()
