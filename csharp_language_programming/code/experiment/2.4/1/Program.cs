using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace _1
{
    public static class MyExtnsions
    {
        public static bool IsPalindrome(this string str)
        {
            for (int i = 0;i < str.Length/2;i++)
            {
                if (str[i] != str[str.Length - i - 1])
                    return false;
            }
            return true;
        }

        public static string ReverseDigits(this int num)
        {
            string str;
            int num1 = 1;
            str = num.ToString();
            string str1 = new string(str.ToCharArray().Reverse().ToArray()); ;
            return str1;
        }
    }
    
    class Program
    {
        static void Main()
        {
            string s = "abc";
            Console.WriteLine(s + " is " + (s.IsPalindrome() ? "" : "not ") + "palindrome");
            s = "abcba";
            Console.WriteLine(s + " is " + (s.IsPalindrome() ? "" : "not ") + "palindrome");
            int i = 1234;
            Console.WriteLine("Reverse of " + i + " is " + i.ReverseDigits());
            Console.ReadKey();
        }
    }
}
