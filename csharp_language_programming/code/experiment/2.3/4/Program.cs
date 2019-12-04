using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace _4
{
    class Program
    {
        static void Main(string[] args)
        {
            string str = @"using System;
            using System.Collections;
            using System.Collections.Generic;
            using System.Linq;
            using System.Text;

            namespace 实验三_第三题
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
                Console.Write(string.Format(""{0} "", i));
            Console.WriteLine();
                
            while (al.IndexOf(5) >= 0)
                al.Remove(5);
            foreach (int i in al)
                Console.Write(string.Format(""{0} "", i));
            Console.WriteLine();

            for (int i = 0; i < 3; i++)
                al.Insert(4,ra.Next(0, 10));
            foreach (int i in al)
                Console.Write(string.Format(""{0} "", i));
            Console.WriteLine();

            for (int i = 0; i < 20; i++)
                if (al[i].Equals(1))
                    al[i] = 10;
            foreach (int i in al)
                Console.Write(string.Format(""{0} "", i));
            Console.WriteLine();

            Console.ReadKey();
            }
            }
            }
            ";
            string[] keys = { "Console", "static", "foreach", "int", "if" };
            Dictionary<string, int> list = new Dictionary<string, int>();
            foreach (string q in keys)
            {
                int where = 0, count = 0;
                while (str.IndexOf(q, where) >= 0)
                {
                    count++;
                    where = str.IndexOf(q, where) + 1;
                }
                list[q] = count;
            }

            foreach (var q in list)
            {
                Console.WriteLine(string.Format("key = {0}, num = {1}", q.Key, q.Value));
            }
            Console.ReadKey();
        }
    }
}
