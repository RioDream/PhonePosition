#!/usr/bin/python
#coding=UTF-8

import os
import sys

if __name__=="__main__":
    idx = int(sys.argv[1])
    #os.system("./PatternAR_desktop ./Pattern.bmp ./raw_data/%d/ ./data/%d/" %(idx, idx))

    os.system("cp ./raw_data/%d/sensor_linacc.txt ./data/%d/" %(idx, idx))
    os.system("cp ./raw_data/%d/sensor_attitude.txt ./data/%d/" %(idx, idx))
    os.system("cp ./raw_data/%d/img2time.txt ./data/%d/" %(idx, idx))


