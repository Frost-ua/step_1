using System;
using System.Linq;


namespace lessons
{

    static class StringStr
    {
        public static int CountVovels(this string str, int start, int length)
        {
            const string vovels = "AEIOYUaeioyu";
            int counter = 0;
            for (int i = 0; i < str.Length; ++i)
                for (int j = 0; j < vovels.Length; ++j)
                    if (str[i] == vovels[j])
                        ++counter;
            return counter;
        }
    }




    static class intExt
    {
        public static void printArr(int [] arr)
        {
            for (int i = 0; i < arr.Length; i++)
            {
                Console.WriteLine(arr[i]);
            }
            
            
        }
    }

     



    class Program
    {
        //========================================================   HW_#1   =========================================================

        /*static void Task1()
        {
            Console.WriteLine("\t\t\t---===   Task #1   ===---\nSelect the position of the employee" +
                              "(enter the number):\n1. Economist.\n2. Programmer.\n3. Quality assurance.\n4. Product manager.\n");
            int choice;
            double econ_hr = 21.4, dev_hr = 37.2, qa_hr = 27.0, pm_hr = 35.1, worked_hours = 0;
            choice = int.Parse(Console.ReadLine());
            if (choice < 0 || choice > 4)
            {
                Console.WriteLine("Incorrect value!\n");
                return;
            }
            Console.WriteLine("Enter worked hours:");
            worked_hours = double.Parse(Console.ReadLine());

            switch (choice)
            {
                case 1:
                    Console.WriteLine($"The economist's salary is {worked_hours * econ_hr}$");
                    break;
                case 2:
                    Console.WriteLine($"The programmer's salary is {worked_hours * dev_hr}$");
                    break;
                case 3:
                    Console.WriteLine($"The QA's salary is {worked_hours * qa_hr}$");
                    break;
                case 4:
                    Console.WriteLine($"The PM's salary is {worked_hours * pm_hr}$");
                    break;
            }
        }
        static void Task2()
        {
            Console.WriteLine("\n\t\t\t---===   Task #2   ===---\n\nEnter two positive numbers (A must be less than B) : \n");
            int first_num = 0, second_num = 0;
            first_num = int.Parse(Console.ReadLine());
            second_num = int.Parse(Console.ReadLine());
            if (first_num < 0 || second_num < 0)
            {
                Console.WriteLine("Incorrect value!\n");
                return;
            }
            int tmp = first_num - 1;
            Console.Write("\n");
            for (int i = 0; i < (second_num - tmp); i++)
            {
                for (int j = 0; j < first_num; j++)
                {
                    Console.Write($"{first_num}  ");
                }
                Console.Write("\n");
                first_num++;
            }
        }
        static void Task3()
        {
            Console.WriteLine("\n\t\t\t---===   Task #3   ===---\n\nEnter some positive number : \n");
            long num = long.Parse(Console.ReadLine());
            long res = 0;
            while (num > 0)
            {
                res *= 10;
                res += num % 10;
                num /= 10;
            }
            Console.WriteLine($"\nResult : { res}");
        }
        static void Task4()
        {
            Console.WriteLine("\n\t\t\t---===   Task #4   ===---\n\nEnter characters. Enter \".\" to stop :\n");
            int count_digit = 0, count_letter = 0, count_another_symbol = 0;
            char ch = '0';
            while (ch != '.')
            {
                ch = (char)Console.Read();
                if (char.IsDigit(ch))
                {
                    ++count_digit;
                }
                else if (char.IsLetter(ch))
                {
                    ++count_letter;
                }
                else if (!char.IsLetterOrDigit(ch))
                {
                    ++count_another_symbol;
                }
            }
            Console.WriteLine($"\nDidits : {count_digit}\nLetters : {count_letter}\nAnother symbols : {count_another_symbol}");
        }
        static void Task5()
        {
            string str = "";
            char ch = '0', tmp = '0';
            Console.WriteLine("\t\t\t---===   Task #5   ===---\n\nEnter characters :\n");

            ch = (char)Console.Read();
            ch = (char)Console.Read();
            ch = '0';


                while (ch != 13)
                {
                    ch = (char)Console.Read();
                    if (char.IsUpper(ch))
                    {
                        tmp = char.ToLower(ch);
                        str += tmp;
                    }
                    else if (char.IsLower(ch))
                    {
                        tmp = char.ToUpper(ch);
                        str += tmp;
                    }
                    else
                    {
                        str += ch;
                    }
                }
            
        
            Console.WriteLine($"\n{str}");
        }*/

