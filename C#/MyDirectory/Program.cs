using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MyDirectory
{
    class Program
    {
        static void DoCommand(string command, string[] words)                                                 // words[0] - command, words[1,2,3...] - dir_name, file name, text etc.
        {
            
            if (string.Compare(command, "md", true) == 0)                                                      // 'md dir_name'
            {
                CmdLine.MakeDir(words);
            }
            else if (string.Compare(command, "rd", true) == 0)                                                 // 'rd dir_name'
            {
                CmdLine.RemoveDir(words);
            }
            else if (command == "C:" || command == "D:" || command == "F:" || command == "G:")                  // 'D:'
            {
                CmdLine.ChangeDir(words);
            }
            else if (string.Compare(command, "cd", true) == 0)                                                  // 'cd D:\Games' or 'cd ..'
            {
                CmdLine.ChangeDir(words);
            }
            else if (string.Compare(command, "dir", true) == 0)                                                 // 'dir' or 'dir D:\My_Projects\C#\Test'
            {
                CmdLine.PrintCurrentDir(words);
            }
            else if (string.Compare(command, "create", true) == 0)                                              // 'create file text'
            {
                CmdLine.CreateTextFile(words);
            }
            else if (string.Compare(command, "type", true) == 0)                                                // 'type D:\My_Projects\C#\Test\Demo.txt' or go to the current dir 'type Demo.txt'
            {
                CmdLine.PrintTextFile(words);
            }
            else if (string.Compare(command, "copy", true) == 0)                                                // 'copy Demo.txt Demo2.txt' or 'copy D:\My_Projects\C#\Test\Demo.txt D:\My_Projects\C#\Test\Demo1.txt'  
            {
                CmdLine.CopyTextFile(words);
            }
            else if (string.Compare(command, "del", true) == 0)                                                 // 'del D:\My_Projects\C#\Test\Demo.txt' or go to the current dir 'del Demo.txt'
            {
                CmdLine.RemoveTextFile(words);
            }
            else if (string.Compare(command, "append", true) == 0)
            {
                CmdLine.AppendTextFile(words);
            }
            else
            {
                Console.WriteLine("\nIncorrect command!!!");
            }
           
        }
        static void Main(string[] args)
        {
            string str;
            string[] words;
            while (true)
            {
                Console.Write($"\n{Directory.GetCurrentDirectory()}>");
                str = Console.ReadLine();
                words = str.Split(" \n\r".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);
                if (words.Length != 0)
                {
                    DoCommand(words[0], words);
                }
            }


        }

    }
    
}
