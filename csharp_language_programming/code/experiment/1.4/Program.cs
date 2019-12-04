using System;

namespace _1._4
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("请输入循环次数n：");
            int n; 
            n = int.Parse(Console.ReadLine());
            int t;
            for (int i = 1;i <= n;i++)
            {
                int a = i;
                t = 0;
                Console.WriteLine("当数为" + a + "时，结果如下：");
                while (a != 1)
                {
                    Console.Write(" " + a);
                    if (a % 2 == 1)
                        a = a * 3 + 1;
                    else
                        a = a / 2;
                    t++;
                }
                Console.WriteLine(" " + a);
                Console.WriteLine("进行了" + t + "次运算！");
            }
            Console.ReadKey();
        }
    }
}