        //========================================================   HW_#2.1   =========================================================

        /*static void Task6(int[] arr)
        {
            Console.WriteLine("====================   TASK #1   =============================");

            FillRandArr(arr);
            PrintArr(arr, "Array");
            swapTwoElement(arr);
            PrintArr(arr, "Each pair of array elements is swapped");
            firstPosValue(arr);

            Console.WriteLine("Enter a multiple you want to find in the array");
            int value = int.Parse(Console.ReadLine());
            multipleValue(arr, value);
        }
        static void Task7(int[] arr)
        {
            Console.WriteLine("====================   TASK #2   =============================");
            negPos(arr);
            PrintArr(arr, "Left side - negative values, right - positive : ");
        }
        static void Task8(int[] arr)
        {
            Console.WriteLine("====================   TASK #3   =============================");
            Console.WriteLine("Enter a value for searching particular value : ");
            int value_1 = int.Parse(Console.ReadLine());
            Console.WriteLine($"Count of value in the array : {arr.Count(x => (x == value_1))} ");
        }
        static void Task9(int[] arr)
        {
            Console.WriteLine("====================   TASK #4   =============================");

            / *int max_index = Array.FindIndex(arr, x => (x == arr.Max()));
            int min_index = Array.FindIndex(arr, x => (x == arr.Min()));* /

            int max_index = Array.IndexOf(arr, arr.Max());
            int min_index = Array.IndexOf(arr, arr.Min());
            int sum = 0;
            Console.WriteLine("Elements between the biggest and the smallest elements of the array : ");
            for (int i = min_index + 1; i < max_index; ++i)
            {
                Console.Write($"{arr[i]}\t");
                sum += arr[i];
            }
            Console.WriteLine($"\nTheir sum : {sum}");
        }
        static void Task10(int[] arr)
        {
            Console.WriteLine("====================   TASK #5   =============================");
            Console.Write("Not sorted arrays : ");
            int[] price = new int[] { 20, 5, 125, 362, 15 };
            string[] names = new string[] { "Pen", "Apple", "Shoes", "Car", "Bike" };
            PrintArr(price);
            PrintArr(names);
            Console.Write("Sorted arrays by decreasing price: ");
            Array.Sort(price, names);

            Array.Reverse(price);
            Array.Reverse(names);

            PrintArr(price);
            PrintArr(names);
        }*/

        //========================================================   HW_#2.2   =========================================================

        /* static void Task11(ref int[][] jagged, int[] new_row)
         {
             Console.WriteLine("====================   TASK #1   =============================");
             fillJagged(jagged);
             printJagged(jagged, "Jagged :");
             jaggedUp(jagged, 3);
             printJagged(jagged, "After shifting up by 3 position");
             jaggedDown(jagged, 4);
             printJagged(jagged, "After shifting down by 4 position");
             addRow(ref jagged, new_row);
             printJagged(jagged, "After adding a new row to the end of jagged");
             deleteRowByIndex(ref jagged, 3);
             printJagged(jagged, "After deleting row by index");
         }
         static void Task12(ref int[][] jagged)
         {
             Console.WriteLine("====================   TASK #2   =============================");
             int min, max;
             getMinMax(jagged, out min, out max);
             Console.WriteLine($"Min and max values in arrays : \nMin : {min},\nMax : {max}");
         }
         static void Task13()
         {
             Console.WriteLine("====================   TASK #3   =============================");
             int[][][] three_d = createThreeD();
             printThreeD(three_d, "Three dimensional array : ");
             printSumEachJagged(three_d);
         }*/

