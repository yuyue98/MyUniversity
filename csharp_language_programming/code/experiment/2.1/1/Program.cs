using System;

namespace _1
{
    class Program
    {
        struct SomeVal { public Int32 x; }
        class SomeRef { public Int32 x; }

        static void Main(string[] args)
        {
            SomeVal v1; // 分配到     （堆/栈）
            //Console.WriteLine(v1.x); //能运行吗？      
            v1 = new SomeVal();
            Console.WriteLine(v1.x); //输出      
            v1.x = 5;
            Console.WriteLine(v1.x); //输出      

            SomeRef r1;
            //Console.WriteLine(r1.x); //能运行吗？        
            r1 = new SomeRef(); // 分配到     （堆/栈）
            Console.WriteLine(r1.x); //输出      
            r1.x = 5;
            Console.WriteLine(r1.x); //输出      

            SomeVal v2 = v1;
            SomeRef r2 = r1;
            v1.x = 9;
            r1.x = 8;
            Console.WriteLine(r1.x); //输出      
            Console.WriteLine(r2.x); //输出      
            Console.WriteLine(v1.x); //输出      
            Console.WriteLine(v2.x); //输出      
            Console.ReadKey();
        }
    }
}
