using System;
using MathOperations;

namespace Calculator
{
    class Program
    {
        static void Main(string[] args)
        {
            int num1 = 10;
            int num2 = 20;
            int sum = MathOperation.Add(num1, num2); // Method from class library    
            Console.WriteLine($"{num1} + {num2} = {sum}");
            Console.ReadLine();
        }
    }
}