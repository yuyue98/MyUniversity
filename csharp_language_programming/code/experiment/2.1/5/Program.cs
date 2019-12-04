using System;

namespace _5
{
    class Program
    {
        //创建委托类型
        public delegate bool NumberPredicate(int number);

        static void Main(string[] args)
        {
            //生成20个随机整数（不超过100），放在数组numbers中并打印这些数
            int[] numbers = new int[20];
            Random rd = new Random();
            for (int i = 0; i < 20;i++)
            {
                numbers[i] = rd.Next(1, 100);
                Console.Write($"number[{i+1}] = ");
                Console.WriteLine(numbers[i]);
            }   

            //生成委托实例
            NumberPredicate evenPredicate1 = IsEven, evenPredicate2 = IsPrime;

            //利用委托变量，对任意值调用IsEven
            Console.WriteLine("通过委托变量调用IsEven方法: {0}", evenPredicate1(rd.Next(1, 100)));

            //选出偶数并输出
            Console.WriteLine("数组包含以下偶数：");
            FilterArray1(numbers, evenPredicate1);

            //利用委托变量，对任意值调用IsEven
            Console.WriteLine("通过委托变量调用IsPrime方法: {0}", evenPredicate2(rd.Next(1, 100)));

            //选出素数并输出
            Console.WriteLine("数组包含以下素数：");
            FilterArray2(numbers, evenPredicate2);

            Console.ReadKey();
        }

        //选择满足predicate的数组元素并打印出来
        private static void FilterArray1(int[] intArray, NumberPredicate predicate)
        {
            foreach (int i in intArray)
            {
                if (predicate(i))
                {
                    Console.Write(i);
                    Console.Write(' ');
                } 
            }
            Console.Write('\n');
        }

        //偶数判断函数
        private static bool IsEven(int number)
        {
            return (number % 2 == 0);
        }

        //选择满足predicate的数组元素并打印出来
        private static void FilterArray2(int[] intArray, NumberPredicate predicate)
        {
            foreach (int i in intArray)
            {
                if (predicate(i))
                {
                    Console.Write(i);
                    Console.Write(' ');
                }
            }
            Console.Write('\n');
        }

        //素数判断函数
        private static bool IsPrime(int number)
        {
            bool n = true;
            for (int i = 2;i < Math.Sqrt(number);i++)
            {
                if (number % i == 0)
                {
                    n = false;
                    break;
                }
            }
            return n;
        }
    }
}
