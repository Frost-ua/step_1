using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace Test_Regex
{
    class Program
    {
        static void Main(string[] args)
        {
            string input = "hello one teo  three one two four";
            string pattern = "one|two";

            Match match = Regex.Match(input, pattern);
            while (match.Success)
            {
                Console.WriteLine($"Found {match.Value} in index {match.Index}");
                match = match.NextMatch();
            }
            Console.WriteLine("\n\n");
            input = "helwlo wolrd  wood awbc";
            Console.WriteLine(input);
            pattern = @"\bw\w*";// w12as w  
            MatchCollection matches = Regex.Matches(input, pattern);
            foreach (Match m in matches)
            {
                Console.WriteLine($"Found {m.Value} in index {m.Index}");

            }

            input = "t_k123@gm.com";// @gmail.com";
            pattern =
            @"\b\w{1,15}\@[a-z]{2,7}\.[a-z]{1,3}";
            Regex regex = new Regex(pattern, RegexOptions.IgnoreCase);

            if (regex.IsMatch(input))
                Console.WriteLine("Success e-mail");
            else
                Console.WriteLine("Not  valid e-mail");

            input = "t_k123@gm.com --  Vania100@ukr.NET--  abc.def@gamil.com ";// @gmail.com";
            Console.WriteLine($"\n\n{input}\n");
            matches = regex.Matches(input);
            foreach (Match m in matches)
            {
                Console.WriteLine($"Found {m.Value} in index {m.Index}");

            }

            string result = Regex.Replace(input, pattern, "", RegexOptions.IgnoreCase);
            Console.WriteLine($"\nAfter delete by  pattern:\n{result}");

            result = Regex.Replace(input, pattern, (Match m) => m.Value.Substring(1), RegexOptions.IgnoreCase);
            Console.WriteLine($"\nAfter delete 1-letter by  pattern:\n{result}");
            Console.WriteLine("\n============================================\n");

            
        }
    }

}
//1. Вилучити з рядка всі цифри Replace
//2. Вивести всі входження(індекси) слів, що містять букву 'a' або 'o' Match MatchNext or Matches