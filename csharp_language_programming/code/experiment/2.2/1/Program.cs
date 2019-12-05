using System;

namespace _1
{
    class Program
    {
        struct point
        {
            public double x;
            public double y;
            public static readonly point orign = new point();

            public point (double a, double b)
            {
                x = a;
                y = b;
            }

            public override String ToString()
            {

                return string.Format($"Point(x: {x}, y:{y})");

            }
        }

        abstract class shape
        {
            public abstract double area();
            public abstract double perimeter();
            public abstract bool contains(double x, double y);
        }

        class rect : shape
        {
            private point topleft;
            private double width;
            private double height;

            public rect (point p, double w, double h)
            {
                topleft = p;
                width = w;
                height = h;
            }

            public override double area()
            {
                return 1.0 * width * height;
            }

            public override double perimeter()
            {
                return 2.0 * (width + height);
            }

            public override bool contains(double x, double y)
            {
                if (x > topleft.x && x < (topleft.x + width) && y > topleft.y && y < (topleft.y + height))
                    return true;
                else
                    return false;
            }

            public override String ToString()
            {
                return string.Format($"Rect[TopLeft: Point(x: {topleft.x}, y:{topleft.y}), Width:{width}, Height: {height}]");

            }
        }

        class circle : shape
        {
            private point center;
            private double radius;

            public circle(point p, double r)
            {
                this.center = p;
                this.radius = r;
            }

            public circle() : this(new point(0, 0), 1)
            {

            }

            public override double area()
            {
                return 3.14159 * radius * radius;
            }

            public override double perimeter()
            {
                return 3.14159 * 2.00 * radius;
            }

            public override bool contains(double x, double y)
            {
                if (radius * radius > (x - center.x) * (x - center.x) + (y - center.y) * (y - center.y))
                    return true;
                else
                    return false;
            }

            public override String ToString()
            {
                return string.Format($"Cirle[Center: Point(x: {center.x}, y:{center.y}), Radius: {radius}, Area: {area()}]");

            }
        }

        static void Main(string[] args)
        {
            point p1 = new point(1,1);
            point p2 = new point(0,0);
            rect rect1 = new rect(p1 , 5, 4);
            circle circle1 = new circle(p2, 5);
            circle circle2 = new circle();

            Console.WriteLine("p1 = " + p1.ToString());
            Console.WriteLine("p2 = " + p2.ToString());

            Console.WriteLine("rect1 = " + rect1.ToString());
            Console.WriteLine("rect1.area = " + rect1.area());
            Console.WriteLine("rect1.perimeter = " + rect1.perimeter());
            Console.WriteLine("contains = " + rect1.contains(2, 3));

            Console.WriteLine("circle1 = " + circle1.ToString());
            Console.WriteLine("circle1.area = " + circle1.area());
            Console.WriteLine("circle1.perimeter = " + circle1.perimeter());
            Console.WriteLine("contains = " + circle1.contains(3, 2));

            Console.WriteLine("circle2 = " + circle2.ToString());
            Console.WriteLine("circle2.area = " + circle2.area());
            Console.WriteLine("circle2.perimeter = " + circle2.perimeter());
            Console.WriteLine("contains = " + circle2.contains(0.5, 0.4));

            Console.ReadKey();
        }
    }
}
