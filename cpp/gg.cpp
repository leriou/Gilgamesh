#include <iostream>  // 引入iostream(输入输出流), io的意思是输入和输出, stream是流的意思, 因为下面我们要用到 cout 和 cin 所以要引入这个头文件
using namespace std;  // 声明命名空间, 这样就可以使用该命名空间下的函数了,
                      // 如果不声明该命名空间,则需要通过 std:cout
                      // 来使用cout这个函数

const double PI = 3.1415926;  // 定义一个double类型的常量

double calculate_circle_perimeter(double r) {
    // 变量的作用域, 每一个{} 符号就定义了一块作用域,
    // 某个作用域的变量只在在该作用域起作用, 作用域可以嵌套
    // 作用域可以想上层扩展, 采用由近及远的原则
    // 例如 该函数最后使用了 PI 这个变量, 但是该变量未在函数中定义,
    // 那就去函数外边找, 最终找到 第6行有定义PI 的值,
    // 作用域最里面可以使用外面的变量, 外边的不能使用里面的变量

    int a_t = 78;  // a_t 这个变量在这个函数里面定义,由于函数内容被{}符号包裹
                   // 那就不能在main 或者calculate_circle_area 这个函数中使用

    if (true) {
        int bh = 89;  // 同样的if 后面有{} , 所以里面定义的bh 变量也不能在if 外面使用
    }

    // cout << bh << endl; // 会报错

    return 2 * PI * r;  // 我们可以在函数内部直接使用函数外的变量但是不能再
}

double calculate_circle_area(double r) { return PI * r * r; }

class Shape {
    protected:
    int width, height;

    public:
    Shape(int a = 0, int b = 0) {
        width  = a;
        height = b;
    }
    int area() {
        cout << "Parent class area :" << endl;
        return 0;
    }
};
class Rectangle : public Shape {
      public:
    Rectangle(int a = 0, int b = 0) : Shape(a, b) {}
    int area() {
        cout << "Rectangle class area :" << endl;
        return (width * height);
    }
};
class Triangle : public Shape {
      public:
    Triangle(int a = 0, int b = 0) : Shape(a, b) {}
    int area() {
        cout << "Triangle class area :" << endl;
        return (width * height / 2);
    }
};

int main() {
    // 基本类型
    int a_i          = 1;
    float a_f        = 3.14;
    double a_d       = 3.1415926;
    char a_name      = '6';  // 字符只能有一个, 必须用单引号
    bool is_beautify = true;
    string a_string = "我是一个字符串";  // 字符串可以有多个字符, 使用双引号, string并不是基本类型

    cout << a_string << std::endl;  // 如果文件最上面没有使用using namespace std; 如果使用std内部的方法需要用 :: 进行访问,例如 std:endl

    // 枚举类型
    enum color { red, green, blue };
    color page_color = blue;  // 给枚举类型赋值只能使用定义好的, 如果使用 yellow
                              // 给page_color赋值,就会报错
    cout << page_color << endl;

    for (int i = 0 ; i <= 5; i++)  
    	cout << i << endl;

    // 函数的形参实参
    int r = 8;
    int p = 9;
    cout << calculate_circle_area(p) << endl;
    return 0;
}