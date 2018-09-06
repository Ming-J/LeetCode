import os
import sys

def getfile(path):
    for filename in os.listdir(path):
        if os.path.isdir(path+"/"+filename):
            getfile(path+"/"+filename)
        else:
            if (filename.endswith("~")
                or filename.endswith(".exe")
                or filename.endswith(".out")
                or filename.endswith(".stackdump")):
                print(filename)
                os.remove(path+"/"+filename)

getfile(os.getcwd())
