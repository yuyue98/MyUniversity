using System;
using System.Collections;

namespace _3
{
    class person : IComparable
    {
        public string name;
        public double salary;
        public DateTime birthday;
        public virtual int CompareTo(object p)
        {

            person per = (person)p;
            return name.CompareTo(per.name);

        }

        public override string ToString()
        {
            return string.Format($"name = {name}, salary = {salary}, birthday = {birthday}");
        }

    }

    class personcomparer : IComparer
    {
        public int type;

        public personcomparer(int type)
        {
            this.type = type;
        }

        public int Compare(object a, object b)
        {
            person p1 = (person)a;
            person p2 = (person)b;
            if (type == 0)
            {
                return p1.salary.CompareTo(p2.salary);
            }
            else
            {
                return p2.birthday.CompareTo(p1.birthday);
            }

        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            person[] persons = new person[]
            {
                new person { name = "Damon", salary = 10, birthday = new DateTime(1990, 5, 1) },
                new person { name = "Niki", salary = 15 , birthday = new DateTime(1995, 10, 4) },
                new person { name = "Ayrton", salary = 12 , birthday = new DateTime(1992, 6, 23) },
                new person { name = "Graham", salary = 13 , birthday = new DateTime(1994, 9, 15) }
            };

            Console.WriteLine("Order by name:");
            Array.Sort(persons);
            foreach (var p in persons)
                Console.WriteLine(p);
            Console.WriteLine();

            Console.WriteLine("Order by salary:");
            Array.Sort(persons, new personcomparer(0));
            foreach (var p in persons)
                Console.WriteLine(p);
            Console.WriteLine();

            Console.WriteLine("Order by birthday:");
            Array.Sort(persons, new personcomparer(1));
            foreach (var p in persons)
                Console.WriteLine(p);
            Console.WriteLine();

            Console.ReadKey();
        }
    }
}
