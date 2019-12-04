using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace _1
{
    public class StuffDict : DictionaryBase
    {
        public void Add(Employee newWorker)
        {
            Dictionary.Add(newWorker.Name, newWorker);
        }

        public void Remove(string workerID)
        {
            Dictionary.Remove(workerID);
        }

        public StuffDict(){}

        public Employee this[string workerID]
        {
            get { return (Employee)Dictionary[workerID]; }
            set { Dictionary[workerID] = value;}
        }

        public Employee GetOldest()
        {
            Employee oldest = new Employee { Name = "Damon", Salary = 10, Birthday = new DateTime(1990, 5, 1) };
            foreach (DictionaryEntry ent in Dictionary)
            {
                Employee emp = ent.Value as Employee;
                if (emp.Birthday.CompareTo(oldest.Birthday) < 0)
                {
                    oldest = emp;
                }
            }
            return oldest; 
        }

    }

    class Program
    {
        static void Main(string[] args)
        {
            StuffDict stuff = new StuffDict();
            stuff.Add(new Employee { Name = "Damon", Salary = 10, Birthday = new DateTime(1990, 5, 1) });
            stuff.Add(new Employee { Name = "Niki", Salary = 15, Birthday = new DateTime(1995, 10, 4) });
            stuff.Add(new Employee { Name = "Ayrton", Salary = 12, Birthday = new DateTime(1992, 6, 23) });
            stuff.Add(new Employee { Name = "Graham", Salary = 13, Birthday = new DateTime(1994, 9, 15) });
            Console.WriteLine(stuff["Niki"]);
            Console.WriteLine(stuff.GetOldest());
            Console.ReadKey();
        }
    }

    public class Employee
    {
        public string Name { get; set; }
        public int Salary { get; set; }
        public DateTime Birthday { get; set; }

        public override string ToString()
        {
            return string.Format("Employee({0} : Salary = {1}; Birthday = {2:D})", Name, Salary, Birthday);
        }
    }
}
