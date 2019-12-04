using System;

namespace _1._6
{
    class Program
    {
        static void Main(string[] args)
        {
            while(true)
            {
                Console.Write("请输入上限N：");
                int N;
                N = int.Parse(Console.ReadLine());
                bool[] a = new bool[N + 1];
                for (int i = 2; i < N + 1; i++)
                    a[i] = true;
                for (int i = 2;i < N+1;i++)
                {
                    for (int j = 2*i;j < N+1;j += i)
                    {
                        a[j] = false;
                    }
                }
                for (int i = 2; i < N + 1; i++)
                    if (a[i])
                        Console.Write(i + " ");
                Console.WriteLine();
                string p = Console.ReadLine();
                if (p == "0")
                    break;
            }
        }
    }
}
