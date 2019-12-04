using System;

namespace _4
{
    class Program
    {
        static void Main(string[] args)
        {
            string str1 = "", str2 = "";
            int len1 = 0, len2 = 0;
            Random rd = new Random();
            int value = rd.Next();
            str1 = Convert.ToString(value);
            len1 = str1.Length;
            foreach(char i in str1)
            {
                switch(i)
                {
                    case '0':
                        str2 += "zeroo";len2 += 4; break;
                    case '1':
                        str2 += "oneo"; len2 += 3; break;
                    case '2':
                        str2 += "twoo"; len2 += 3; break;
                    case '3':
                        str2 += "threeo"; len2 += 5; break;
                    case '4':
                        str2 += "fouro"; len2 += 4; break;
                    case '5':
                        str2 += "fiveo"; len2 += 4; break;
                    case '6':
                        str2 += "sixo"; len2 += 3; break;
                    case '7':
                        str2 += "seveno"; len2 += 5; break;
                    case '8':
                        str2 += "eighto"; len2 += 5; break;
                    case '9':
                        str2 += "nineo"; len2 += 4; break;
                }    
            }
            str2 = str2.Substring(0, str2.Length - 1);
            Console.WriteLine($"The random number is {value}");
            Console.WriteLine($"The string length before replacement is {len1}");
            Console.WriteLine($"The String length aftre replacement is {len2}");
            Console.WriteLine($"The string after the segmentation is {str2}");
            Console.ReadKey();
        }
    }
}
