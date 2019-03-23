import os

# file save location - works best with gui path picker
save_path = os.path.join(os.path.expanduser('~'),'Documents/lifi/recieved_files') 

# read any file
pathname = raw_input("file path: ") # works best with gui file picker
filer = open(pathname,"rb")
base_path = os.path.basename(filer.name)
image = filer.read()

filew = open(os.path.join(save_path,base_path),"wb")
filew.write(image)