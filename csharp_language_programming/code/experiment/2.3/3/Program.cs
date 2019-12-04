using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace _3
{
    class Program
    {
        static void Main(string[] args)
        {
            Random ra = new Random();
            ArrayList al = new ArrayList(20);
            List<int> lst = new List<int>();

            for (int i = 0; i < 20; i++)
            {
                al.Add(ra.Next(0, 10));
            }

            foreach (int i in al)
                Console.Write(string.Format("{0} ", i));
            Console.WriteLine();
                
            while (al.IndexOf(5) >= 0)
                al.Remove(5);
            foreach (int i in al)
                Console.Write(string.Format("{0} ", i));
            Console.WriteLine();

            for (int i = 0; i < 3; i++)
                al.Insert(4,ra.Next(0, 10));
            foreach (int i in al)
                Console.Write(string.Format("{0} ", i));
            Console.WriteLine();

            for (int i = 0; i < 20; i++)
                if (al[i].Equals(1))
                    al[i] = 10;
            foreach (int i in al)
                Console.Write(string.Format("{0} ", i));
            Console.WriteLine();

            Console.ReadKey();
        }
    }
}
