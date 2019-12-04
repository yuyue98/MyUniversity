using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace _2
{
    class Program
    {
        static void Main(string[] args)
        {
            Func<int> f1 = () => DateTime.Now.Year ;
            Console.WriteLine(f1());
            Func<int,double> f2 = x => Math.Sqrt(x);
            Console.WriteLine(f2(1));
            Func<int,int,double> f3 = (x,y) => Math.Sqrt(x * x + y * y);
            Console.WriteLine(f3(4, 5));
            Func<int,int,int,double> f4 = (x, y, z) => Math.Sqrt(x * y * z);
            Console.WriteLine(f4(4, 5, 6));
            Action<String> f5 = str => Console.WriteLine(str);
            f5("Hello World!");
            Action<int, List<int>> f6 = (x,lis) => Console.WriteLine(x);
            List<int> asd = new List<int>();
            f6(1,asd);
            Predicate<int> f7 = x => x < 0 ;
            Console.WriteLine(f7(4));
            Predicate<double> f8 = x => x > 0;
            Console.WriteLine(f8(4.5));
            Console.ReadKey();
        }
    }
}
