#获取尺度因子

SKF data的获取

1. ipad获取
2. 使用imageRotate.py 旋转
3. 将 documents 中的txt 和 旋转之后的图像都拷贝到 raw_data
4. 删除 img2time.txt 中前几帧黑的，一般从6.jpg开始
5. 并行运行
    a. skf_offline
    b. AnaSensor.py 
        获得的 IMU.txt 第一行需要和 img2time.txt 中第一行的image时间一致，就是说删掉之前的

6. 将img2time.txt IMUdata.txt 拷贝到 skf_data 然后新建 summary.txt 文档
7. 找一个 attitude.txt 中和 img2time 和 IMUdata.txt 第一行最接近的时间，使用其 gravity


