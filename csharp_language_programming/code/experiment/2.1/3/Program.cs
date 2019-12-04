using System;

namespace _3
{
    class Program
    {
        class MeanTool
        {
            public static double Mean(double a, double b, double c)
            {
                return (a + b + c) / 3;
            }

            public static void Mean(ref double a, ref double b, ref double c)
            {
                a = Math.Pow(a * b * c, 1.0 / 3);
                b = Math.Sqrt(1.0 * (a * a + b * b + c * c) / 3);
                Console.WriteLine($"The geometric mean value is: {a}");
                Console.WriteLine($"The square mean value is: {b}");
            }

            public static void Mean(double a, double b, double c, out double x, out double y)
            {
                x = Math.Pow(a * b * c, 1.0 / 3);
                y = Math.Sqrt(1.0 * (a * a + b * b + c * c) / 3);
                Console.WriteLine($"The geometric mean value is: {x}");
                Console.WriteLine($"The square mean value is: {y}");
            }

            public static void Mean(out double x, out double y, double n, double[] a)
            {
                double sum = 1.0;
                double ant = 0;
                foreach (double i in a)
                {
                    sum *= i;
                    ant += i * i; 
                }
                x = Math.Pow(1.0 * sum, 1.0 / n);
                y = Math.Sqrt(1.0 * ant / n);
                Console.WriteLine($"The geometric mean value is: {x}");
                Console.WriteLine($"The square mean value is: {y}");
            }
        }
        public static void Main()
        {
            double value1 = 2.0, value2 = 3.0, value3 = 4.0;
            double x, y;
            double result1 = 0.0, result2 = 0.0;
            double[] num = { 2.0, 3.0, 4.0 };
            Console.WriteLine("函数1：{0}", MeanTool.Mean(value1, value2, value3));
            MeanTool.Mean(value1, value2, value3);
            Console.WriteLine("函数2：{0}, {1}", value1, value2);
            MeanTool.Mean(value1, value2, value3, out result1, out result2);
            Console.WriteLine("函数3：{0}, {1}", result1, result2);
            MeanTool.Mean(out result1, out result2, 3.0, num);
            Console.WriteLine("函数4：{0}, {1}", result1, result2);
            Console.ReadKey();
        }
    }
}
