滤波：为了在保留图像特征的情况下，尽可能减少噪声

内核：一组权重，决定了如何利用某一个点周围的像素点来计算新的像素点，核也被称为卷积矩阵，对一个区域的像素做调和或者卷积运算，通常基于核的滤波器被称为卷积滤波器。

![img](https://img2020.cnblogs.com/blog/1643788/202104/1643788-20210406220625539-626020956.gif)

#### 方框滤波

通过内核值相乘算出图像像素点得值

boxFilter函数-线性

void boxFilter(InputArray src, OutputArray dst,int ddepth, Size ksize, Point anchor=Point(-1, -1), bool normalize = true, int borderType = BORDER_DEFALT)

参数一：InputArray类型，一般是cv::Mat，且可以处理任何通道数的图片。但需要注意，待处理的图片深度应该为CV_8U、CV_16U、CV_16S、CV_32F、CV_64F中的一个。
参数二；OutputArray类型，输出的目标图像，需要和原图片有一样的尺寸和类型。
参数三：int类型，表示输出图像的深度，-1代表使用原图深度。
参数四：Size类型的ksize，内核的大小。一般用Size(w,h)来表示内核的大小，Size(3,3)就表示3x3的核大小。
参数五：Point类型，表示锚点（值被平滑的那个点）。注意：默认值Point(-1,-1)。如果点是负值，就表示取核的中心为锚点。
参数六：bool类型normalize，默认为true，表示内核是否被其区域归一化。
参数七：int类型的borderType，用于推断图像外部像素的某种边界模式，使用默认值BORDER_DEFULAT，一般无需使用。

#### 均值滤波

通过内核点算出像素平均值

Blur函数-线性

void blur( InputArray src, OutputArray dst,Size ksize, Point anchor = Point(-1,-1),int borderType = BORDER_DEFAULT )*;*

InputArray，输入图像 src。
OutputArray ，输出图像 dst。

Int 类型 ddepth，输出图像深度， -1 代表使用原图 src 深度。

Size类型 ksize，内核大小 ，一般用 Size(w,h)，w 为宽度， h 为深度。
Point 类型 anchor，被平滑的点，表示取 内核中心 ，默认值 Point(-1,-1)。
Int 类型 boderType，推断图像外部像素的某种边界模式。默认值 BORDER_DEFAULT 

#### 高斯滤波



GaussianBlur函数-线性

- 高斯滤波是指用高斯函数作为滤波函数的滤波操作；
- 高斯模糊就是高斯低通滤波

#### 中值滤波

medianBlur函数-非线性

#### 双边滤波

bilateralFilter函数-非线性