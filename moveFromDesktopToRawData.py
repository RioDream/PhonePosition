import os
import sys

if __name__ == "__main__":
    idx = int(sys.argv[1])
    srcDir = "/Users/riodream/Desktop/Documents/"
    dstDir = "/Users/riodream/workspace/PhonePosition/raw_data/%d/" %idx
    
    os.system("mkdir %s" %dstDir)
    files = os.listdir(srcDir)
    for fname in files:
        fpath = srcDir + fname
        os.system("mv %s %s" %(fpath,dstDir))

    os.system("rm -r %s" %srcDir)
    os.system("python script.py %d" %idx)

