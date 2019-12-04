using System;

namespace _2
{
    class Program
    {
        static void Main(string[] args)
        {
            string text = "";
            string str = "";
            string str1 = "";
            int key = 0;
            int a = 0;
            Console.WriteLine("Please input the string:");
            text = Console.ReadLine();
            Console.WriteLine("Please input the key:");
            key = Console.ReadKey().KeyChar;
            foreach(char i in text)
            {
                a = Convert.ToInt32(i) ^ key;
                str += Convert.ToChar(a);
            }
            Console.WriteLine($"\nThe string encryption results is: {str}");
            foreach (char i in str)
            {
                a = Convert.ToInt32(i) ^ key;
                str1 += Convert.ToChar(a);
            }
            Console.WriteLine($"The string decryption results is: {str1}");
            Console.ReadKey();
        }
    }
}