        //========================================================   HW_#3.1   =========================================================

        static void Task14(string str4)
        {
            Console.WriteLine("\t\t\t---===   Task #1   ===---\n");
            char symbol;
            Console.WriteLine($"{str4}\nEnter letter : ");
            symbol = char.Parse(Console.ReadLine());
            int last_index = findLetter(str4, symbol);
            Console.WriteLine($"\nAfter replacing symbol \"{symbol}\"");
            Console.WriteLine(str4.Replace(symbol, Char.ToUpper(symbol)));

            Console.WriteLine($"\nAfter deleting all symbols after the last symbol \"{symbol}\"");
            Console.WriteLine(str4.Remove(last_index));
        }
        static void Task15(string str4)
        {
            Console.WriteLine("\n\t\t\t---===   Task #2   ===---\n");
            Console.WriteLine($"After deleting all symbols \" -.\"  ");
            Console.WriteLine(deleteSymbols(str4, " -."));
        }
        static void Task16()
        {
            Console.WriteLine("\n\t\t\t---===   Task #3   ===---\n");
            string str5 = "I don’t know whether to delete this or rewrite it.";
            Console.WriteLine(str5);
            letterStatistic(str5);
        }
        static void Task17()
        {
            Console.WriteLine("\n\t\t\t---===   Task #4   ===---");
            string[] keywords = new string[] { "char", "double", "case", "bool", "break", "else", "false", "float", "for", "foreach", "if", "int", "new", "out", "ref", "return", "static", "string", "void", "while" };
            string text_c = @"char again = 'd';
            while (again == 'd')
            {
                double a;
                double b;
                double total;
                char oper;
                Console.WriteLine(""Enter first digit:"");
                a = Convert.ToDouble(Console.ReadLine());
                Console.WriteLine(""Enter action:"");
                oper = Convert.ToChar(Console.ReadLine());
                Console.WriteLine(""Enter second digit:"");
                b = Convert.ToDouble(Console.ReadLine());
                if (oper == '+')
                {
                    total = a + b;
                    Console.WriteLine(""Sum "" + a + "" and "" + b + "" equal "" + total + ""."");
                }
                else if (oper == '-')
                {
                    total = a - b;
                    Console.WriteLine(""Sub "" + a + "" and "" + b + "" equal "" + total + ""."");
                }
                else if (oper == '*')
                {
                    total = a * b;
                    Console.WriteLine(""Mult "" + a + "" and "" + b + "" equal "" + total + ""."");
                }
                else if (oper == '/')
                {
                    total = a / b;
                    Console.WriteLine(""Div "" + a + ""and "" + b + "" equal "" + total + ""."");
                }
                else
                {
                    Console.WriteLine(""Incorrect action."");
                }
                Console.WriteLine(""Do you want to continue? (Y/N)"");
                again = Convert.ToChar(Console.ReadLine());";

            searchKeywords(keywords, text_c);
        }

        //========================================================   HW_#3.2   =========================================================

       


        static void Main(string[] args)
        {

            //===================================   HW_#1   ==========================================

            /* Task1(arr);
               Console.ReadKey();
               Task2(arr);
               Console.ReadKey();
               Task3(arr);
               Console.ReadKey();
               Task4(arr);
               Console.ReadKey();
               Task5(arr);*/

            //===================================   HW_#2.1 --- Arrays  ==========================================

            /* int size = 10;
             int[] arr = createArr(size); // arr(Stack) --------- > Heap[][][][][][]
             Task6(arr);
             Console.ReadKey();
             Task7(arr);
             Console.ReadKey();
             Task8(arr);
             Console.ReadKey();
             Task9(arr);
             Console.ReadKey();
             Task10(arr);*/

            //===================================   HW_#2.2 --- Matrix, Jagged, Three dimensional arrays     ==========================================

            /* const int rows = 4;
             int[][] jagged = new int[rows][];
             int[] new_row = new int[] { 5, 5, 2, 0, 12, 12, 12, 500 };
             Task11(ref jagged, new_row);
             Task12(ref jagged);
             Task13();*/

            //===================================   HW_#3.1 String    ==========================================

            /*string str4 = "The simplest way to get started with HOPR" +
                " is to run our pre-prepared script to install hopr.";
            Task14(str4);
            Console.ReadKey();
            Task15(str4);
            Console.ReadKey();
            Task16();
            Console.ReadKey();*/
            Task17();

            //===================================   HW_#3.2 Classes    ==========================================

            /*Event football = new Event("Fottball", "Rivne, st.\"Avangard\"", 12, new Client("Jordy Frost", "0967217411"), new DateTime(2021, 06, 20));
            Event birthday = new Event("Birthday", "Rivne, \"Kolyba\"", 25, new Client("Julia", "0971544578"), new DateTime(2021, 08, 20));
            Event marriage = new Event("Marriage", "Rivne, \"Aivengo\"", 33, new Client("Julia", "0971544578"), new DateTime(2021, 05, 20));

            EventService events_ls = new EventService();
            events_ls.AddEvent(football);
            events_ls.AddEvent(birthday);
            events_ls.AddEvent(marriage);
            Console.WriteLine(events_ls);

            Console.WriteLine("==============================   Search event by date 20/06/2021 :");
            events_ls.SearchEventByDate(new DateTime(2021, 06, 20));
            Console.WriteLine("==============================   Search event by client Julia :");
            events_ls.SearchEventByClient(new Client("Julia", "0971544578"));
            Console.WriteLine("==============================   Search event by range of date - from 01/02/2021 till 1/07/2021:");
            events_ls.SearchEventByRangeDate(new DateTime(2021, 02, 01), new DateTime(2021, 07, 01));*/


            //===================================   HW_#4. ?????    ==========================================















            //===================================   CW_6_03   ==========================================

            /* int a = 10, b = 15;
             Swap(ref a, ref b);
             Console.WriteLine($"{a}, {b}");
             int s, p;
             SumMult(2, 4, out s, out p);
             Console.WriteLine($"{s}, {p}");

             double x1, x2;
             bool f = Equation(1, 2, 1, out x1, out x2);
             if (f)
             {
                 Console.WriteLine($"{x1}, {x2}");
             }
             else
             {
                 Console.WriteLine("Not found!");
             }
            // 1. Створити одновимірний масив, заповнити вип числами
            // 2. Порахувати кількість елементів із вказаного користувачем діапазону
            // 3. Зробити реверс першої половини  масиву

             int size;
             Console.WriteLine("Input  size : ");

             while (!int.TryParse(Console.ReadLine(), out size))
             {
                 Console.WriteLine("Wrong size! Try again");
             }

             int[] arr = new int[10]; // arr(Stack) --------- > Heap[][][][][][]
             FillRandArr(arr);
             PrintArr(arr, "Array");
             int left = 3, right = 45;
             Console.WriteLine($"Count from left to right = {arr.Count(x => (x >= left && x <= right))} ");
             Array.Reverse(arr, 0, arr.Length/2);
             PrintArr(arr, "Array");

            int rows, cols;

            Console.WriteLine("Rows :\n");
            rows = int.Parse(Console.ReadLine());
            Console.WriteLine("Cols :\n");
            cols = int.Parse(Console.ReadLine());

            int[,] matrix = new int[rows, cols];
            FillMatrix(matrix);
            PrintMatrix(matrix);
            int[] my_arr = getMax(matrix);
            PrintArr(my_arr);*/



            //===================================   CW_13_03 String   ==========================================


            /*string str = "Hello world";
            Console.WriteLine(str.Replace('o', '*'));
            Console.WriteLine(str.ToUpper());
            Console.WriteLine(str.ToLower());           // return new str
            Console.WriteLine(str);                     // old str without changing

            char[] symbols = str.ToCharArray();   //string to char[]

            string str2 = "The simplest way to get       started with HOPR" +
                " is to run our pre-prepared script to install hopr.";
            Console.WriteLine();
            Console.WriteLine($"{str2}");
            findLetter(str2, 'i');     // find symbol "i"
            findOneOf(str2, ".-");     //find symbols "." and "-"
            Console.WriteLine();

            Console.WriteLine($"Delete first 5 symbols in the str :\n{str2.Remove(0, 5)}");
            Console.WriteLine($"\nInsert \" TEST \" after 3-d symbol :\n{str2.Insert(3, " TEST")}");

            //string[] words = str2.Split(new char[] { ' ', '-', '.' });
            //string[] words = str2.Split(' ', '-', '.' );
            string[] words = str2.Split(" ,.-!'".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);
            Console.WriteLine();
            foreach (var item in words)
            {
                Console.WriteLine($"{item}");
            }

            Console.WriteLine($"\nMin word (by alphabet is first) : {words.Min()}");
            Console.WriteLine($"Max word (by alphabet is last) : {words.Max()}");
            Console.WriteLine($"Amount words shorter than 4 symbols : {words.Count(word => word.Length < 4)}");

            Array.Sort(words);
            Console.WriteLine("\n ------------   Sort result a > A   -------------");
            foreach (var item in words)
            {
                Console.WriteLine($"{item}");
            }

            Array.Sort(words, (x, y) => -x.CompareTo(y));
            Console.WriteLine("\n ------------   Sort result - REVERSE   -------------");
            foreach (var item in words)
            {
                Console.WriteLine($"{item}");
            }

            Array.Sort(words, (x, y) => String.CompareOrdinal(x, y));
            Console.WriteLine("\n ------------   Sort result - A > a   -------------");
            foreach (var item in words)
            {
                Console.WriteLine($"{item}");
            }

            //CompareOrdinal - by letters code (Asci table)  A(65) < a(97)
            //CompareTo - Big letter is bigger then small letter A > a

            //Comparison of strings. There aren't     ==   !=   >   <
            //instead we use CompareTo and CompareOrdinal

            string word1 = "APPLE", word2 = "aPPLe";
            Console.WriteLine($"Comparison of \"APPLE\" and \"aPPLe\" (register - true - isn't depend of register) : {string.Compare(word1, word2, true)}");

            int[] arr = { 10, 12, 20, 52, 100 };
            Console.WriteLine($"We join str (symbol \",\") and int[] arr : {String.Join(",", arr)}");
            Console.WriteLine(String.Join("---", words));

            str2.Contains();
            str2.StartsWith();
            str2.EndsWith();
            str2.Trim();


            // Дано речення. Знайти найдовше та найкоротше  слово. Split

            string str3 = "The following code example shows how to sort the values in an Array using the default comparer " +
               "and a custom comparer that reverses the sort order. Note that the result might vary depending on the current CultureInfo." ;
            Console.WriteLine($"{str3}");

            string[] words2 = str3.Split(" ,.-!'".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);
            Console.WriteLine("\n ------Split result-------------");

            foreach (var item in words2)
            {
                Console.WriteLine($"{item}");
            }

           int IndexLong = 0;
           for (int i = 1; i < words.Length; i++)
           {
               if (words[i].Length > words[IndexLong].Length)
               {
                   IndexLong = i;
               }

           }
           Console.WriteLine($"\t{words[IndexLong]}");*/

            //===================================   CW_27_03 String   ==========================================




       
















        }

        




        //========================================================   String   =========================================================

        static void searchKeywords(string[] keywords, string text_c)
        {
            string[] words_text_c = text_c.Split(" (){};:\\/=[],.\r\t\n*-\"!+-'".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);

            /*Console.WriteLine();
            foreach (var item in words_text_c)
            {
                Console.WriteLine($"{item}");
            }*/

            string[] keywords_result = new string[] { "" };
            int[] amount_keywords = new int[] { };

            for (int i = 0, k = 0; i < keywords.Length; i++)
            {
                for (int j = 0; j < words_text_c.Length; j++)
                {
                    if (keywords[i] == words_text_c[j])
                    {
                        if (Array.Find(keywords_result, x => (x == words_text_c[j])) == null)
                        {
                            Array.Resize(ref keywords_result, keywords_result.Length + 1);
                            Array.Resize(ref amount_keywords, amount_keywords.Length + 1);
                            keywords_result[k] = keywords[i];
                            amount_keywords[k] = words_text_c.Count(a => (a == keywords[i]));
                            ++k;
                        }
                    }
                }
            }
            Array.Resize(ref keywords_result, keywords_result.Length - 1);
            Array.Sort(amount_keywords, keywords_result);
            Array.Reverse(amount_keywords);
            Array.Reverse(keywords_result);
            Console.WriteLine();
            for (int i = 0; i < amount_keywords.Length; i++)
            {
                Console.Write($"{keywords_result[i]} \t {amount_keywords[i]}");
                Console.WriteLine();
            }
        }
        static void letterStatistic(string str)
        {
            str = "I don’t know whether to delete this or rewrite it";
            str = deleteSymbols(str, " -.,’\"'`()[]");
            string unic_letters = String.Join("", str.Distinct());
            char[] letters = str.ToCharArray();
            char[] unic_char = unic_letters.ToCharArray();
            Array.Sort(unic_char);
            Console.WriteLine();
           
            int count = 0;
            for (int i = 0; i < unic_char.Length; i++)
            {
                for (int j = 0; j < letters.Length; j++)
                {
                    if (unic_char[i] == letters[j])
                    {
                        ++count;
                    }
                }
                Console.Write($"{unic_char[i]} [{count}]\t");
                for (int k = 0; k < count; k++)
                {
                    Console.Write("* ");
                }
                Console.WriteLine();
                count = 0;
            }
        }
        static string deleteSymbols(string str, string set)
        {
            string tmp = str;
            int index = str.IndexOfAny(set.ToCharArray());
            while (index != -1)
            {
                if (index != -1)
                {
                    str = str.Remove(index, 1);
                }
                index = str.IndexOfAny(set.ToCharArray(), index);
            }
           // Console.WriteLine(str);
            return str;
        }
        static int findLetter(string str, char letter)
        {
            int index = str.IndexOf(letter), tmp = 0;
            while (index != -1) // >=0
            {
                Console.WriteLine($"Letter \"{letter}\" found in index {index}");
                index = str.IndexOf(letter, index + 1);
                if (index != -1)
                {
                    tmp = index;
                }
            }
            return tmp + 1;
            /*else
            {
                Console.WriteLine("The letter isn't found.");
            }*/
        }
        static void findOneOf(string str, string set)
        {
            int index = str.IndexOfAny(set.ToCharArray());
            while (index != -1)
            {
                Console.WriteLine($"Symbol \"{str[index]}\" found in index {index}");
                index = str.IndexOfAny(set.ToCharArray(), index + 1);
               
            }
        }

        //========================================================   Three dimensional array   =========================================================
        static int[][][] createThreeD()
        {
            Random rdn = new Random();

            int[][][] tmp = new int[rdn.Next(3, 6)][][];

            for (int i = 0; i < tmp.Length; i++)
            {
                tmp[i] = new int[rdn.Next(2, 4)][];
                for (int j = 0; j < tmp[i].Length; j++)
                {
                    tmp[i][j] = new int[rdn.Next(2, 4)];
                    for (int k = 0; k < tmp[i][j].Length; k++)
                    {
                        tmp[i][j][k] = rdn.Next(0, 11);
                    }
                }
            }
            return tmp;
        }
        static void printThreeD(int[][][] three_d, string prompt = "")
        {
            Console.WriteLine(prompt);
            for (int i = 0; i < three_d.Length; i++)
            {
                Console.WriteLine($"Array : { i}");
                for (int j = 0; j < three_d[i].Length; j++)
                {
                    for (int k = 0; k < three_d[i][j].Length; k++)
                    {
                        Console.Write($"{three_d[i][j][k], 4}");
                    }
                    Console.WriteLine();
                }
                Console.WriteLine();
            }
            Console.WriteLine();
        }
        static void printSumEachJagged(int[][][] three_d)
        {
            int sum = 0;
            for (int i = 0; i < three_d.Length; i++)
            {
                for (int j = 0; j < three_d[i].Length; j++)
                {
                    for (int k = 0; k < three_d[i][j].Length; k++)
                    {
                        sum += three_d[i][j][k];
                    }
                }
                Console.WriteLine($"Sum of jagged [{i}] : {sum}");
                sum = 0;
            }
        }

        //========================================================   Jugged   =========================================================
        static void fillJagged(int[][] jagged)
        {
            for (int i = 0; i < jagged.Length; i++)
            {
                Random rnd = new Random();
                jagged[i] = new int [rnd.Next(2, 5)];                 // creating each array in the jagged with random length
                for (int j = 0; j < jagged[i].Length; j++)
                {
                    jagged[i][j] = rnd.Next(-10, 10);                // filling each array by random values from -100 till 100
                }
            }
        }
        static void printJagged(int[][] jagged, string prompt = "")
        {
            Console.WriteLine(prompt);
            for (int i = 0; i < jagged.Length; i++)
            {
                for (int j = 0; j < jagged[i].Length; j++)
                {
                    Console.Write($"{jagged[i][j], 4}");
                }
                Console.WriteLine();
            }
            Console.WriteLine();
        }
        static void jaggedUp(int[][] jagged, int shift)
        {
            for (int i = 0; i < shift; i++)
            {
                int[] tmp = jagged[0];
                for (int j = 0; j < jagged.Length - 1; j++)
                {
                    jagged[j] = jagged[j + 1];   
                }
                jagged[jagged.Length - 1] = tmp;
            }
        }
        static void jaggedDown(int[][] jagged, int shift)
        {
            for (int i = 0; i < shift; i++)
            {
                int[] tmp = jagged[jagged.Length - 1];
                for (int j = jagged.Length - 1; j > 0; j--)
                {
                    jagged[j] = jagged[j - 1];
                }
                jagged[0] = tmp;
            }
        }
        static void addRow(ref int [][] jagged, int[] new_row)
        {
            int[][] tmp = new int[jagged.Length + 1][];

            for (int i = 0; i < jagged.Length; i++)
            {
                tmp[i] = jagged[i];
            }
            tmp[jagged.Length] = new_row;
            jagged = tmp;
        }
        static void deleteRowByIndex(ref int[][] jagged, int index)
        {
            int[][] tmp = new int[jagged.Length - 1][];
            bool flag = false;

            for (int i = 0; i < jagged.Length - 1; i++)
            {
                if (i < index)
                {
                    tmp[i] = jagged[i];
                }
                else
                {
                    tmp[i] = jagged[i + 1];
                    flag = true;
                }
            }
            if (flag)
            {
                jagged = tmp;
            }
            else
            {
                Console.WriteLine("Incorrect index!");
            }
        }
        static void getMinMax(int[][] jagged, out int min, out int max)
        {
            min = jagged[0][0];
            max = 0;
            for (int i = 0; i < jagged.Length; i++)
            {
                for (int j = 0; j < jagged[i].Length; j++)
                {
                    if (jagged[i][j] < min)
                    {
                        min = jagged[i][j];
                    }
                    if (jagged[i][j] > max)
                    {
                        max = jagged[i][j];
                    }
                }
            }
        }

        //========================================================   Matrix   =========================================================
        static void FillMatrix(int[,] matrix, int left = 0, int right = 1000)
        {
            Random rnd = new Random();
            for (int i = 0; i < matrix.GetLength(0); ++i)
            {
                for (int j = 0; j < matrix.GetLength(1); ++j)
                {
                    matrix[i, j] = rnd.Next(left, right + 1);

                }
            }
        }
        static void PrintMatrix(int[,] matrix, string prompt = "")
        {
            for (int i = 0; i < matrix.GetLength(0); ++i)
            {
                for (int j = 0; j < matrix.GetLength(1); ++j)
                {
                    Console.Write($"{matrix[i, j]} \t");
                }
                Console.Write("\n");
            }
        }
        // Визначити метод, який отримує прямокутну  матрицю і повертає одновимірний масив з максимальних елементів у кожному рядку
        static int[] getMax(int[,] matrix)
        {
            int[] result = new int[matrix.GetLength(0)];

            for (int i = 0; i < matrix.GetLength(0); ++i)
            {
                int max = matrix[i, 0];
                for (int j = 0; j < matrix.GetLength(1); ++j)
                {
                    if (max < matrix[i, j])
                    {
                        max = matrix[i, j];
                    }
                }
                result[i] = max;
            }
            return result;
        }

        //========================================================   Other   =========================================================
        static void Swap(ref int a, ref int b)
        {
            int tmp = a;
            a = b;
            b = tmp;
        }
        static void SumMult(int a, int b, out int sum, out int prod)
        {
            sum = a + b;
            prod = a * b;
        }
        static bool Equation(double a, double b, double c, out double x1, out double x2)
        {
            double D = b * b - 4 * a * c;
            if (D < 0)
            {
                x1 = 0;
                x2 = 0;
                return false;
            }
            else
            {
                double DD = Math.Sqrt(D);

                x1 = ((-b) - DD) / (2 * a);
                x2 = ((-b) + DD) / (2 * a);
                return true;
            }
        }

        //========================================================   Array   =========================================================
        private static int [] createArr(int size)
        {
            int[] arr = new int[size];
            return arr;
        }
        private static void FillRandArr(int[] arr, int left = -100, int right = 100)           
        {
            Random rnd = new Random();
            for (int i = 0; i < arr.Length; i++)
            {
                arr[i] = rnd.Next(left, right + 1);
            }
        }
        private static void PrintArr<T>(T[]arr, string prompt = "")                 // Print array
        {
            Console.WriteLine(prompt);
            foreach (var el in arr)                                              // тільки для читання елементів масиву(колекції)
            {
                Console.Write($"{el,-7}");
            }
            Console.WriteLine();
        }
        private static void swapTwoElement(int[] arr)
        {
            if (arr.Length % 2 == 0)
            {
                for (int i = 0; i < arr.Length;)
                {
                    mySwap(ref arr[i], ref arr[i + 1]);
                    i += 2;
                }
            }
            else
            {
                for (int i = 0; i < (arr.Length - 1);)
                {
                    mySwap(ref arr[i], ref arr[i + 1]);
                    i += 2;
                }
            }
        }
        private static void mySwap(ref int a, ref int b)
        {
            int tmp = a;
            a = b;
            b = tmp;
        }
        private static void firstPosValue(int[] arr)
        {
            int index = Array.FindIndex(arr, e => { return e > 0; });   
            Console.WriteLine($"The first positive value : {arr[index]}, index : {index}"); 
        }
        private static void numberPairedElement(int [] arr)
        {
            Console.WriteLine($"The number of paired elements of the array : {arr.Count(x => (x % 2 == 0))} ");
        }
        private static void multipleValue(int[] arr, int value)
        {
            int index = Array.FindIndex(arr, e => { return e % value == 0; });
            Console.WriteLine($"The first value of the array is a multiple of the inputted value : {arr[index]}, index : {index}");
        }
        private static void negPos(int[] arr)
        {
            int[] tmp_neg = new int[Array.FindAll(arr, e => { return e < 0; } ).Length];
            tmp_neg = Array.FindAll(arr, e => { return e < 0; });
            int[] tmp_pos = new int[Array.FindAll(arr, e => { return e > 0; }).Length];
            tmp_pos = Array.FindAll(arr, e => { return e > 0; });

            Array.Copy(tmp_neg, arr, tmp_neg.Length);
            Array.Copy(tmp_pos, 0, arr, tmp_neg.Length, tmp_pos.Length);
        }

    }
}
