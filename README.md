#Phone Position

##intro 
This a Matlab code which try to get the attitude and position of the phone. There are two versions here. 

* simu_trj.m uses the attitude and accleration API of windows phone
* simu_trj\_ahrs.m uses the AHRS algorithm and gravity instead

##results

it seems that the attitude API and the AHRS algorithm can produce similar attitude infomation. But when I use gravity instead of accleration API， the result go worse. It seems that the API is more reliable.


##references

[AHRS（航姿参考系统）和IMU（惯性测量单元）的区别](http://bbs.ednchina.com/BLOG_ARTICLE_1616967.HTM)

[CHR-6dm datasheet 中文翻译](http://www.cnblogs.com/yxy8023ustc/archive/2012/11/22/2782932.html)

[Oscillatory Motion Tracking With x-IMU](http://www.x-io.co.uk/oscillatory-motion-tracking-with-x-imu/)

[Gait tracking with x-IMU](http://www.x-io.co.uk/gait-tracking-with-x-imu/)

[Rotating device acceleration to horizontal ref frame](http://social.msdn.microsoft.com/forums/wpapps/zh-cn/ad12a6b7-cbac-4304-a133-b65c5140cb8a/rotating-device-acceleration-to-horizontal-ref-frame?forum=wpdevelop)



