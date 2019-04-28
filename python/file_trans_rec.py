import os

# file save location - works best with gui path picker
save_path = os.path.join(os.path.expanduser('~'),'Documents/LiFi/Recieved_files') 

# read any file
filer = open("test.pdf","rb")
base_path = os.path.basename(filer.name)
image = filer.read()

filew = open(os.path.join(save_path,base_path),"wb")
filew.write(image)
