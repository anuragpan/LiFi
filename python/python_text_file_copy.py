f=open('list1.txt')  
f1=open('output.txt','a')
for x in f.readlines():
    f1.write(x)
f.close()
f1.close()