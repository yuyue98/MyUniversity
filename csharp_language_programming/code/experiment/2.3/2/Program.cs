using System;

namespace _2
{
    class Program
    {
        static void Main(string[] args)
        {

            Employee emp1 = new Employee("张三");
            Console.WriteLine(emp1);
            Employee emp2 = new Employee("李四", 3, new DateTime(2000, 1, 15));
            Console.WriteLine(emp2);

            Console.ReadKey();
        }
    }

    public class Employee
    {
        public string Name { get; set; }
        public int? Salary { get; set; }
        public DateTime? Birthday { get; set; }

        public Employee(string name)
        {
            Name = name;
        }

        public Employee(string name, int salaty, DateTime birthday)
        {
            Name = name;
            Salary = salaty;
            Birthday = birthday;
        }

        public override string ToString()
        {
            if (Salary != null && Birthday != null)
                return string.Format("Employee({0} : Salary = {1}; Birthday = {2:D})", Name, Salary, Birthday);
            else if (Salary != null && Birthday == null)
                return string.Format("Employee({0} : Salary = {1})", Name, Salary);
            else if (Salary == null && Birthday != null)
                return string.Format("Employee({0} : Birthday = {2:D})", Name, Birthday);
            else
                return string.Format("Employee({0})", Name);
        }
    }
}
